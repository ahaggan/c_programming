#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include "SDL2/SDL.h"

#define M_PI           3.14159265358979323846  /* pi - Should I need to define this?? */
#define strings_match(A, B) (strcmp(A, B) == 0)
#define PROGRAM_LENGTH 100
#define WORD_LENGTH 20
#define TRUE 1
#define FALSE 0
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define DEGTORAD(x) ((x) * M_PI/180)


typedef struct prog{
    char words[PROGRAM_LENGTH][WORD_LENGTH];
    double draw[PROGRAM_LENGTH];
    int draw_pointer;
    int current_word;  
    double current_x;
    double current_y;
    int current_angle;
    double current_length;
    int test;
    FILE *file_pointer;
}prog;

int run(prog *program);
int make_positive(int angle);
void test(void);
FILE* check_input(prog *program, int argc, char **argv);
void initialise_words_array(prog *program);
int validate(prog *program);
int instrctlst(prog *program);
int instruction(prog *program);
int fd(prog *program);
int lt(prog *program);
int rt(prog *program);
int varnum(prog *program);
void draw_turtle(prog *program);
//Adds the x and y coordinates of the next point to draw to into a draw array.
void assign_draw(prog *program);
void set_new_xy(prog *program);
