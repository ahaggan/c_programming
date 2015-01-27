/*

Turtle
Created by Ashley Haggan
University of Bristol
2015

This is the header file for my Turtle parser. All function descriptions will be in this file and a function description will accompany each function.  

The parser will parse any file written in the assigned Turtle formal grammer. It will also parse some additional language features. These features are documented in my extention report.

The parser also contains some interpreting functions which assign new draw conditions to a draw linked list. This is used in ashley_sdl.c to draw the required program in SDL.

The Prog struct is quite large, because I took a test driven approach to writing the program I made a decision that most functions should return and integer and take a pointer to the program as an argument. There are a few exception to this.
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>


#define M_PI           3.14159265358979323846  
#define strings_match(A, B) (strcmp(A, B) == 0)
#define WORD_LENGTH 20  //Maximum length of a word used in a turtle file, if an input word is longer than this an error is given
//Return values of most functions, used in both parsing and whitebox testing.
#define TRUE 1
#define FALSE 0
//Dimentions of the SDL window, used in Parser to set the middle of the window as a sarting point
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 700
//Function used to convert degrees to radians
#define DEGTORAD(x) ((x) * M_PI/180)
//Number of letters in the alphabet
#define LETTERS 26
//Number of conditions needed for interpreting a loop
#define CONDITIONS 3
//Maximum length of a COLOUR used in a turtle file, if an input word is longer than this an error is given
#define LONGEST_COLOUR 10
//Number of colours currently parsed and interpreted
#define COLOUR_CHOICE 4

//Struct used to create a linked list containing the user entered program
typedef struct words{
    char current[WORD_LENGTH];
    struct words *next;
    struct words *previous;
}words;

//Struct containing information needed to draw the interpreted program in SDL
//This is used in the parser to create a linked list of coordinates and colours to draw
typedef struct draw{
    double current_x;
    double current_y;
    int red;
    int blue;
    int green;
    struct draw *next;
    struct draw *previous;
}draw;

//Used to create a stack of numbers to perform reverse polish operations
typedef struct polish_list{
    double number;
    struct polish_list *previous;
}polish_list;
//stack pointer for the above stack
typedef struct stack{
    polish_list *pointer;
}stack;

//Conditions used to interpret the users loop operations
enum condition{letter, start, stop};
typedef enum condition condition;

//Contains all the information needed by the various functions within the parser and interpreter
typedef struct Prog{
    draw start_coordinate;
    draw *coordinate;
    words start_word;
    words *current_word;  
    char colour[LONGEST_COLOUR];
    int current_angle;
    double current_length;
    int test;
    int assign;
    FILE *file_pointer;
    double variable[LETTERS];
    double result;
    condition loop[CONDITIONS];
    stack *polish;
}Prog;
/*
The main function in the parser, calls functions to read/store the given file and initialises the program struct
This function chooses whether the user has asked for a test or has entered a text file to parse.
If the user has entered their own file, if it is parsed correctly the main function will call the draw_turtle funnction and display their program in SDL.
*/

/*
Functions called outside the parser
*/
//This function is called if a user has intered a file to be parsed. It scans the file into the linked list and then sends the linked list to the parser to parse. Returns TRUE if parsed correctly.
int parse(Prog *program);
//Called by the main function to check the users input to the command line, returns NULL or the file pointer to the users file
FILE* check_input(Prog *program, int argc, char **argv);
//Sets all the initial values to the program struct, such as the start of both linked lists and the first draw coordinates
void initialise_program(Prog *program);

/*
These functions are called recursively to form the parser
*/
int validate(Prog *program);
int loop(Prog *program);

int polish(Prog *program);
int get_parameter(Prog *program);
int loop_condition(Prog *program);
int perform_loop(Prog *program);
int varnum(Prog *program);
int if_condition(Prog *program);
int instrctlst(Prog *program);
int instruction(Prog *program);
int fd(Prog *program);
int lt(Prog *program);
int rt(Prog *program);

/*
Functions used in parsing, they are called by other functions, but are not recursive
*/
int multiply(Prog *program);
int divide(Prog *program);
int subtract(Prog *program);
int add(Prog *program);
int check_stack(Prog *program);
double pop(stack *pointer);
void push(stack *tmp_pointer, double number);
int set(Prog *program);
int set_letter(Prog *program);
int set_colour(Prog *program);
int is_var(Prog *program);
int is_number(Prog *program);

int if_letter(Prog *program);
int if_colour(Prog *program);
int op(Prog *program);
int make_positive(int angle);


/*
Test function
*/

void test(void);

/*
Function used to interpret the commands in the file that is being parsed
*/
//Adds the x and y coordinates of the next point to draw to into a draw array.
void assign_draw(Prog *program);
void assign_colour(Prog *program);
void set_new_xy(Prog *program);
//Function contained in ashley_sdl.c and uses the draw array to draw the program file on the screen in SDL
void draw_turtle(Prog *program);

