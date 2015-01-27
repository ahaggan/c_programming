#include "test.h"

void test(void){
	Test test;
	int i; 
    test.no_passed = 0;
    test.no_failed = 0;
    //Array of function pointers to the test functions
    int(*test_function[NO_TESTS])(Test*) = {&test_parse, &test_check_input, &test_initialise_program, &test_validate, &test_instrctlst, &test_instruction, &test_fd, &test_lt, &test_rt, &test_make_positive, &test_varnum, &test_push, &test_get_parameter, &test_is_number, &test_is_var, &test_check_stack, &test_add, &test_subtract, &test_divide, &test_multiply, &test_op, &test_pop, &test_polish, &test_set, &test_loop_condition, &test_perform_loop, &test_loop, &test_set_new_xy, &test_if_condition, &test_if_letter, &test_if_colour, &test_assign_colour, &test_set_colour, &test_set_letter};
    //Array of function names in the same order as above
    char function_name[NO_TESTS][FUNCTION_NAME] = {"Test parse", "Test check input", "Test initialise program", "Test validate", "Test instrctlst", "Test instruction","Test fd","Test lt","Test rt","Test make positive", "Test varnum", "Test push", "Test get parameter", "Test is number", "Test is var","Test check stack","Test add", "Test subtract", "Test divide", "Test multiply","Test op","Test pop", "Test polish", "Test set", "Test loop condition", "Test perform loop", "Test loop", "Test set new xy", "Test if condition", "Test if letter", "Test if colour", "Test assign colour", "Test set colour", "Test set letter"};

	test.results = fopen("test_results.txt", "w");
	fprintf(test.results, "Below are the test results for each function:\n");
    //Runs through each test in the above array and prints the results
    for(i = 0; i < NO_TESTS; i++){
        run_test(test_function[i], &test, function_name[i]);
        fprintf(stdout, "\nTEST %s COMPLETED\n", function_name[i]);
    }
    
    fprintf(test.results, "\nNUMBER OF TESTS PASSED: %d\n", test.no_passed);
    fprintf(test.results, "\nNUMBER OF TESTS FAILED: %d\n", test.no_failed);
    fclose(test.results);
    
    
    /*
    if(test_assign_draw(&test) == PASSED){ //Not sure how to test this?
    
    
    */

   
}

void run_test(int(*test_function)(Test*), Test *test, char *test_name){
    if(test_function(test) == PASSED){
        print_outcome(test->results, test_name, "PASSED");
        test->no_passed += 1;
    }
    else{
        print_outcome(test->results, test_name, "FAILED");
        test->no_failed += 1;
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
    initialise_program(test->program);
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

int test_parse(Test *test){
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "parse");
    test->function = &parse;
    
    //Basic FD RT and LT used should PASS
    test->program->file_pointer = fopen("test1.txt", "r");
    test->condition = TRUE;
    tester(test);

    //Basic DO loop used should PASS
    test->program->file_pointer = fopen("test2.txt", "r");
    test->condition = TRUE;
    tester(test);

    //DO loop using polish multiplication should PASS
    test->program->file_pointer = fopen("test3.txt", "r");
    test->condition = TRUE;
    tester(test);

    //Nested loop using multiple letters and polish operations should PASS
    test->program->file_pointer = fopen("test4.txt", "r");
    test->condition = TRUE;
    tester(test);

    //Basic SET COLOUR instruction used should PASS
    test->program->file_pointer = fopen("test5.txt", "r");
    test->condition = TRUE;
    tester(test);

    //SET COLOUR instruction used in a DO loop should PASS
    test->program->file_pointer = fopen("test6.txt", "r");
    test->condition = TRUE;
    tester(test);
    
    //IF statement used in a DO loop should PASS
    test->program->file_pointer = fopen("test7.txt", "r");
    test->condition = TRUE;
    tester(test);

    //Multiple IF statements used in a DO loop should PASS
    test->program->file_pointer = fopen("test8.txt", "r");
    test->condition = TRUE;
    tester(test);

    

    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_if_condition(Test *test){
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "If_condition");
    test->function = &if_condition;
    
    
    //Program will return TRUE, passed a basic if statement with number
    
    strcpy(test->test_program[0], "IF");
    strcpy(test->test_program[1], "A");
    strcpy(test->test_program[2], ":=");
    strcpy(test->test_program[3], "7");
    strcpy(test->test_program[4], "{");
    strcpy(test->test_program[5], "}");
    write_program(test);
    test->condition = TRUE;
    tester(test);

    //Program will return FALSE, passed a basic statement doesn't start with IF
    
    strcpy(test->test_program[0], "When");
    strcpy(test->test_program[1], "A");
    strcpy(test->test_program[2], ":=");
    strcpy(test->test_program[3], "7");
    strcpy(test->test_program[4], "{");
    strcpy(test->test_program[5], "}");
    write_program(test);
    test->condition = FALSE;
    tester(test);

    //Program will return TRUE, passed a basic statement comparing to variable
    strcpy(test->test_program[0], "IF");
    strcpy(test->test_program[1], "A");
    strcpy(test->test_program[2], ":=");
    strcpy(test->test_program[3], "C");
    strcpy(test->test_program[4], "{");
    strcpy(test->test_program[5], "}");
    write_program(test);
    test->condition = TRUE;
    tester(test);

    //Program will return FALSE, comparing a variable to a colour
    strcpy(test->test_program[0], "IF");
    strcpy(test->test_program[1], "A");
    strcpy(test->test_program[2], ":=");
    strcpy(test->test_program[3], "BLUE");
    strcpy(test->test_program[4], "{");
    strcpy(test->test_program[5], "}");
    write_program(test);
    test->condition = FALSE;
    tester(test);

     
    //Program will return TRUE, comparing a colour to a colour
    strcpy(test->test_program[0], "IF");
    strcpy(test->test_program[1], "COLOUR");
    strcpy(test->test_program[2], ":=");
    strcpy(test->test_program[3], "RED");
    strcpy(test->test_program[4], "{");
    strcpy(test->test_program[5], "}");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}
int test_if_letter(Test *test){
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "If_letter");
    test->function = &if_letter;
    
    
    //Program will return TRUE, passed a basic if statement for a letter
    
    strcpy(test->test_program[0], "A");
    strcpy(test->test_program[1], ":=");
    strcpy(test->test_program[2], "7");
    strcpy(test->test_program[3], "{");
    strcpy(test->test_program[4], "}");
    write_program(test);
    test->condition = TRUE;
    tester(test);

    //Program will return FALSE, passed a basic if statement for a colour
    
    strcpy(test->test_program[0], "COLOUR");
    strcpy(test->test_program[1], ":=");
    strcpy(test->test_program[2], "BLUE");
    strcpy(test->test_program[3], "{");
    strcpy(test->test_program[4], "}");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //Program will return FALSE, passed a letter compared to COLOUR
    
    strcpy(test->test_program[0], "G");
    strcpy(test->test_program[1], ":=");
    strcpy(test->test_program[2], "BLUE");
    strcpy(test->test_program[3], "{");
    strcpy(test->test_program[4], "}");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    

    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;

}
int test_if_colour(Test *test){
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "If_colour");
    test->function = &if_colour;
    
    
    //Program will return TRUE, passed a basic if statement for colour
    
    strcpy(test->test_program[0], "COLOUR");
    strcpy(test->test_program[1], ":=");
    strcpy(test->test_program[2], "RED");
    strcpy(test->test_program[3], "{");
    strcpy(test->test_program[4], "}");
    write_program(test);
    test->condition = TRUE;
    tester(test);

    //Program will return FALSE, passed a basic if statement without a := sign
    
    strcpy(test->test_program[1], "equals");
    strcpy(test->test_program[2], "9");
    strcpy(test->test_program[3], "{");
    strcpy(test->test_program[4], "}");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    

    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}
int test_assign_colour(Test *test){
    //Tests each available colour
    Prog program;
    initialise_test(test, &program);    
    
    //Test assign WHITE
    test->current += 1;
    strcpy(test->program->colour, "WHITE");
    assign_colour(test->program);
    if(test->program->coordinate->red == 255 && test->program->coordinate->green == 255 && test->program->coordinate->blue == 255){
        test->pass += 1;
        fprintf(test->results, "\nAssign_colour test 1: Passed");
    }
    else{
        fprintf(test->results, "\nAssign_colour test 1: Failed");
    }

    //Test assign RED
    test->current += 1;
    strcpy(test->program->colour, "RED");
    assign_colour(test->program);
    if(test->program->coordinate->red == 255 && test->program->coordinate->green == 0 && test->program->coordinate->blue == 0){
        test->pass += 1;
        fprintf(test->results, "\nAssign_colour test 2: Passed");
    }
    else{
        fprintf(test->results, "\nAssign_colour test 2: Failed");
    }

    //Test assign GREEN
    test->current += 1;
    strcpy(test->program->colour, "GREEN");
    assign_colour(test->program);
    if(test->program->coordinate->red == 0 && test->program->coordinate->green == 255 && test->program->coordinate->blue == 0){
        test->pass += 1;
        fprintf(test->results, "\nAssign_colour test 3: Passed");
    }
    else{
        fprintf(test->results, "\nAssign_colour test 3: Failed");
    }
    //Test assign BLUE
    test->current += 1;
    strcpy(test->program->colour, "BLUE");
    assign_colour(test->program);
    if(test->program->coordinate->red == 0 && test->program->coordinate->green == 0 && test->program->coordinate->blue == 255){
        test->pass += 1;
        fprintf(test->results, "\nAssign_colour test 4: Passed");
    }
    else{
        fprintf(test->results, "\nAssign_colour test 4: Failed");
    }
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}
int test_set_colour(Test *test){
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "Set_colour");
    test->function = &set_colour;
    
    
    //Program will return TRUE, passed a basic if statement for colour
    
    strcpy(test->test_program[0], "COLOUR");
    strcpy(test->test_program[1], ":=");    //Only matters from here
    strcpy(test->test_program[2], "RED");
    strcpy(test->test_program[3], ";");
    write_program(test);
    test->condition = TRUE;
    tester(test);

    //Program will return FALSE, missing := sign
    
    strcpy(test->test_program[0], "COLOUR");
    strcpy(test->test_program[1], "to");    //Only matters from here
    strcpy(test->test_program[2], "RED");
    strcpy(test->test_program[3], ";");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //Program will return FALSE, invalid colour
    
    strcpy(test->test_program[0], "COLOUR");
    strcpy(test->test_program[1], ":=");    //Only matters from here
    strcpy(test->test_program[2], "INDIGO");
    strcpy(test->test_program[3], ";");
    write_program(test);
    test->condition = FALSE;
    tester(test);

    //Program will return FALSE, needs to end with ;
    
    strcpy(test->test_program[0], "COLOUR");
    strcpy(test->test_program[1], ":=");    //Only matters from here
    strcpy(test->test_program[2], "BLUE");
    strcpy(test->test_program[3], "{");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //Program will return FALSE, doesn't set to antything
    
    strcpy(test->test_program[0], "COLOUR");
    strcpy(test->test_program[1], ":=");    //Only matters from here
    strcpy(test->test_program[2], ";");
    write_program(test);
    test->condition = FALSE;
    tester(test);

    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}
int test_set_letter(Test *test){
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "Set_letter");
    test->function = &set_letter;
    
    
    //Program will return TRUE, passed a basic set letter to number
    
    strcpy(test->test_program[0], "K");
    strcpy(test->test_program[1], ":=");    
    strcpy(test->test_program[2], "8");
    strcpy(test->test_program[3], ";");
    write_program(test);
    test->condition = TRUE;
    tester(test);

    //Program will return TRUE, passed a basic set letter to variable
    
    strcpy(test->test_program[0], "K");
    strcpy(test->test_program[1], ":=");    
    strcpy(test->test_program[2], "J");
    strcpy(test->test_program[3], ";");
    write_program(test);
    test->condition = TRUE;
    tester(test);

    //Program will return FALSE, try to set letter to a word
    
    strcpy(test->test_program[0], "K");
    strcpy(test->test_program[1], ":=");    
    strcpy(test->test_program[2], "RED");
    strcpy(test->test_program[3], ";");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //Program will return FALSE, try to set to nothing
    
    strcpy(test->test_program[0], "K");
    strcpy(test->test_program[1], ":=");    
    strcpy(test->test_program[2], ";");
    write_program(test);
    test->condition = FALSE;
    tester(test);

    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}

int test_initialise_program(Test *test){
    Prog program;
    initialise_program(&program);
    if(program.current_word == NULL){
        return NOT_PASSED;
    }
    if(program.start_coordinate.current_x != WINDOW_WIDTH/2){
        return NOT_PASSED;
    }
    if(program.start_coordinate.current_y != WINDOW_HEIGHT/2){
        return NOT_PASSED;
    }
    if(program.assign != TRUE){
        return NOT_PASSED;
    }
    if(!strings_match(program.colour, "WHITE")){
        return NOT_PASSED;
    }
    if(program.current_angle != 0){
        return NOT_PASSED;
    }
    if(program.polish == NULL){
        return NOT_PASSED;
    }
    for(int i = 0; i < LETTERS; i++){
        if(program.variable[i] != 0){
            return NOT_PASSED;
        }
    }
    if(program.test != FALSE){
        return NOT_PASSED;
    }
    return PASSED;

}

int test_push(Test *test){
    Prog program;
    initialise_test(test, &program);
    
    
    //Test should pass, is correct instruction followed by a number - the number is actually checked in a different function tested separately.
    test->current += 1;
    push(program.polish, 10);
    push(program.polish, 20);
    if(pop(&program) == 20){
        if(pop(&program) == 10){
            test->pass += 1;
            fprintf(test->results, "\nPush test 1: Passed");
        }
        else{
            fprintf(test->results, "\nPush test 1: Failed");
        }
    }
    else{
        fprintf(test->results, "\nPush test 1: Failed");
    }
    
    
    
    if(test->current == test->pass){
        return PASSED;
    }
    return NOT_PASSED; 
    
}


int test_set_new_xy(Test *test){
    //Tests an angle that falls into each of the different categories in the function.
    Prog program;
    initialise_test(test, &program);
    test->program->current_length = 100;
    test->program->coordinate->current_x = 100;
    test->program->coordinate->current_y = 100;
    //Test angle of 0
    test->current += 1;
    test->program->current_angle = 0;
    set_new_xy(test->program);
    printf("\nPROGRAM X COORD: %d\n", (int)test->program->coordinate->current_x);
    printf("\nPROGRAM Y COORD: %d\n", (int)test->program->coordinate->current_y);
    if(test->program->coordinate->current_x == 100 && test->program->coordinate->current_y == 0){
            test->pass += 1;
            fprintf(test->results, "\nSet_nex_xy test 1: Passed");
        }
    else{
            fprintf(test->results, "\nSet_nex_xy test 1: Failed");
    }
    //Test angle of 90
    test->current += 1;
    test->program->coordinate->current_x = 100;
    test->program->coordinate->current_y = 100;
    test->program->current_angle = 90;
    set_new_xy(test->program);
    printf("\nPROGRAM X COORD: %d\n", (int)test->program->coordinate->current_x);
    printf("\nPROGRAM Y COORD: %d\n", (int)test->program->coordinate->current_y);
    if(test->program->coordinate->current_x == 200 && test->program->coordinate->current_y == 100){
            test->pass += 1;
            fprintf(test->results, "\nSet_nex_xy test 2: Passed");
        }
    else{
            fprintf(test->results, "\nSet_nex_xy test 2: Failed");
    }
    //Test angle of 180
    test->current += 1;
    test->program->coordinate->current_x = 100;
    test->program->coordinate->current_y = 100;
    test->program->current_angle = 180;
    set_new_xy(test->program);
    printf("\nPROGRAM X COORD: %d\n", (int)test->program->coordinate->current_x);
    printf("\nPROGRAM Y COORD: %d\n", (int)test->program->coordinate->current_y);
    if(test->program->coordinate->current_x == 100 && test->program->coordinate->current_y == 200){
            test->pass += 1;
            fprintf(test->results, "\nSet_nex_xy test 3: Passed");
        }
    else{
            fprintf(test->results, "\nSet_nex_xy test 3: Failed");
    }
    //Test angle of 270
    test->current += 1;
    test->program->coordinate->current_x = 100;
    test->program->coordinate->current_y = 100;
    test->program->current_angle = 270;
    set_new_xy(test->program);
    printf("\nPROGRAM X COORD: %d\n", (int)test->program->coordinate->current_x);
    printf("\nPROGRAM Y COORD: %d\n", (int)test->program->coordinate->current_y);
    if(test->program->coordinate->current_x == 0 && test->program->coordinate->current_y == 100){
            test->pass += 1;
            fprintf(test->results, "\nSet_nex_xy test 4: Passed");
        }
    else{
            fprintf(test->results, "\nSet_nex_xy test 4: Failed");
    }

    if(test->current == test->pass){
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
    
    test->program->loop[letter] = 'A';
    test->program->loop[start] = 1;
    test->program->loop[stop] = 2;
    strcpy(test->test_program[0], "{");//Needed for the function but not read
    strcpy(test->test_program[1], "}");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    
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
    push(test->program->polish, 10); // Pop's a value if ; found so needs a value on the stack    
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
    if(pop(test->program) == FALSE ){
        test->pass += 1;
        fprintf(test->results, "\npop test 1: Passed");
    }
    else{
        fprintf(test->results, "\npop test 1: Passed");
    }
        
    //Test should return the number last popped onto stack
    test->current += 1;
    push(test->program->polish, 10);
    if(pop(test->program) == 10){
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
    
    /*
    //Tests when the stack has too few numbers should return FALSE
    pop(test->program);
    
    strcpy(test->test_program[0], "+");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    */
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
    if(pop(test->program) == 30){
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
    if(pop(test->program) == 7.5){
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
    if(pop(test->program) == 5){
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
    if(pop(test->program) == 1.2){
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
    int answer;
    
    test->current += 1;
    //Test two whole numbers
    push(test->program->polish, 10);
    push(test->program->polish, 1);
    subtract(test->program);
    if(pop(test->program) == 9){
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
    answer = (int)(100 * pop(test->program)); //Tests to 2 dp of accuracy
    if(answer == 191){
        fprintf(test->results, "\nSubtract test 2: Passed");
        test->pass += 1;
    }
    else{
        fprintf(test->results, "\nSubtract test 2: Failed");
    }
    //fprintf(stdout, "\nAnswer = %lf", answer);
    
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
    if(pop(test->program) == 2){
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
    
    if(pop(test->program) == 64.009800){
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
    push(test->program->polish, 20);
    test->condition = FALSE;
    tester(test);
    
    //Tests pushes another number onto stack(so should be the amount needed) should return TRUE
    test->program->current_word = 0;
    push(test->program->polish, 10);
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
    //Tests just "-" sign should return FALSE
    
    strcpy(test->test_program[0], "-");
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
    /*
    Function calls in_number and is_var functions which are tested separately so only basic testing 
    */
    Prog program;
    initialise_test(test, &program);
    strcpy(test->name, "Varnum");
    test->function = &varnum;
    
    //Passes a capital letter, should return TRUE
    strcpy(test->test_program[0], "R");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    
    //Passes a lower case letter should return FALSE
    strcpy(test->test_program[0], "g");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //Passes multiple letters should return FALSE
    strcpy(test->test_program[0], "RT");
    write_program(test);
    test->condition = FALSE;
    tester(test);
    
    //Passes a number, should return TRUE
    strcpy(test->test_program[0], "6");
    write_program(test);
    test->condition = TRUE;
    tester(test);
    
    if(test->pass == test->current){
        return PASSED;
    }
    return NOT_PASSED;
}


int test_make_positive(Test *test){
    Prog program;
    int test_number;
    initialise_test(test, &program);
    //Should always return a positive number, but not the positive version of the number given - is modded with 360 later.
    test->current += 1;
    test_number = 50;
    if(make_positive(test_number) > 0){
        fprintf(test->results, "\nmake_positive test 1: Passed");
        test->pass += 1;
    }
    else{
        fprintf(test->results, "\nmake_positive test 1: Failed");
    }
    
    test->current += 1;
    test_number = -50;
    if(make_positive(test_number) > 0){
        fprintf(test->results, "\nmake_positive test 2: Passed");
         test->pass += 1;
    }
    else{
        fprintf(test->results, "\nmake_positive test 2: Failed");
    }
    
    if(test->current == test->pass){
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
    strcpy(test->test_program[0], "}");
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



int test_program(Test *test){
    
            return NOT_PASSED;
    
}

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
    
    if(test->pass == test->current){
        return PASSED;
    }
    else{       //ELSE NOT NEEDED, IS IT BETTER NOT TO HAVE?
        return NOT_PASSED;
    }
}
