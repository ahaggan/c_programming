#include "parser.h"
#define PASSED 1
#define NOT_PASSED 0
#define NO_INSTRUCTIONS 3
#define INSTRUCTION_LENGTH 15

int test_input(FILE *test_pointer);
void print_outcome(FILE *test_pointer, char *test, char *outcome);
int test_words_array(FILE *test_pointer);
int test_validate(FILE *test_pointer);
int test_instrctlst(FILE *test_pointer);
int test_instruction(FILE *test_pointer);
int test_fd(FILE *test_pointer);
int test_lt(FILE *test_pointer);
int test_rt(FILE *test_pointer);
int test_make_positive(FILE *test_pointer);
int test_assign_draw(FILE *test_pointer);
int test_varnum(FILE *test_pointer);
int test_push(FILE *test_pointer);
