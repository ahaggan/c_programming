#include "parser.h"
#include "test.h"

void test(void){
	FILE *test_pointer;
	test_pointer = fopen("test_results.txt", "w");
    if (test_input(test_pointer) == PASSED){
        fprintf(test_pointer, "\n\n**Check_input function PASSED all tests!**\n\n");
    }
    else{
        fprintf(test_pointer, "\n\n**Check_input function FAILED at least one test!**\n\n");
    }      
}


int test_input(FILE *test_pointer){
    FILE *file_pointer;
    int pass_count = 0, no_of_tests = 0;
    int argc = 2; //argc values that would be read from command line, will be changed to test for different inputs
    char **test_array;
    test_array = (char**)malloc(NO_INSTRUCTIONS * sizeof(char*));
    test_array[0] = (char*)malloc(INSTRUCTION_LENGTH * sizeof(char*));
    //Test for correct number of inputs and file name, test will pass if function doesn't return NULL
    no_of_tests += 1;
    test_array[0] = "prog_name";
    test_array[1] = "program.txt";
    file_pointer = check_input(argc, test_array);
    if(file_pointer == NULL){
        fprintf(test_pointer, "\nInput test 1: Failed");  
    }
    else{
        fprintf(test_pointer, "\nInput test 1: Passed");
        pass_count += 1;
    }
    //Test for incorrect file name, test will pass if NULL is returned
    no_of_tests += 1;
    test_array[0] = "prog_name";
    test_array[1] = "progrm.txt"; //Incorrect file name
    file_pointer = check_input(argc, test_array);
    if(file_pointer == NULL){
        fprintf(test_pointer, "\nInput test 2: Passed");  
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nInput test 2: Failed");
        //pass_count += 1;
    }
    //Supply's an incorrect 3rd input, test should pass if check_input returns NULL
    no_of_tests += 1;
    argc = 3;
    test_array[0] = "prog_name";
    test_array[1] = "program.txt";
    test_array[2] = "hello"; 
    file_pointer = check_input(argc, test_array);
    if(file_pointer == NULL){
        fprintf(test_pointer, "\nInput test 3: Passed");  
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nInput test 3: Failed");
        //pass_count += 1;
    }
    
    //Test for 3 correct inputs, test will fail if function returns NULL
    no_of_tests += 1;
    argc = 3;
    test_array[0] = "prog_name";
    test_array[1] = "program.txt";
    test_array[2] = "test"; 
    file_pointer = check_input(argc, test_array);
    if(file_pointer == NULL){
        fprintf(test_pointer, "\nInput test 4: Failed");  
        //pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nInput test 4: Passed");
        pass_count += 1;
    }
    //Tests for too few inputs, will pass if check_input returns NULL
    no_of_tests += 1;
    argc = 1;
    test_array[0] = "prog_name";
    file_pointer = check_input(argc, test_array);
    if(file_pointer == NULL){
        fprintf(test_pointer, "\nInput test 5: Passed");  
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nInput test 5: Failed");
        //pass_count += 1;
    }
    
    if(pass_count != no_of_tests){
        return NOT_PASSED;
    }
    else{       //ELSE NOT NEEDED, IS IT BETTER NOT TO HAVE?
        return PASSED;
    }
}
