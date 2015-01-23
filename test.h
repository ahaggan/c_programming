#include "parser.h"
#define PASSED 1
#define NOT_PASSED 0
#define NO_INSTRUCTIONS 3
#define INSTRUCTION_LENGTH 15
//Helper function called to print the results of a test to the txt file.
void print_outcome(FILE *test_pointer, char *test, char *outcome);

int is_true(int(*test_function)(Prog), Prog test_program);
/*
Functions each test a single function in the parser. The function they are testing is the name after test_
*/
int test_check_input(FILE *test_pointer); 
int test_initialise_words_array(FILE *test_pointer);
int test_validate(FILE *test_pointer);
int test_instrctlst(FILE *test_pointer);
int test_instruction(FILE *test_pointer);
int test_fd(FILE *test_pointer);
int test_lt(FILE *test_pointer);
int test_rt(FILE *test_pointer);
int test_varnum(FILE *test_pointer);
int test_make_positive(FILE *test_pointer);
int test_assign_draw(FILE *test_pointer); //NOT DONE!!!

int test_push(FILE *test_pointer);

/*
Functions still to test
test_loop
test_multiply
test_divide
test_subtract
test_add
test_check_stack
test_op
test_pop
test_calculate_current
test_polish
test_set
test_isVar
test_isNumber
test_run
draw_turtle
set_new_xy
*/
