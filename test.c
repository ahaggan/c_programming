#include "parser.h"
#include "test.h"

void test(void){
	FILE *test_pointer;
	test_pointer = fopen("test_results.txt", "w");
    if (test_input(test_pointer) == PASSED){
        fprintf(test_pointer, "\n\n**Check_input function PASSED all tests!**\n\n");
    }
    else{
        fprintf(test_pointer, "\n\n**Check_input function FAILED at least one test, read test_results.txt to see which!**\n\n");
    }      
}


int test_input(FILE *test_pointer){
    FILE *file_pointer;
    int pass_count = 0;
    char **test_array;
    test_array = (char**)malloc(NO_INSTRUCTIONS * sizeof(char*));
    test_array[0] = (char*)malloc(INSTRUCTION_LENGTH * sizeof(char*));
    test_array[0] = "prog_name";
    test_array[1] = "program.txt";
    file_pointer = check_input(2, test_array);
    if(file_pointer == NULL){
        fprintf(test_pointer, "\nInput test 1: Failed");  //Would expect function to return a file pointer, not NULL!
    }
    else{
        fprintf(test_pointer, "\nInput test 1: Passed");
        pass_count += 1;
    }
    if(pass_count != 1){
        return NOT_PASSED;
    }
    else{       //ELSE NOT NEEDED, IS IT BETTER NOT TO HAVE?
        return PASSED;
    }
}
