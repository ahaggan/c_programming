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
Functions used at the end of the program to free all malloced space
*/
void free_space(Prog *program);

void free_words(words *start);
/*

These functions form the parser

*/

//Checks for an opening brace then calls instrctlst to check the rest
int validate(Prog *program);
//Checks either for an ending brace or a valid instruction
int instrctlst(Prog *program);
//Checks for a valid instruction given in formal grammer, if the program doesn't have a correct ending displays error message
int instruction(Prog *program);

//function assigns a current length value to the program struct the calls assign_draw to add this new coordinate to the draw linked list
int fd(Prog *program);
//functions update the current angle value to the program struct adds for right turn and subtracts for left.
int lt(Prog *program);
int rt(Prog *program);

//Function checks for "SET" instruction, if present determines whether user is setting a letter, the colour or an incorrect program
int set(Prog *program);
//Called if a user wants to set a letter, assigns the value to the program's variable array. Returns FALSE if input in incorrect.
int set_letter(Prog *program);
//Called if user is setting the colour and updates the colour element of the program. Returns FALSE if input in incorrect.
int set_colour(Prog *program);

//Function checks for "DO" instruction followed by a valid letter, it then checks if the loop condition valid then calls a function to perform the loop.
int loop(Prog *program);
//checks a valid "FROM A TO B" condition, A and B could be any allowed number or variable
int loop_condition(Prog *program);
//Checks that the loop goes from a lower to higher value then runs the DO program for the required iterations.
int perform_loop(Prog *program);
//Function returns the integer values of the current variable or number, returns -1 if FALSE to allow for an input of 0 in the loop
int get_parameter(Prog *program);

//Function checks for "IF" instruction followed by a valid letter or colour, it then calls the relevant letter or colour function which will check the condition
int if_condition(Prog *program);
/*
Functions will return TRUE if the grammer is correct, the functions will set an assign flag to off if the if condition is not met. This will mean that the program in the if statement will be read, but wont set of assign any values to be drawn by the interpreter.
*/ 
int if_letter(Prog *program);
int if_colour(Prog *program);

//Function checks for a ';' or calls functions which check for a variable/number or an operation, if all these are false, returns an error message.
int polish(Prog *program);
//Function calls the is_var and is_number functions and will return TRUE if the current word is a variable or a number
int varnum(Prog *program);
//Function returns TRUE if the current word is a variable A-Z
int is_var(Prog *program);
//Function returns TRUE if the current word is a number
int is_number(Prog *program);

//Function checks the stack, to make sure there are enough numbers in it to perform an operation, it then calls each operation function in turn to check for a valid operation.
int op(Prog *program);
//Checks that the current and previous stack pointers are not NULL(i.e. contains at least two values)
int check_stack(Prog *program);
/*
The operation functions check for thier operations sign, if found, they pop two numbers off the stack and perform their specific operation.
*/
int multiply(Prog *program);
int divide(Prog *program);
int subtract(Prog *program);
int add(Prog *program);

//returns the current number on top of the program->polish stack and frees the space that was occupied by it.
double pop(Prog *program);
//pushes the given number to the top of the the given stack
void push(stack *tmp_pointer, double number);


/*

Test function:  - Performs whitebox tests on each function in turn
                - Performs a blackbox test on the parser as a whole, by passing test files to the parse function
*/
void test(void);


/*

Function used to interpret the commands in the file that is being parsed

*/

//Adds the x and y coordinates of the next point to draw to the draw linked list, it calls the make positive, assign colour and set_new_xy
void assign_draw(Prog *program);
//Takes an angle, returns % 360 if above 0, or recursively calls itself with the current angle + 360.
int make_positive(int angle);
//Assigns the corresponding RGB parts of the colour element of the program struct to the current draw struct.
void assign_colour(Prog *program);
//Uses the current_angle and current_length elements of the porgram struct
void set_new_xy(Prog *program);

//Function contained in ashley_sdl.c and uses the draw array to draw the program file on the screen in SDL
void draw_turtle(Prog *program);

