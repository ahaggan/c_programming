#include "test.h"

void test(void){
	FILE *test_pointer;
	test_pointer = fopen("test_results.txt", "w");
	fprintf(test_pointer, "Below are the test results for each function:\n");
    if (test_input(test_pointer) == PASSED){
        print_outcome(test_pointer, "Check_input", "PASSED");
    }
    else{
        print_outcome(test_pointer, "Check_input", "FAILED");
    }   
    
    if (test_words_array(test_pointer) == PASSED){
        print_outcome(test_pointer, "Test_words_array", "PASSED");
    }
    else{
        print_outcome(test_pointer, "Test_words_array", "FAILED");
    }
    
    if(test_validate(test_pointer) == PASSED){
        print_outcome(test_pointer, "Test_validate", "PASSED");
    }
    else{
        print_outcome(test_pointer, "Test_validate", "FAILED");
    }
    
    if(test_instrctlst(test_pointer) == PASSED){
        print_outcome(test_pointer, "Test_instrctlst", "PASSED");
    }
    else{
        print_outcome(test_pointer, "Test_instrctlst", "FAILED");
    }
    
    if(test_instruction(test_pointer) == PASSED){
        print_outcome(test_pointer, "Test_instruction", "PASSED");
    }
    else{
        print_outcome(test_pointer, "Test_instruction", "FAILED");
    }
    
    if(test_fd(test_pointer) == PASSED){
        print_outcome(test_pointer, "Test_fd", "PASSED");
    }
    else{
        print_outcome(test_pointer, "Test_fd", "FAILED");
    }
    
    if(test_lt(test_pointer) == PASSED){
        print_outcome(test_pointer, "Test_lt", "PASSED");
    }
    else{
        print_outcome(test_pointer, "Test_lt", "FAILED");
    }
    
    if(test_rt(test_pointer) == PASSED){
        print_outcome(test_pointer, "Test_rt", "PASSED");
    }
    else{
        print_outcome(test_pointer, "Test_rt", "FAILED");
    }
}

int test_rt(FILE *test_pointer){
    prog program;
    int pass_count = 0, no_of_tests = 0;
    initialise_words_array(&program);
    //Test should pass, is correct instruction followed by a number - the number is actually checked in a different function tested separately.
    no_of_tests += 1;
    strcpy(program.words[0], "RT");
    strcpy(program.words[1], "10");
    if(rt(&program) == TRUE){
        fprintf(test_pointer, "\nRT test 1: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nRT test 1: Failed");
    }
    //test has a valid number, but incorrect instruction, test will pass if function returns FALSE
    no_of_tests += 1;
    strcpy(program.words[0], "LT");
    strcpy(program.words[1], "10");
    if(rt(&program) == FALSE){
        fprintf(test_pointer, "\nRT test 2: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nRT test 2: Failed");
    }
    //test has a valid instruction, but not a number following so test will pass if function returns false.
    no_of_tests += 1;
    strcpy(program.words[0], "RT");
    strcpy(program.words[1], "ten");
    if(rt(&program) == FALSE){
        fprintf(test_pointer, "\nRT test 3: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nRT test 3: Failed");
    }
    if(pass_count == no_of_tests){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_lt(FILE *test_pointer){
    prog program;
    int pass_count = 0, no_of_tests = 0;
    initialise_words_array(&program);
    //Test should pass, is correct instruction followed by a number - the number is actually checked in a different function tested separately.
    no_of_tests += 1;
    strcpy(program.words[0], "LT");
    strcpy(program.words[1], "10");
    if(lt(&program) == TRUE){
        fprintf(test_pointer, "\nLT test 1: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nLT test 1: Failed");
    }
    //test has a valid number, but incorrect instruction, test will pass if function returns FALSE
    no_of_tests += 1;
    strcpy(program.words[0], "FD");
    strcpy(program.words[1], "10");
    if(lt(&program) == FALSE){
        fprintf(test_pointer, "\nLT test 2: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nLT test 2: Failed");
    }
    //test has a valid instruction, but not a number following so test will pass if function returns false.
    no_of_tests += 1;
    strcpy(program.words[0], "LT");
    strcpy(program.words[1], "ten");
    if(lt(&program) == FALSE){
        fprintf(test_pointer, "\nLT test 3: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nLT test 3: Failed");
    }
    if(pass_count == no_of_tests){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_fd(FILE *test_pointer){
    prog program;
    int pass_count = 0, no_of_tests = 0;
    initialise_words_array(&program);
    //Test should pass, is correct instruction followed by a number - the number is actually checked in a different function tested separately.
    no_of_tests += 1;
    strcpy(program.words[0], "FD");
    strcpy(program.words[1], "10");
    if(fd(&program) == TRUE){
        fprintf(test_pointer, "\nFD test 1: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nFD test 1: Failed");
    }
    //test has a valid number, but incorrect instruction, test will pass if function returns FALSE
    no_of_tests += 1;
    strcpy(program.words[0], "FT");
    strcpy(program.words[1], "10");
    if(fd(&program) == FALSE){
        fprintf(test_pointer, "\nFD test 2: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nFD test 2: Failed");
    }
    //test has a valid instruction, but not a number following so test will pass if function returns false.
    no_of_tests += 1;
    strcpy(program.words[0], "FD");
    strcpy(program.words[1], "ten");
    if(fd(&program) == FALSE){
        fprintf(test_pointer, "\nFD test 3: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nFD test 3: Failed");
    }
    if(pass_count == no_of_tests){
        return PASSED;
    }
    return NOT_PASSED;
}


int test_instruction(FILE *test_pointer){
/*Function will call FD, LT and RT in turn*/
    prog program;
    int pass_count = 0, no_of_tests = 0;
    initialise_words_array(&program);
    //passing FD to function which should be correct, test should pass if TRUE is returned.
    no_of_tests += 1;
    strcpy(program.words[0], "FD");
    strcpy(program.words[1], "10");
    if (instruction(&program) == TRUE){
        fprintf(test_pointer, "\nInstruction test 1: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nInstruction test 1: Failed");
    }
    
    //passing LT to function which should be correct, test should pass if TRUE is returned.
    no_of_tests += 1;
    program.current_word = 0;
    strcpy(program.words[0], "LT");
    strcpy(program.words[1], "10");
    if (instruction(&program) == TRUE){
        fprintf(test_pointer, "\nInstruction test 2: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nInstruction test 2: Failed");
    }
    
    //passing RT to function which should be correct, test should pass if TRUE is returned.
    no_of_tests += 1;
    program.current_word = 0;
    strcpy(program.words[0], "RT");
    strcpy(program.words[1], "10");
    if (instruction(&program) == TRUE){
        fprintf(test_pointer, "\nInstruction test 3: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nInstruction test 3: Failed");
    }
    
    //passing an incorrect word to function which should not be correct, test should pass if FALSE is returned.
    no_of_tests += 1;
    program.current_word = 0;
    strcpy(program.words[0], "something");
    strcpy(program.words[1], "10");
    if (instruction(&program) == FALSE){
        fprintf(test_pointer, "\nInstruction test 4: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nInstrctlst test 4: Failed");
    }
    
    if(pass_count == no_of_tests){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_instrctlst(FILE *test_pointer){
/*Function should return TRUE if the current word is } otherwise, should call the instruction followed by itself.*/
    prog program;
    int pass_count = 0, no_of_tests = 0;
    initialise_words_array(&program);
    
    //passes an incorrect word to instrctlst, this should be passes along and eventually return FALSE.
    no_of_tests += 1;
    strcpy(program.words[0], "Hello");
    if (instrctlst(&program) == FALSE){
        fprintf(test_pointer, "\nInstrctlst test 1: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nInstrctlst test 1: Failed");
    }
    
    //passes a correct program end so should return TRUE
    no_of_tests += 1;
    strcpy(program.words[0], "}");
    if (instrctlst(&program) == TRUE){
        fprintf(test_pointer, "\nInstrctlst test 2: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nInstrctlst test 2: Failed");
    }
    
    if(pass_count == no_of_tests){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_validate(FILE *test_pointer){
/*Tests need to check that the function only works if the program
starts with a {, all other checks are done in other functions.*/ 
    prog program;
    int pass_count = 0, no_of_tests = 0;
    initialise_words_array(&program);
    //Function is given an incorrect starting word, will pass if FALSE is returned
    no_of_tests += 1;
    strcpy(program.words[0], "Hello");
    if (validate(&program) == FALSE){
        fprintf(test_pointer, "\nValidate test 1: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nValidate test 1: Failed");
    }
    
    //function is given the most basic starting program, will pass if TRUE is returned, this is sort of testing the next function as well.
    no_of_tests += 1;
    strcpy(program.words[0], "{");
    strcpy(program.words[1], "}");
    if (validate(&program) == FALSE){
        fprintf(test_pointer, "\nValidate test 2: Failed");
    }
    else{
        fprintf(test_pointer, "\nValidate test 2: Passed");
        pass_count += 1;
    }
    
    if(pass_count == no_of_tests){
        return PASSED;
    }
    return NOT_PASSED;
}

void print_outcome(FILE *test_pointer, char *test, char *outcome){
    fprintf(test_pointer, "\n\n**%s function %s!**\n\n", test, outcome);
}

int test_words_array(FILE *test_pointer){
    prog test_program;
    initialise_words_array(&test_program);
    for(int i = 0; i < PROGRAM_LENGTH; i++){
        if(test_program.words[i][0] != '\0'){
            return NOT_PASSED;
        }
    }
    return PASSED;
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
