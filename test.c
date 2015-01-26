#include "test.h"

void test(void){
	//FILE *test_pointer;
	Test test;
	//Prog program;
	//test.program = &program;
	//test_pointer = fopen("test_results.txt", "w");
	test.results = fopen("test_results.txt", "w");
	fprintf(test.results, "Below are the test results for each function:\n");
    if (test_check_input(&test) == PASSED){
        print_outcome(test.results, "Check_input", "PASSED");
    }
    else{
        print_outcome(test.results, "Check_input", "FAILED");
    }   
    /*
    if (test_words_array(test.results) == PASSED){
        print_outcome(test.results, "Test_words_array", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_words_array", "FAILED");
    }
    */
    if(test_validate(&test) == PASSED){
        print_outcome(test.results, "Test_validate", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_validate", "FAILED");
    }
    
    if(test_instrctlst(&test) == PASSED){
        print_outcome(test.results, "Test_instrctlst", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_instrctlst", "FAILED");
    }
    
    if(test_instruction(&test) == PASSED){
        print_outcome(test.results, "Test_instruction", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_instruction", "FAILED");
    }
    
    if(test_fd(&test) == PASSED){
        print_outcome(test.results, "Test_fd", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_fd", "FAILED");
    }
    
    if(test_lt(&test) == PASSED){
        print_outcome(test.results, "Test_lt", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_lt", "FAILED");
    }
    
    if(test_rt(&test) == PASSED){
        print_outcome(test.results, "Test_rt", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_rt", "FAILED");
    }
    
    if(test_make_positive(test.results) == PASSED){
        print_outcome(test.results, "Test_make_positive", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_make_positive", "FAILED");
    }
    /*
    if(test_assign_draw(&test) == PASSED){ //Not sure how to test this?
        print_outcome(test.results, "Test_assign_draw", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_assign_draw", "FAILED");
    }
    
    */
    if(test_varnum(&test) == PASSED){
        print_outcome(test.results, "Test_varnum", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_varnum", "FAILED");
    }
    
    if(test_push(test.results) == PASSED){
        print_outcome(test.results, "Test_push", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_push", "FAILED");
    }
    
    if(test_get_parameter(&test) == PASSED){
        print_outcome(test.results, "Test_get_parameter", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_get_parameter", "FAILED");
    }
    
    if(test_is_number(&test) == PASSED){
        print_outcome(test.results, "Test_is_number", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_is_number", "FAILED");
    }
    
    if(test_is_var(&test) == PASSED){
        print_outcome(test.results, "Test_is_var", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_is_var", "FAILED");
    }
    
    if(test_check_stack(&test) == PASSED){
        print_outcome(test.results, "Test_check_stack", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_check_stack", "FAILED");
    }
    
    if(test_add(&test) == PASSED){
        print_outcome(test.results, "Test_add", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_add", "FAILED");
    }
    
    if(test_subtract(&test) == PASSED){
        print_outcome(test.results, "Test_subtract", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_subtract", "FAILED");
    }
    
    if(test_divide(&test) == PASSED){
        print_outcome(test.results, "Test_divide", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_divide", "FAILED");
    }
    
    if(test_multiply(&test) == PASSED){
        print_outcome(test.results, "Test_multiply", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_multiply", "FAILED");
    }
    
    if(test_op(&test) == PASSED){
        print_outcome(test.results, "Test_op", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_op", "FAILED");
    }
    
    if(test_pop(&test) == PASSED){
        print_outcome(test.results, "Test_pop", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_pop", "FAILED");
    }
    
    if(test_polish(&test) == PASSED){
        print_outcome(test.results, "Test_polish", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_polish", "FAILED");
    }
    
    if(test_set(&test) == PASSED){
        print_outcome(test.results, "Test_set", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_set", "FAILED");
    }
    
    if(test_loop_condition(&test) == PASSED){
        print_outcome(test.results, "Test_loop_condition", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_loop_condition", "FAILED");
    }
    
    if(test_perform_loop(&test) == PASSED){
        print_outcome(test.results, "Test_perform_loop", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_perform_loop", "FAILED");
    }
    
    if(test_loop(&test) == PASSED){
        print_outcome(test.results, "Test_loop", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_loop", "FAILED");
    }
    
    if(test_set_new_xy(&test) == PASSED){
        print_outcome(test.results, "Test_set_new_xy", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_set_new_xy", "FAILED");
    }
   
}

void write_program(Test *test){
    int i = 0;
    words *new_word;
    words *previous_word;
    test->program->current_word = &test->program->start_word;
    while(i < MAX_FUNCTION_LENGTH){
        strcpy(test->program->current_word->current, test->test_program[i]);
        new_word = (words*)malloc(sizeof(words));
        previous_word = test->program->current_word;
        test->program->current_word->next = new_word;
        test->program->current_word = new_word;
        test->program->current_word->previous = previous_word;
        test->test_program[i][0] = '\0';
        i++;
    }
    test->program->current_word = &test->program->start_word;  
}

void print_outcome(FILE *test_pointer, char *test, char *outcome){
    fprintf(test_pointer, "\n\n**%s function %s!**\n\n", test, outcome);
}

void initialise_test(Test *test, Prog *program){
    test->program = program;
    initialise_words_array(test->program);
    test->current = 0;
    test->pass = 0;
}

void tester(Test *test){
    test->current += 1;
    if (test->function(test->program) == test->condition){
        fprintf(test->results, "\n%s test %d: Passed", test->name, test->current);
        test->pass += 1;
        return;
    }
    fprintf(test->results, "\n%s test %d: Failed", test->name, test->current);
    
}

int test_push(FILE *test_pointer){
    Prog program;
    int pass_count = 0, no_of_tests = 0;
    initialise_words_array(&program);
    //Test should pass, is correct instruction followed by a number - the number is actually checked in a different function tested separately.
    no_of_tests += 1;
    push(program.polish, 10);
    push(program.polish, 20);
    if(pop(program.polish) == 20){
        if(pop(program.polish) == 10){
            pass_count += 1;
            fprintf(test_pointer, "\nPush test 1: Passed");
        }
        else{
            fprintf(test_pointer, "\nPush test 1: Failed");
        }
    }
    else{
        fprintf(test_pointer, "\nPush test 1: Failed");
    }
    
    
    
    if(pass_count == no_of_tests){
        return PASSED;
    }
    return NOT_PASSED; 
    
}


int test_set_new_xy(Test *test){
    Prog program;
    //int startx, starty, endx, endy;
    initialise_test(test, &program);
    strcpy(test->name, "set_new_xy");
    
    //Tests an angle less than 90
    test->current += 1;
    test->program->current_x = 100;
    test->program->current_y = 100;
    test->program->current_length = 100;
    test->program->current_angle = 30;
    set_new_xy(test->program);
    printf("\nCURRENT X: %d\n", (int)test->program->current_x);
    if((int)(test->program->current_x) == 150){
        test->program->current_y = 100;
        test->program->current_angle = 60;
        set_new_xy(test->program);
        printf("\nCURRENT Y: %lf\n", test->program->current_y);
        printf("\nCURRENT Y: %d\n", (int)test->program->current_y);
        if((int)(test->program->current_y) == 50){ 
            printf("\nCURRENT Y: %lf\n", test->program->current_y);
            test->pass += 1;
            fprintf(test->results, "\nset_new_xy test 1: Passed");
        }
    }
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_loop(Test *test){
    Prog program;
    
    initialise_test(test, &program);
    strcpy(test->name, "loop");
    test->function = &loop;
    
    //Program will return TRUE, basic loop
    
    
    strcpy(test->test_program[0], "DO");
    strcpy(test->test_program[1], "R");
    strcpy(test->test_program[2], "FROM");
    strcpy(test->test_program[3], "1");
    strcpy(test->test_program[4], "TO");
    strcpy(test->test_program[5], "2");
    strcpy(test->test_program[6], "{");
    strcpy(test->test_program[7], "}");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    
    //Program will return FALSE, no variable defined
    
    
    strcpy(test->test_program[1], "DO");
    strcpy(test->test_program[2], "FROM");
    strcpy(test->test_program[3], "1");
    strcpy(test->test_program[4], "TO");
    strcpy(test->test_program[5], "2");
    strcpy(test->test_program[6], "{");
    strcpy(test->test_program[7], "}");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //Program will return FALSE, no opening bracket
    
    
    strcpy(test->test_program[1], "DO");
    strcpy(test->test_program[2], "A");
    strcpy(test->test_program[3], "FROM");
    strcpy(test->test_program[4], "1");
    strcpy(test->test_program[5], "TO");
    strcpy(test->test_program[6], "2");
    strcpy(test->test_program[7], "}");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_perform_loop(Test *test){
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "perform_loop");
    test->function = &perform_loop;
    
    //Program will return TRUE, basic loop
    
    printf("\nBEFORE THE FIRST TEST.\n");
    test->program->loop[letter] = 'A';
    test->program->loop[start] = 1;
    test->program->loop[stop] = 2;
    printf("\nBEFORE THE FIRST STRCPY.\n");
    strcpy(test->test_program[0], "{");//Needed for the function but not read
    strcpy(test->test_program[1], "}");
    printf("\nBEFORE THE WRITE_PROGRAM.\n");
    write_program(test);
    test->condition = TRUE;
    printf("\nBEFORE THE TESTER.\n");
    tester(test);
    printf("\nAFTER THE TESTER.\n");
    
    //Program will return FALSE, start > end
   
    
    test->program->loop[letter] = 'A';
    test->program->loop[start] = 2;
    test->program->loop[stop] = 1;
    strcpy(test->test_program[0], "Arb");
    strcpy(test->test_program[1], "}");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //Program will return FALSE, basic loop with incomplete contents
    
    
    test->program->loop[letter] = 'A';
    test->program->loop[start] = 1;
    test->program->loop[stop] = 2;
    strcpy(test->test_program[0], "{");
    strcpy(test->test_program[1], "FD");
    strcpy(test->test_program[2], "10");
    strcpy(test->test_program[3], "RT");
    strcpy(test->test_program[4], "50");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_loop_condition(Test *test){
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "loop_condition");
    test->function = &loop_condition;
    
    
    //Program will return TRUE, basic loop condition just numbers
    
    
    strcpy(test->test_program[0], "FROM");
    strcpy(test->test_program[1], "1");
    strcpy(test->test_program[2], "TO");
    strcpy(test->test_program[3], "4");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    
    //Program will return TRUE, basic loop condition with a letter
    
    
    strcpy(test->test_program[0], "FROM");
    strcpy(test->test_program[1], "A");
    strcpy(test->test_program[2], "TO");
    strcpy(test->test_program[3], "4");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    
    //Program will return TRUE, basic loop condition start = end
   
    
    strcpy(test->test_program[0], "FROM");
    strcpy(test->test_program[1], "A");
    strcpy(test->test_program[2], "TO");
    strcpy(test->test_program[3], "A");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    
    //Program will return FALSE, basic loop condition without FROM
    
    
    strcpy(test->test_program[0], "5");
    strcpy(test->test_program[1], "TO");
    strcpy(test->test_program[2], "1");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //Program will return FALSE, basic loop condition without a second condition
    
    
    strcpy(test->test_program[0], "FROM");
    strcpy(test->test_program[1], "5");
    strcpy(test->test_program[2], "TO");
    strcpy(test->test_program[3], "");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_set(Test *test){
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "set");
    test->function = &set;
    
    
    //Program will return FALSE, basic expression doesn't end with a ;
    
    
    strcpy(test->test_program[0], "SET");
    strcpy(test->test_program[1], "A");
    strcpy(test->test_program[2], ":=");
    strcpy(test->test_program[3], "7");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //Program will return FALSE, basic expression doesn't contain an equals sign
    
    
    strcpy(test->test_program[0], "SET");
    strcpy(test->test_program[1], "A");
    strcpy(test->test_program[2], "to");
    strcpy(test->test_program[3], "7");
    strcpy(test->test_program[4], ";");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //Program will return FALSE, basic expression doesn't start SET a variable
    
    
    strcpy(test->test_program[0], "SET");
    strcpy(test->test_program[1], "5");
    strcpy(test->test_program[2], ":=");
    strcpy(test->test_program[3], "7");
    strcpy(test->test_program[4], ";");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //Program will return FALSE, basic expression doesn't start with SET
   
    
    strcpy(test->test_program[0], "N");
    strcpy(test->test_program[1], ":=");
    strcpy(test->test_program[2], "5");
    strcpy(test->test_program[3], ";");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //Program will return FALSE, basic expression doesn't start with SET
    
    
    strcpy(test->test_program[0], "N");
    strcpy(test->test_program[1], ":=");
    strcpy(test->test_program[2], "5");
    strcpy(test->test_program[3], ";");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    //Program will return FALSE, basic SET expression without a value to set to
    
    
    strcpy(test->test_program[0], "SET");
    strcpy(test->test_program[1], "G");
    strcpy(test->test_program[2], ":=");
    strcpy(test->test_program[3], ";");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //Program will return TRUE, basic SET expression passed
    
    
    strcpy(test->test_program[0], "SET");
    strcpy(test->test_program[1], "G");
    strcpy(test->test_program[2], ":=");
    strcpy(test->test_program[3], "5");
    strcpy(test->test_program[4], ";");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
    
}

int test_polish(Test *test){
    
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "polish");
    test->function = &polish;
    
    //Program will return TRUE, basic end of Polish expression passed
    
    
    strcpy(test->test_program[0], ";");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    
    //Program will return TRUE, basic number and end
    
    
    strcpy(test->test_program[0], "7");
    strcpy(test->test_program[1], ";");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    
    //Program will return TRUE, basic variable and end
    
    
    strcpy(test->test_program[0], "V");
    strcpy(test->test_program[1], ";");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    
    //Program will return TRUE, basic operation and end
    
    
    push(test->program->polish, 5);
    push(test->program->polish, 5);
    strcpy(test->test_program[0], "+");
    strcpy(test->test_program[1], ";");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    
    //Program will return FALSE, basic variable but no end
    
    
    strcpy(test->test_program[0], "V");
    strcpy(test->test_program[0], "");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
    
}

int test_pop(Test *test){
    //COULD CREATE A NEW TEST STACK IF I HAVE TIME!!
    Prog program;
    initialise_test(test, &program);
    //Function pops the last number off the stack return TRUE if it's equal to the last number pushed
    //Test should return FALSE, there is nothing in the stack
    test->current += 1;
    if(pop(test->program->polish) == FALSE ){
        test->pass += 1;
        fprintf(test->results, "\npop test 1: Passed");
    }
    else{
        fprintf(test->results, "\npop test 1: Passed");
    }
    
    
    //Test should return the number last popped onto stack
    test->current += 1;
    push(test->program->polish, 10);
    if(pop(test->program->polish) == 10){
        test->pass += 1;
        fprintf(test->results, "\npop test 2: Passed");
    }
    else{
        fprintf(test->results, "\npop test 2: Passed");
    }
    
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
    
    
}

int test_op(Test *test){
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "op");
    test->function = &op;
    //Checks that TRUE is returned when enough number on the stack and a valied operation: +, -, *, /. Function will return FALSE otherwise    
   
    
    //Tests addition should return TRUE
    
    push(test->program->polish, 10);
    strcpy(test->test_program[0], "+");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    
    //Tests subtraction should return TRUE
    
    push(test->program->polish, 10);
    strcpy(test->test_program[0], "-");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    
    //Tests multiplication should return TRUE
    
    push(test->program->polish, 10);
    strcpy(test->test_program[0], "*");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    
    //Tests division should return TRUE
    ;
    push(test->program->polish, 10);
    strcpy(test->test_program[0], "/");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    
    //Tests an invalid operation should return FALSE
    
    push(test->program->polish, 10);
    strcpy(test->test_program[0], ")");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //Tests when the stack has too few numbers should return FALSE
    pop(test->program->polish);
    
    strcpy(test->test_program[0], "+");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_multiply(Test *test){
    Prog program;
    initialise_test(test, &program);
    
    
    test->current += 1;
    //Test two whole numbers
    push(test->program->polish, 10);
    push(test->program->polish, 3);
    
    multiply(test->program);
    if(pop(test->program->polish) == 30){
        fprintf(test->results, "\nMultiply test 1: Passed");
        test->pass += 1;
    }
    else{
        fprintf(test->results, "\nMultiply test 1: Failed");
    }
    //Test with decimals
    test->current += 1;
    push(test->program->polish, 2.5);
    push(test->program->polish, 3);
    multiply(test->program);
    if(pop(test->program->polish) == 7.5){
        fprintf(test->results, "\nMultiply test 2: Passed");
        test->pass += 1;
    }
    else{
        fprintf(test->results, "\nMultiply test 2: Failed");
    }
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_divide(Test *test){
    Prog program;
    initialise_test(test, &program);
    
    
    test->current += 1;
    //Test two whole numbers
    push(test->program->polish, 10);
    push(test->program->polish, 2);
    divide(test->program);
    if(pop(test->program->polish) == 5){
        fprintf(test->results, "\nDivide test 1: Passed");
        test->pass += 1;
    }
    else{
        fprintf(test->results, "\nDivide test 1: Failed");
    }
    
    //Test with decimals
    test->current += 1;
    push(test->program->polish, 2.40);
    push(test->program->polish, 2);
    divide(test->program);
    if(pop(test->program->polish) == 1.2){
        fprintf(test->results, "\nDivide test 2: Passed");
        test->pass += 1;
    }
    else{
        fprintf(test->results, "\nDivide test 2: Failed");
    }
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_subtract(Test *test){
    Prog program;
    initialise_test(test, &program);
    double answer;
    
    test->current += 1;
    //Test two whole numbers
    push(test->program->polish, 10);
    push(test->program->polish, 1);
    subtract(test->program);
    if(pop(test->program->polish) == 9){
        fprintf(test->results, "\nSubtract test 1: Passed");
        test->pass += 1;
    }
    else{
        fprintf(test->results, "\nSubtract test 1: Failed");
    }
    
    //Test with decimals
    test->current += 1;
    push(test->program->polish, 3.79);
    push(test->program->polish, 1.88);
    subtract(test->program);
    if((answer = pop(test->program->polish)) == 1.910000){
        fprintf(test->results, "\nSubtract test 2: Passed");
        test->pass += 1;
    }
    else{
        fprintf(test->results, "\nSubtract test 2: Failed");
    }
    fprintf(stdout, "\nAnswer = %lf", answer);
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_add(Test *test){
    Prog program;
    
    initialise_test(test, &program);
    //strcpy(test->name, "Add");
    //test->function = &add;
    //Only need to test that the function adds numbers correctly
    //Other functions check that the stack only contains numbers
    //Tests push the correct numbers onto stack should push a solution onto the stack
    //Test two whole numbers
    
    test->current += 1;
    push(test->program->polish, 1);
    push(test->program->polish, 1);
    add(test->program);
    if(pop(test->program->polish) == 2){
        fprintf(test->results, "\nAdd test 1: Passed");
        test->pass += 1;
    }
    else{
        fprintf(test->results, "\nAdd test 1: Failed");
    }
    //Test with decimals
    test->current += 1;
    push(test->program->polish, 63.8921);
    push(test->program->polish, 0.1177);
    add(test->program);
    
    if(pop(test->program->polish) == 64.009800){
        fprintf(test->results, "\nAdd test 2: Passed");
        test->pass += 1;
    }
    else{
        fprintf(test->results, "\nAdd test 2: Failed");
    }
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_check_stack(Test *test){
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "Check_stack");
    test->function = &check_stack;
    //Is there automatically a number on the stack??
    
    //Tests pushes too few numbers onto stack should return FALSE
   
    
    printf("\nNumber automatically on stack: %lf\n", pop(test->program->polish));
    test->condition = FALSE;
    tester(test);
    
    //Tests pushes another number onto stack(so should be the amount needed) should return TRUE
    test->program->current_word = 0;
     
    push(test->program->polish, 20);
    test->condition = TRUE;
    tester(test);
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
    
}

int test_is_var(Test *test){
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "is_var");
    test->function = &is_var;
    
    //Tests a single capital letter should return TRUE
    
    
    strcpy(test->test_program[0], "Y");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    
    //Tests a single lower case letter should return FALSE
    
    
    strcpy(test->test_program[0], "g");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //Tests a digit should return FALSE
    
    
    strcpy(test->test_program[0], "7");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //Tests a word should return FALSE
   
    
    strcpy(test->test_program[0], "YES");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_is_number(Test *test){
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "is_number");
    test->function = &is_number;
    //Tests a single digit should return TRUE
    
    strcpy(test->test_program[0], "4");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    //Tests multiple digits should return TRUE
    
    strcpy(test->test_program[0], "432");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    //Tests negative number should return TRUE
    
    strcpy(test->test_program[0], "-432");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    //Tests a decimal number should return TRUE
    
    strcpy(test->test_program[0], "4.32");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    //Tests a decimal number with no leading digit should return FALSE
    
    strcpy(test->test_program[0], ".432");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    //Tests a letter should return FALSE
   
    strcpy(test->test_program[0], "D");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    //Tests multiple decimal places should return FALSE
    
    strcpy(test->test_program[0], "4.3.2");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED; 
    
}

int test_get_parameter(Test *test){
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "Get_parameter");
    test->function = &get_parameter;
    
    /*
    Because the function returns a number(for the parameter) or -1, FALSE is usually 0, but because the function can return 0 a False value is -1 for this function.
    */
    
    //Tests a number in a string, program should return the same number as an integer 
    
    strcpy(test->test_program[0], "6");
    write_program(test);
    test->condition = 6;
    tester(test);
    
    //Tests a letter, this has not been set so should return 0. 
    
    strcpy(test->test_program[0], "F");
    write_program(test);
    test->condition = 0;
    tester(test);
    
    //Tests an invalid string so should return -1
    
    strcpy(test->test_program[0], "one");
    write_program(test);
    test->condition = -1;
    tester(test);
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED; 
}

int test_varnum(Test *test){
    //Test test;
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "Varnum");
    test->function = &varnum;
    
    
    strcpy(test->test_program[0], "RT");
    strcpy(test->test_program[1], "40");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    

    strcpy(test->test_program[0], "RT");
    strcpy(test->test_program[1], "-3g");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    
    strcpy(test->test_program[0], "RT");
    strcpy(test->test_program[1], "-30");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    

    strcpy(test->test_program[0], "RT");
    strcpy(test->test_program[1], "A");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_assign_draw(FILE *test_pointer){
    /*  Not sure how to test this function
    prog program;
    int pass_count = 0, no_of_tests = 0;
    initialise_words_array(&program);
    
    no_of_tests += 1;
    program.current_angle = 90;
    program.current_length = 50;
    assign_draw(&program);
    
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
    */
    return PASSED;
}

int test_make_positive(FILE *test_pointer){

    int pass_count = 0, no_of_tests = 0, test_number;
    //Should always return a positive number, but not the positive version of the number given - is modded with 360 later.
    no_of_tests += 1;
    test_number = 50;
    if(make_positive(test_number) > 0){
        fprintf(test_pointer, "\nmake_positive test 1: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nmake_positive test 1: Failed");
    }
    
    no_of_tests += 1;
    test_number = -50;
    if(make_positive(test_number) > 0){
        fprintf(test_pointer, "\nmake_positive test 2: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nmake_positive test 2: Failed");
    }
    
    if(pass_count == no_of_tests){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_rt(Test *test){
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "Rt");
    test->function = &rt;
    
    
    //Test should pass, is correct instruction followed by a number - the number is actually checked in a different function tested separately.

    strcpy(test->test_program[0], "RT");
    strcpy(test->test_program[1], "10");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    //Test should pass, is correct instruction followed by a number - the number is actually checked in a different function tested separately.

    strcpy(test->test_program[0], "RT");
    strcpy(test->test_program[1], "-10");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    //test has a valid number, but incorrect instruction, test will pass if function returns FALSE

    strcpy(test->test_program[0], "LT");
    strcpy(test->test_program[1], "10");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    //test has a valid instruction, but not a number following so test will pass if function returns FALSE.

    strcpy(test->test_program[0], "RT");
    strcpy(test->test_program[1], "ten");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //test has a valid instruction, but not a number following so test will pass if function returns FALSE.

    strcpy(test->test_program[0], "RT");
    strcpy(test->test_program[1], "-ten");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    //test has a valid instruction, but not a number following so test will pass if function returns FALSE.

    strcpy(test->test_program[0], "RT");
    strcpy(test->test_program[1], "-4g");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_lt(Test *test){
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "Lt");
    test->function = &lt;
    
    
    //Test should pass, is correct instruction followed by a number - the number is actually checked in a different function tested separately.

    strcpy(test->test_program[0], "LT");
    strcpy(test->test_program[1], "10");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    //Test should pass, is correct instruction followed by a number - the number is actually checked in a different function tested separately.
;
    strcpy(test->test_program[0], "LT");
    strcpy(test->test_program[1], "-10");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    //test has a valid number, but incorrect instruction, test will pass if function returns FALSE

    strcpy(test->test_program[0], "RT");
    strcpy(test->test_program[1], "10");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    //test has a valid instruction, but not a number following so test will pass if function returns FALSE.

    strcpy(test->test_program[0], "LT");
    strcpy(test->test_program[1], "ten");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //test has a valid instruction, but not a number following so test will pass if function returns FALSE.

    strcpy(test->test_program[0], "LT");
    strcpy(test->test_program[1], "-ten");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    //test has a valid instruction, but not a number following so test will pass if function returns FALSE.

    strcpy(test->test_program[0], "LT");
    strcpy(test->test_program[1], "-4g");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_fd(Test *test){
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "Fd");
    test->function = &fd;
    
    
    //Test should pass, is correct instruction followed by a number - the number is actually checked in a different function tested separately.

    strcpy(test->test_program[0], "FD");
    strcpy(test->test_program[1], "10");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    //Test should pass, is correct instruction followed by a number - the number is actually checked in a different function tested separately.

    strcpy(test->test_program[0], "FD");
    strcpy(test->test_program[1], "-10");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    //test has a valid number, but incorrect instruction, test will pass if function returns FALSE

    strcpy(test->test_program[0], "RT");
    strcpy(test->test_program[1], "10");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    //test has a valid instruction, but not a number following so test will pass if function returns FALSE.

    strcpy(test->test_program[0], "FD");
    strcpy(test->test_program[1], "ten");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //test has a valid instruction, but not a number following so test will pass if function returns FALSE.

    strcpy(test->test_program[0], "FD");
    strcpy(test->test_program[1], "-ten");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    //test has a valid instruction, but not a number following so test will pass if function returns FALSE.

    strcpy(test->test_program[0], "FD");
    strcpy(test->test_program[1], "-4g");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}


int test_instruction(Test *test){
/*Function will call FD, LT and RT in turn*/
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "Instruction");
    test->function = &instruction;
    
    
    ///passing FD to function which should be correct, test should pass if TRUE is returned.

    strcpy(test->test_program[0], "FD");
    strcpy(test->test_program[1], "10");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    //passing LT to function which should be correct, test should pass if TRUE is returned.

    strcpy(test->test_program[0], "LT");
    strcpy(test->test_program[1], "10");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    //passing LT to function which should be correct, test should pass if TRUE is returned.

    strcpy(test->test_program[0], "RT");
    strcpy(test->test_program[1], "10");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    //passing an incorrect word to function which should not be correct, test should pass if FALSE is returned.

    strcpy(test->test_program[0], "something");
    strcpy(test->test_program[1], "10");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
    
}

int test_instrctlst(Test *test){
/*
Function should return TRUE if the current word is } otherwise, should call the instruction followed by itself, would call other functions in larger programs, but these are tested separately.
*/
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "Instrctlst");
    test->function = &instrctlst;
    
    
    //passes an incorrect word to instrctlst, this should be passed along and eventually return FALSE.
    strcpy(test->test_program[0], "Hello");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    //passes a correct program end so should return TRUE
    strcpy(test->test_program[0], "{");
    strcpy(test->test_program[1], "}");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    //passes an incorrect ending program to instrctlst, this should be passed along and eventually return FALSE.
    strcpy(test->test_program[0], "{");
    strcpy(test->test_program[0], "end");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_validate(Test *test){
/*
Tests need to check that the function only works if the program starts with a {, all other checks(including correct end) are done in other functions.
*/ 

    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "Validate");
    test->function = &validate;
    
    
    //Function is given an incorrect starting word, will pass if FALSE is returned
    strcpy(test->test_program[0], "Hello");
    strcpy(test->test_program[1], "{");
    strcpy(test->test_program[2], "}");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //function is given the most basic starting program, will pass if TRUE is returned, this is sort of testing the next function as well.
    strcpy(test->test_program[0], "{");
    strcpy(test->test_program[1], "}");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}
/*
int test_words_array(Test *test){
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "Validate");
    test->function = &validate;
    
    for(int i = 0; i < PROGRAM_LENGTH; i++){
        if(test_program.words[i][0] != '\0'){
            return NOT_PASSED;
        }
    }
    return PASSED;
}
*/
int test_check_input(Test *test){
    FILE *file_pointer;
    Prog program;
    char **test_array;
    initialise_test(test, &program);
    test_array = (char**)malloc(NO_INSTRUCTIONS * sizeof(char*));
    test_array[0] = (char*)malloc(INSTRUCTION_LENGTH * sizeof(char));
    int argc = 2; //argc values that would be read from command line, will be changed to test for different inputs
    
    //Test for correct number of inputs and file name, test will pass if function doesn't return NULL
    test->current += 1;
    test_array[0] = "prog_name";
    test_array[1] = "program.txt";

    file_pointer = check_input(test->program, argc, test_array);
    if(file_pointer == NULL){
        fprintf(test->results, "\nInput test 1: Failed");  
    }
    else{
        fprintf(test->results, "\nInput test 1: Passed");
        test->pass += 1;
    }
    //Test for incorrect file name, test will pass if NULL is returned
    test->current += 1;
    test_array[0] = "prog_name";
    test_array[1] = "progrm.txt";//Incorrect file name
     
   file_pointer = check_input(test->program, argc, test_array);
    if(file_pointer == NULL){
        fprintf(test->results, "\nInput test 2: Passed");  
        test->pass += 1;
    }
    else{
        fprintf(test->results, "\nInput test 2: Failed");
        //pass_count += 1;
    }
    //Supply's an incorrect 3rd input, test should pass if check_input returns NULL
    test->current += 1;
    argc = 3;
    test_array[0] = "prog_name";
    test_array[1] = "program.txt";
    test_array[2] = "hello";
    
    file_pointer = check_input(test->program, argc, test_array);
    if(file_pointer == NULL){
        fprintf(test->results, "\nInput test 3: Passed");  
        test->pass += 1;
    }
    else{
        fprintf(test->results, "\nInput test 3: Failed");
        //pass_count += 1;
    }
    
    //Test for input 'test', test will pass if function returns NULL and sets test element of program to TRUE.
    test->current += 1;
    argc = 2;
    test_array[0] = "prog_name";
    test_array[1] = "test";
    
    file_pointer = check_input(test->program, argc, test_array);
    if(file_pointer == NULL && test->program->test == TRUE){
        fprintf(test->results, "\nInput test 4: Passed");  
        test->pass += 1;
    }
    else{
        fprintf(test->results, "\nInput test 4: Failed");
    }
    //Tests for too few inputs, will pass if check_input returns NULL
    test->current += 1;
    argc = 1;
    test_array[0] = "prog_name";
    file_pointer = check_input(test->program, argc, test_array);
    if(file_pointer == NULL){
        fprintf(test->results, "\nInput test 5: Passed");  
        test->pass += 1;
    }
    else{
        fprintf(test->results, "\nInput test 5: Failed");
        //pass_count += 1;
    }
    
    if(test->pass != test->current){
        return PASSED;
    }
    else{       //ELSE NOT NEEDED, IS IT BETTER NOT TO HAVE?
        return NOT_PASSED;
    }
}
