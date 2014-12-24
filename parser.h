#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "SDL2/SDL.h"

#define strings_match(A, B) (strcmp(A, B) == 0)
#define PROGRAM_LENGTH 100
#define WORD_LENGTH 20
#define TRUE 1
#define FALSE 0
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

typedef struct prog{
    char words[PROGRAM_LENGTH][WORD_LENGTH];
    int draw[PROGRAM_LENGTH];
    int draw_pointer;
    int current_word;  
    int current_x;
    int current_y;
    int current_angle;
    int current_length;
}prog;

int make_positive(int angle);
void test(void);
FILE* check_input(int argc, char **argv);
void initialise_words_array(prog *program);
int validate(prog *program);
int instrctlst(prog *program);
int instruction(prog *program);
int fd(prog *program);
int lt(prog *program);
int rt(prog *program);
int varnum(prog *program);
void draw_turtle(prog *program);
void assign_draw(prog *program);
void set_new_xy(prog *program);
