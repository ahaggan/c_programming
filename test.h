/*
Testing module tests each function in the Parser. Due to the recursive nature of the Parser some of the functions need to be given a fuller test program due to the number of functions they may have to pass to give a return value. In these case I give the smallest function possible that is able to sufficiently test the current function.
*/

#include "parser.h"
#define PASSED 1
#define NOT_PASSED 0
#define NO_INSTRUCTIONS 3
#define INSTRUCTION_LENGTH 15
#define MAX_FUNCTION_LENGTH 15
//Contains information needed for the tests
typedef struct Test{
    Prog *program;
    int current;
    int condition;
    char name[MAX_FUNCTION_LENGTH];
    FILE *results;
    int (*function)(Prog*);
    int pass;
}Test;
/*
Helper functions used by test function in order to test and print the results for each function in the parser
*/
void print_outcome(FILE *test_pointer, char *test, char *outcome);
void tester(Test *test);
void initialise_test(Test *test, Prog *program);
/*
Each function is a test for the function that is explicit in the function name
*/

/*
Old tests!
*/
int test_check_input(FILE *test_pointer);
int test_words_array(FILE *test_pointer);
int test_validate(FILE *test_pointer);
int test_instrctlst(FILE *test_pointer);
int test_instruction(FILE *test_pointer);

int test_fd(FILE *test_pointer);
int test_lt(FILE *test_pointer);
int test_rt(FILE *test_pointer);
int test_make_positive(FILE *test_pointer);
int test_assign_draw(FILE *test_pointer);


int test_push(FILE *test_pointer); //Not complete

/*
New tests!
*/
int test_varnum(Test *test);
int test_loop(Test *test);
int test_loop_condition(Test *test);
int test_perform_loop(Test *test);
int test_get_parameter(Test *test);
int test_is_number(Test *test);
int test_is_var(Test *test);
int test_check_stack(Test *test);
int test_add(Test *test);
int test_subtract(Test *test);
int test_multiply(Test *test);
int test_divide(Test *test);
int test_op(Test *test);
int test_pop(Test *test);
int test_polish(Test *test);
int test_set(Test *test);
int test_set_new_xy(Test *test); //Test doesn't work

/*
New tests needed:

int test_run
int test_draw_turtle

int test_assign_draw

*/


