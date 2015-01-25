#include "test.h"

void test(void){
	//FILE *test_pointer;
	Test test;
	//Prog program;
	//test.program = &program;
	//test_pointer = fopen("test_results.txt", "w");
	test.results = fopen("test_results.txt", "w");
	fprintf(test.results, "Below are the test results for each function:\n");
    if (test_check_input(test.results) == PASSED){
        print_outcome(test.results, "Check_input", "PASSED");
    }
    else{
        print_outcome(test.results, "Check_input", "FAILED");
    }   
    
    if (test_words_array(test.results) == PASSED){
        print_outcome(test.results, "Test_words_array", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_words_array", "FAILED");
    }
    
    if(test_validate(test.results) == PASSED){
        print_outcome(test.results, "Test_validate", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_validate", "FAILED");
    }
    
    if(test_instrctlst(test.results) == PASSED){
        print_outcome(test.results, "Test_instrctlst", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_instrctlst", "FAILED");
    }
    
    if(test_instruction(test.results) == PASSED){
        print_outcome(test.results, "Test_instruction", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_instruction", "FAILED");
    }
    
    if(test_fd(test.results) == PASSED){
        print_outcome(test.results, "Test_fd", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_fd", "FAILED");
    }
    
    if(test_lt(test.results) == PASSED){
        print_outcome(test.results, "Test_lt", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_lt", "FAILED");
    }
    
    if(test_rt(test.results) == PASSED){
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
    
    if(test_assign_draw(test.results) == PASSED){ //Not sure how to test this?
        print_outcome(test.results, "Test_assign_draw", "PASSED");
    }
    else{
        print_outcome(test.results, "Test_assign_draw", "FAILED");
    }
    
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

void initialise_test(Test *test, Prog *program){
    test->program = program;
    initialise_words_array(test->program);
    test->current = 0;
    test->pass = 0;
}

void tester(Test *test){
    if (test->function(test->program) == test->condition){
        fprintf(test->results, "\n%s test %d: Passed", test->name, test->current);
        test->pass += 1;
        return;
    }
    fprintf(test->results, "\n%s test %d: Failed", test->name, test->current);
    
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
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "DO");
    strcpy(test->program->words[1], "R");
    strcpy(test->program->words[2], "FROM");
    strcpy(test->program->words[3], "1");
    strcpy(test->program->words[4], "TO");
    strcpy(test->program->words[5], "2");
    strcpy(test->program->words[6], "{");
    strcpy(test->program->words[7], "}");
    test->condition = TRUE;
    tester(test);
    
    //Program will return FALSE, no variable defined
    test->program->current_word = 1;
    test->current += 1;
    strcpy(test->program->words[1], "DO");
    strcpy(test->program->words[2], "FROM");
    strcpy(test->program->words[3], "1");
    strcpy(test->program->words[4], "TO");
    strcpy(test->program->words[5], "2");
    strcpy(test->program->words[6], "{");
    strcpy(test->program->words[7], "}");
    test->condition = FALSE;
    tester(test);
    
    //Program will return FALSE, no opening bracket
    test->program->current_word = 1;
    test->current += 1;
    strcpy(test->program->words[1], "DO");
    strcpy(test->program->words[2], "A");
    strcpy(test->program->words[3], "FROM");
    strcpy(test->program->words[4], "1");
    strcpy(test->program->words[5], "TO");
    strcpy(test->program->words[6], "2");
    strcpy(test->program->words[7], "}");
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
    test->program->current_word = 0;
    test->current += 1;
    test->program->loop[letter] = 'A';
    test->program->loop[start] = 1;
    test->program->loop[stop] = 2;
    strcpy(test->program->words[1], "}");
    test->condition = TRUE;
    tester(test);
    
    //Program will return FALSE, start > end
    test->program->current_word = 0;
    test->current += 1;
    test->program->loop[letter] = 'A';
    test->program->loop[start] = 2;
    test->program->loop[stop] = 1;
    strcpy(test->program->words[1], "}");
    test->condition = FALSE;
    tester(test);
    
    //Program will return FALSE, basic loop with incomplete contents
    test->program->current_word = 0;
    test->current += 1;
    test->program->loop[letter] = 'A';
    test->program->loop[start] = 1;
    test->program->loop[stop] = 2;
    strcpy(test->program->words[1], "FD");
    strcpy(test->program->words[2], "10");
    strcpy(test->program->words[3], "RT");
    strcpy(test->program->words[4], "50");
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
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "FROM");
    strcpy(test->program->words[1], "1");
    strcpy(test->program->words[2], "TO");
    strcpy(test->program->words[3], "4");
    test->condition = TRUE;
    tester(test);
    
    //Program will return TRUE, basic loop condition with a letter
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "FROM");
    strcpy(test->program->words[1], "A");
    strcpy(test->program->words[2], "TO");
    strcpy(test->program->words[3], "4");
    test->condition = TRUE;
    tester(test);
    
    //Program will return TRUE, basic loop condition start = end
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "FROM");
    strcpy(test->program->words[1], "A");
    strcpy(test->program->words[2], "TO");
    strcpy(test->program->words[3], "A");
    test->condition = TRUE;
    tester(test);
    
    //Program will return FALSE, basic loop condition without FROM
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "5");
    strcpy(test->program->words[1], "TO");
    strcpy(test->program->words[2], "1");
    test->condition = FALSE;
    tester(test);
    
    //Program will return FALSE, basic loop condition without a second condition
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "FROM");
    strcpy(test->program->words[1], "5");
    strcpy(test->program->words[2], "TO");
    strcpy(test->program->words[3], "");
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
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "SET");
    strcpy(test->program->words[1], "A");
    strcpy(test->program->words[2], ":=");
    strcpy(test->program->words[3], "7");
    test->condition = FALSE;
    tester(test);
    
    //Program will return FALSE, basic expression doesn't contain an equals sign
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "SET");
    strcpy(test->program->words[1], "A");
    strcpy(test->program->words[2], "to");
    strcpy(test->program->words[3], "7");
    strcpy(test->program->words[4], ";");
    test->condition = FALSE;
    tester(test);
    
    //Program will return FALSE, basic expression doesn't start SET a variable
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "SET");
    strcpy(test->program->words[1], "5");
    strcpy(test->program->words[2], ":=");
    strcpy(test->program->words[3], "7");
    strcpy(test->program->words[4], ";");
    test->condition = FALSE;
    tester(test);
    
    //Program will return FALSE, basic expression doesn't start with SET
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "N");
    strcpy(test->program->words[1], ":=");
    strcpy(test->program->words[2], "5");
    strcpy(test->program->words[3], ";");
    test->condition = FALSE;
    tester(test);
    
    //Program will return FALSE, basic expression doesn't start with SET
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "N");
    strcpy(test->program->words[1], ":=");
    strcpy(test->program->words[2], "5");
    strcpy(test->program->words[3], ";");
    test->condition = FALSE;
    tester(test);
    //Program will return FALSE, basic SET expression without a value to set to
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "SET");
    strcpy(test->program->words[1], "G");
    strcpy(test->program->words[2], ":=");
    strcpy(test->program->words[3], ";");
    test->condition = FALSE;
    tester(test);
    
    //Program will return TRUE, basic SET expression passed
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "SET");
    strcpy(test->program->words[1], "G");
    strcpy(test->program->words[2], ":=");
    strcpy(test->program->words[3], "5");
    strcpy(test->program->words[4], ";");
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
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], ";");
    test->condition = TRUE;
    tester(test);
    
    //Program will return TRUE, basic number and end
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "7");
    strcpy(test->program->words[1], ";");
    test->condition = TRUE;
    tester(test);
    
    //Program will return TRUE, basic variable and end
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "V");
    strcpy(test->program->words[1], ";");
    test->condition = TRUE;
    tester(test);
    
    //Program will return TRUE, basic operation and end
    test->program->current_word = 0;
    test->current += 1;
    push(test->program->polish, 5);
    push(test->program->polish, 5);
    strcpy(test->program->words[0], "+");
    strcpy(test->program->words[1], ";");
    test->condition = TRUE;
    tester(test);
    
    //Program will return FALSE, basic variable but no end
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "V");
    strcpy(test->program->words[0], "");
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
    test->program->current_word = 0;
    
    //Tests addition should return TRUE
    test->current += 1;
    push(test->program->polish, 10);
    strcpy(test->program->words[0], "+");
    test->condition = TRUE;
    tester(test);
    
    //Tests subtraction should return TRUE
    test->current += 1;
    push(test->program->polish, 10);
    strcpy(test->program->words[0], "-");
    test->condition = TRUE;
    tester(test);
    
    //Tests multiplication should return TRUE
    test->current += 1;
    push(test->program->polish, 10);
    strcpy(test->program->words[0], "*");
    test->condition = TRUE;
    tester(test);
    
    //Tests division should return TRUE
    test->current += 1;
    push(test->program->polish, 10);
    strcpy(test->program->words[0], "/");
    test->condition = TRUE;
    tester(test);
    
    //Tests an invalid operation should return FALSE
    test->current += 1;
    push(test->program->polish, 10);
    strcpy(test->program->words[0], ")");
    test->condition = FALSE;
    tester(test);
    
    //Tests when the stack has too few numbers should return FALSE
    pop(test->program->polish);
    test->current += 1;
    strcpy(test->program->words[0], "+");
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
    
    test->program->current_word = 0;
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
    
    test->program->current_word = 0;
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
    test->program->current_word = 0;
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
    test->program->current_word = 0;
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
    test->program->current_word = 0;
    test->current += 1;
    printf("\nNumber automatically on stack: %lf\n", pop(test->program->polish));
    test->condition = FALSE;
    tester(test);
    
    //Tests pushes another number onto stack(so should be the amount needed) should return TRUE
    test->program->current_word = 0;
    test->current += 1;
    
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
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "Y");
    test->condition = TRUE;
    tester(test);
    
    //Tests a single lower case letter should return FALSE
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "g");
    test->condition = FALSE;
    tester(test);
    
    //Tests a digit should return FALSE
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "7");
    test->condition = FALSE;
    tester(test);
    
    //Tests a word should return FALSE
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "YES");
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
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "4");
    test->condition = TRUE;
    tester(test);
    //Tests multiple digits should return TRUE
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "432");
    test->condition = TRUE;
    tester(test);
    //Tests negative number should return TRUE
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "-432");
    test->condition = TRUE;
    tester(test);
    //Tests a decimal number should return TRUE
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "4.32");
    test->condition = TRUE;
    tester(test);
    //Tests a decimal number with no leading digit should return FALSE
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], ".432");
    test->condition = FALSE;
    tester(test);
    //Tests a letter should return FALSE
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "D");
    test->condition = FALSE;
    tester(test);
    //Tests multiple decimal places should return FALSE
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "4.3.2");
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
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "6");
    test->condition = 6;
    tester(test);
    
    //Tests a letter, this has not been set so should return 0. 
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "F");
    test->condition = 0;
    tester(test);
    
    //Tests an invalid string so should return -1
    test->program->current_word = 0;
    test->current += 1;
    strcpy(test->program->words[0], "one");
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
    
    
    test->program->current_word = 1;
    test->current += 1;
    strcpy(test->program->words[0], "RT");
    strcpy(test->program->words[1], "40");
    test->condition = TRUE;
    tester(test);
    
    test->program->current_word = 1;
    test->current += 1;
    strcpy(test->program->words[0], "RT");
    strcpy(test->program->words[1], "-3g");
    test->condition = FALSE;
    tester(test);
    
    test->program->current_word = 1;
    test->current += 1;
    strcpy(test->program->words[0], "RT");
    strcpy(test->program->words[1], "-30");
    test->condition = TRUE;
    tester(test);
    
    test->program->current_word = 1;
    test->current += 1;
    strcpy(test->program->words[0], "RT");
    strcpy(test->program->words[1], "A");
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

int test_rt(FILE *test_pointer){
    Prog program;
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
    //test has a valid instruction, but not a number following so test will pass if function returns FALSE.
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
    
    no_of_tests += 1;
    strcpy(program.words[0], "RT");
    strcpy(program.words[1], "gh");
    if(rt(&program) == FALSE){
        fprintf(test_pointer, "\nRT test 4: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nRT test 4: Failed");
    }
    
    no_of_tests += 1;
    strcpy(program.words[0], "RT");
    strcpy(program.words[1], "-gh");
    if(rt(&program) == FALSE){
        fprintf(test_pointer, "\nRT test 5: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nRT test 5: Failed");
    }
    
    no_of_tests += 1;
    strcpy(program.words[0], "RT");
    strcpy(program.words[1], "-4gh");
    if(rt(&program) == FALSE){
        fprintf(test_pointer, "\nRT test 6: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nRT test 6: Failed");
    }
    
    no_of_tests += 1;
    strcpy(program.words[0], "RT");
    strcpy(program.words[1], "4gh");
    if(rt(&program) == FALSE){
        fprintf(test_pointer, "\nRT test 7: Passed");
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nRT test 7: Failed");
    }
    
    
    
    if(pass_count == no_of_tests){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_lt(FILE *test_pointer){
    Prog program;
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
    Prog program;
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
    Prog program;
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
    Prog program;
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
    strcpy(program.words[0], "{");
    strcpy(program.words[1], "}");
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
    Prog program;
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
    Prog test_program;
    initialise_words_array(&test_program);
    for(int i = 0; i < PROGRAM_LENGTH; i++){
        if(test_program.words[i][0] != '\0'){
            return NOT_PASSED;
        }
    }
    return PASSED;
}

int test_check_input(FILE *test_pointer){
    FILE *file_pointer;
    Prog test_program;
    int pass_count = 0, no_of_tests = 0;
    int argc = 2; //argc values that would be read from command line, will be changed to test for different inputs
    char **test_array;
    test_array = (char**)malloc(NO_INSTRUCTIONS * sizeof(char*));
    test_array[0] = (char*)malloc(INSTRUCTION_LENGTH * sizeof(char*));
    //Test for correct number of inputs and file name, test will pass if function doesn't return NULL
    no_of_tests += 1;
    test_array[0] = "prog_name";
    test_array[1] = "program.txt";
    file_pointer = check_input(&test_program, argc, test_array);
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
    file_pointer = check_input(&test_program, argc, test_array);
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
    file_pointer = check_input(&test_program, argc, test_array);
    if(file_pointer == NULL){
        fprintf(test_pointer, "\nInput test 3: Passed");  
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nInput test 3: Failed");
        //pass_count += 1;
    }
    
    //Test for input 'test', test will pass if function returns NULL and sets test element of program to TRUE.
    no_of_tests += 1;
    argc = 2;
    test_array[0] = "prog_name";
    test_array[1] = "test";
    file_pointer = check_input(&test_program, argc, test_array);
    if(file_pointer == NULL && test_program.test == TRUE){
        fprintf(test_pointer, "\nInput test 4: Passed");  
        pass_count += 1;
    }
    else{
        fprintf(test_pointer, "\nInput test 4: Failed");
    }
    //Tests for too few inputs, will pass if check_input returns NULL
    no_of_tests += 1;
    argc = 1;
    test_array[0] = "prog_name";
    file_pointer = check_input(&test_program, argc, test_array);
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
