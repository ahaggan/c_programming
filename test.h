/*
Testing module tests each function in the Parser. Due to the recursive nature of the Parser some of the functions need to be given a fuller test program due to the number of functions they may have to pass to give a return value. In these case I give the smallest function possible that is able to sufficiently test the current function.

The assign_draw and draw_turtle have been tesed through the visual realisation of programs entered. Functions will always be given correct input due to the nature of the parser and therefore do not have individual white box tests. 
*/

#include "parser.h"
#define PASSED 1
#define NOT_PASSED 0
#define NO_INSTRUCTIONS 3
#define INSTRUCTION_LENGTH 15
#define MAX_FUNCTION_LENGTH 15
#define FUNCTION_NAME 30 //Max length of a function name
#define NO_TESTS 34
//Contains information needed for the tests
typedef struct Test{
    Prog *program;
    char test_program[MAX_FUNCTION_LENGTH][INSTRUCTION_LENGTH];
    int current;
    int condition;
    char name[MAX_FUNCTION_LENGTH];
    FILE *results;
    int (*function)(Prog*);
    int pass;
    int no_passed;
    int no_failed;
}Test;
/*
Helper functions used by test function in order to test and print the results for each function in the parser
*/
//Used in a for loop to run and print each test in tern printing the results to test_results.txt
void run_test(int(*test_function)(Test*), Test *test, char *test_name);
//Used by other functions to print the outcom of the tests to file
void print_outcome(FILE *test_pointer, char *test, char *outcome);
//Is passed the function currently being tested and a pass condition, prints pass of fail to the file
void tester(Test *test);
//Initialises the test struct, setting and assigning the requirted values before the start of each function test
void initialise_test(Test *test, Prog *program);
//Converts the test_program array into a linked list for the parser to read
void write_program(Test *test);
/*
Each function is a test for the function that is explicit in the function name, each test will pass all possible inputs correct of not to the current function and print the results to the test->results file
*/

int test_check_input(Test *test);
int test_initialise_program(Test *test); 
int test_make_positive(Test *test);
int test_assign_draw(Test *test);
int test_push(Test *test); //Not complete
int test_parse(Test *test);
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
int test_set_new_xy(Test *test); 
int test_fd(Test *test);
int test_lt(Test *test);
int test_rt(Test *test);
int test_instrctlst(Test *test);
int test_instruction(Test *test);
int test_validate(Test *test);
int test_if_condition(Test *test);
int test_if_letter(Test *test);
int test_if_colour(Test *test);
int test_assign_colour(Test *test);
int test_set_colour(Test *test);
int test_set_letter(Test *test);


