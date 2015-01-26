#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include "SDL2/SDL.h"

#define M_PI           3.14159265358979323846  
#define strings_match(A, B) (strcmp(A, B) == 0)
#define PROGRAM_LENGTH 100000
#define WORD_LENGTH 20
#define TRUE 1
#define FALSE 0
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 700
#define DEGTORAD(x) ((x) * M_PI/180)
#define LETTERS 26
#define CONDITIONS 3

typedef struct words{
    char current[WORD_LENGTH];
    struct words *next;
    struct words *previous;
}words;

typedef struct draw{
    double current_x;
    double current_y;
    struct draw *next;
    struct draw *previous;
}draw;

typedef struct polish_list{
    double number;
    struct polish_list *previous;
}polish_list;

typedef struct stack{
    polish_list *pointer;
}stack;

enum condition{letter, start, stop};
typedef enum condition condition;

typedef struct Prog{
    draw start_coordinate;
    draw *coordinate;
    double draw[PROGRAM_LENGTH];
    int draw_pointer;
    words start_word;
    words *current_word;  
    double current_x;
    double current_y;
    int current_angle;
    double current_length;
    int test;
    FILE *file_pointer;
    double variable[LETTERS];
    double result;
    condition loop[CONDITIONS];
    stack *polish;
}Prog;

int loop(Prog *program);
int multiply(Prog *program);
int divide(Prog *program);
int subtract(Prog *program);
int add(Prog *program);

int check_stack(Prog *program);
int op(Prog *program);
double pop(stack *pointer);
void push(stack *tmp_pointer, double number);
//int calculate_current(Prog *program);

int polish(Prog *program);
int set(Prog *program);
int is_var(Prog *program);
int is_number(Prog *program);
int parse(Prog *program);

int make_positive(int angle);
void test(void);
FILE* check_input(Prog *program, int argc, char **argv);
void initialise_words_array(Prog *program);
int validate(Prog *program);

int instrctlst(Prog *program);
int instruction(Prog *program);
int fd(Prog *program);
int lt(Prog *program);
int rt(Prog *program);

int get_parameter(Prog *program);
int loop_condition(Prog *program);
int perform_loop(Prog *program);
int varnum(Prog *program);
/*
The functions below are used to interpret the commands in the file that is being parsed
*/
//Adds the x and y coordinates of the next point to draw to into a draw array.
void assign_draw(Prog *program);
void set_new_xy(Prog *program);
//Function contained in ashley_sdl.c and uses the draw array to draw the program file on the screen in SDL
void draw_turtle(Prog *program);

