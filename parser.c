#include "parser.h"

int main(int argc, char **argv){
   	FILE *file_pointer;
    prog program;
    
    initialise_words_array(&program);
    
    file_pointer = check_input(&program, argc, argv);
    program.file_pointer = file_pointer;
    return run(&program);
    
}

int run(prog *program){
    int i = 0;
    if(program->file_pointer == NULL){
        if(program->test == TRUE){
            test();
            return 0;
        }
        return 1;
    }
    
    while(fscanf(program->file_pointer, "%s", program->words[i]) != EOF && i < PROGRAM_LENGTH){
        i++;
    }
    if(i == PROGRAM_LENGTH){
        fprintf(stdout, "\nYour program may be too long for the parser to handle.\n");
    }
    if (validate(program) == FALSE){
        exit(1);
    }
    printf("\nBefore draw");
    /*for(int i = 0; i < LETTERS; i++){
        printf("\nLetter: %lf", program->variable[i]);   
    }*/
    fprintf(stdout, "\nPARSED OK!");
    draw_turtle(program);
    return 0;
}

int validate(prog *program){
    printf("\nIn validate");
    for(int i = 0; i < LETTERS; i++){
        //printf("\nLetter: %lf", program->variable[i]);   
    }
    if(!strings_match(program->words[program->current_word], "{")){
        fprintf(stdout, "\nProgram needs to start with '{'");
        return FALSE;
    }
    program->current_word += 1;
    if(instrctlst(program) == FALSE){
        /*if (program->words[program->current_word][0] == '\0'){
            fprintf(stdout, "\nA program needs to end with a }.");
        }
        else{
            fprintf(stdout, "\nInstruction %s is not valid.", program->words[program->current_word]);
        } */
        return FALSE;
    }
    return TRUE;
}

int instrctlst(prog *program){
    if(strings_match(program->words[program->current_word], "}")){
        return TRUE;
    }
    if(instruction(program) == TRUE){
        program->current_word += 1;
        if (instrctlst(program) == TRUE){
            return TRUE;
        }
    }
    
       
    return FALSE;
}

int instruction(prog *program){
    if(fd(program) == TRUE){
        return TRUE;
    }
    
    if(lt(program) == TRUE){
        return TRUE;
    }
    
    if(rt(program) == TRUE){
        return TRUE;
    }
   
    if(set(program) == TRUE){
        return TRUE;
    }
    
    if(loop(program) == TRUE){
        return TRUE;
    }
    
    
    if(program->words[program->current_word][0] == '\0'){
        fprintf(stdout, "\nProgram needs to end with '}'.");
    }
    else{
        fprintf(stdout, "\nERROR in the word '%s'", program->words[program->current_word]);   //NEED TO LOOK HOW TO GIVE END MESSAGE
        program->current_word += 1;
    }
    return FALSE;
}

int loop(prog *program){
    int start, stop, i, variable_index, program_marker;
    if(!(strings_match(program->words[program->current_word], "DO"))){
        return FALSE;
    }
    program->current_word += 1;
    if(isVar(program) == FALSE){
        return FALSE;
    }
    variable_index = program->words[program->current_word][0] - 'A';
    program->current_word += 1;
    if(!(strings_match(program->words[program->current_word], "FROM"))){
        return FALSE;
    }
    program->current_word += 1;
    if(varnum(program) == TRUE){
        if(isVar(program) == TRUE){
            start = program->variable[program->words[program->current_word][0] - 'A'];
        }
        else{
            start = atoi(program->words[program->current_word]);
        }
    }
    else{
        return FALSE;
    }
    
    program->current_word += 1;
    
    if(!(strings_match(program->words[program->current_word], "TO"))){
        return FALSE;
    }
    
    program->current_word += 1;
    
    if(varnum(program) == TRUE){
        if(isVar(program) == TRUE){
            stop = program->variable[program->words[program->current_word][0] - 'A'];
        }
        else{
            stop = atoi(program->words[program->current_word]);
        }
    }
    else{
        return FALSE;
    }
    
    if(start > stop){
        return FALSE;
    }
    
    program->current_word += 1;
    
    if(!(strings_match(program->words[program->current_word], "{"))){
        return FALSE;
    }
    program->current_word += 1;
    program_marker = program->current_word;
    printf("\nBefore for loop...");
    for(i = start; i <= stop ; i++){
        
        
        program->variable[variable_index] = i;
        program->current_word = program_marker;
        if (instrctlst(program) == FALSE){
            return FALSE;
        }
    }
    return TRUE;
} 
    
int set(prog *program){
    //printf("\nIn Set");
    int variable_index;
    if(!(strings_match(program->words[program->current_word], "SET"))){
        return FALSE;
    }
    program->current_word += 1;
    
    if (isVar(program) == FALSE){
        return FALSE;
    }
    
    variable_index = program->words[program->current_word][0] - 'A';
    printf("\nVariable_index = %d", variable_index); 
    program->current_word += 1;
    if(!(strings_match(program->words[program->current_word], ":="))){
        return FALSE;
    }
    program->current_word += 1; 
    if(polish(program) == TRUE){  
        printf("\nVariable_index = %d", variable_index);
        printf("\nVariable c = %lf", program->result);
        program->variable[variable_index] = program->result;
        return TRUE;
    }
    return FALSE;
}

int polish(prog *program){
    //printf("\nIn Polish");
    int variable_index;
    //int tmp_int1, tmp_int2;
    //polish_list *tmp_list;
    //tmp_list = (polish_list*)malloc(sizeof(polish_list));
    if(strings_match(program->words[program->current_word], ";")){
        /*if(program->result != NULL){   //Is this a good way to check no result has been calculated? 
            printf("\nYou need to assign a numerical value using the SET function");
            return FALSE;
        else{*/
            program->result = pop(program->polish);
            return TRUE;
        //}
    }
    else if(op(program) == TRUE){
        
        program->current_word += 1;
        return polish(program);
    }
    else if(varnum(program) == TRUE){
        if(isVar(program) == TRUE){
            variable_index = program->words[program->current_word][0] - 'A';
           
            push(program->polish, program->variable[variable_index]);
        }
        else{
            //printf("\nNumber to set = %d", atoi(program->words[program->current_word]));
            push(program->polish, atof(program->words[program->current_word]));
            //printf("\nNumber in stack = %d", pop(program->polish));
        }
        
        program->current_word += 1;
        return polish(program);
    }
    else{
        return FALSE;
    }
}



int op(prog *program){
    //printf("\nIn Op");
    if(check_stack(program) == FALSE){
        return FALSE;
    }
    else if(strings_match(program->words[program->current_word], "+")){
        return add(program);
    }
    else if(strings_match(program->words[program->current_word], "-")){
        return subtract(program);
    }
    else if(strings_match(program->words[program->current_word], "*")){
        return multiply(program);
    }
    else if(strings_match(program->words[program->current_word], "/")){
        return divide(program);
    }
    else{
        return FALSE;
    }
}

double pop(stack *tmp_pointer){
    //printf("\nIn Pop");
    double number;
    number = tmp_pointer->pointer->number;
    tmp_pointer->pointer = tmp_pointer->pointer->previous;
    return number;
}

void push(stack *tmp_polish, double number){
    //printf("\nIn Push");
    polish_list *new;
    new = (polish_list*)malloc(sizeof(polish_list));
    new->previous = tmp_polish->pointer;
    new->number = number;
    tmp_polish->pointer = new;
}

int add(prog *program){
    //printf("\nIn Add");
    double one, two, result;
    one = pop(program->polish);
    two = pop(program->polish);
    
    result = one + two;
    push(program->polish, result);
    return TRUE;    
    
}

int subtract(prog *program){
    double one, two, result;
    one = pop(program->polish);
    two = pop(program->polish);
    
    result = two - one; // if this was other way round and I got a negative number, the line is just smaller not opposite?
    push(program->polish, result);
    return TRUE;  
}

int multiply(prog *program){
    double one, two, result;
    one = pop(program->polish);
    two = pop(program->polish);
    printf("\nOne = %lf", one);
    printf("\nTwo = %lf", two);
   
    result = one * two; 
     printf("\nMultiplied result = %lf", result);
    push(program->polish, result);
    return TRUE;  
}

int divide(prog *program){
    double one, two, result;
    one = pop(program->polish);
    two = pop(program->polish);
    
    result = two / one; 
    push(program->polish, result);
    return TRUE;  
}  

int check_stack(prog *program){
    //printf("\nIn Check_stack");
    stack *tmp_stack;
   // printf("\nBefore set stack");
    tmp_stack = program->polish;
    //printf("\nAfter set stack");
    if(tmp_stack->pointer != NULL && tmp_stack->pointer->previous != NULL){
        return TRUE;
    }
    return FALSE; 
}

int fd(prog *program){
    int length, variable_index;
    /*printf("\nIn FD");
    for(int i = 0; i < LETTERS; i++){
        printf("\nLetter: %d", program->variable[i]);   
    }*/
    if(!(strings_match(program->words[program->current_word], "FD"))){
        return FALSE;
    }
    program->current_word += 1;
    
    if (varnum(program) == TRUE){
        if (isVar(program) == TRUE){
            variable_index = program->words[program->current_word][0] - 'A';
            //printf("\nVariable_index = %d", variable_index);
            //printf("\nVariable A value = %lf", program->variable[variable_index]);
            length = program->variable[variable_index];
        }
        else{
            length = atoi(program->words[program->current_word]);
        }
        //printf("\nCurrent length = %d", length);
        program->current_length = length;
        assign_draw(program);
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int lt(prog *program){
    if(!(strings_match(program->words[program->current_word], "LT"))){
        return FALSE;
    }
    program->current_word += 1;
    if (varnum(program) == TRUE){
        program->current_angle -= atoi(program->words[program->current_word]);
        return TRUE;
    }
    else{
    
        return FALSE;
    }
}

int rt(prog *program){
    if(!(strings_match(program->words[program->current_word], "RT"))){
        return FALSE;
    }
    program->current_word += 1;
    if (varnum(program) == TRUE){
        program->current_angle += atoi(program->words[program->current_word]);
        return TRUE;
    }
    else{
        return FALSE;
    }
}

void assign_draw(prog *program){
    //printf("\nCurrent angle = %d", program->current_angle);
    program->current_angle = make_positive(program->current_angle); //incase current angle has become negative
    //printf("\nCurrent angle = %d", program->current_angle);
   
    set_new_xy(program);
    program->draw[program->draw_pointer] = program->current_x;
    program->draw_pointer += 1;
    program->draw[program->draw_pointer] = program->current_y;
    program->draw_pointer += 1;
}

void set_new_xy(prog *program){
    double tmp_angle;
    tmp_angle = DEGTORAD(program->current_angle % 90);
    if(program->current_angle >= 270){
        //printf("\nGreater than 270");
        //printf("\nSin of angle %lf: %lf", tmp_angle, sin(tmp_angle));
        //printf("\nCos of angle %lf: %lf", tmp_angle, cos(tmp_angle));
        program->current_x -= (cos(tmp_angle) * program->current_length);
        program->current_y -= (sin(tmp_angle) * program->current_length);
    }
    else if(program->current_angle >= 180){
        //printf("\nGreater than 180");
        //printf("\nSin of angle %lf: %lf", tmp_angle, sin(tmp_angle));
        //printf("\nCos of angle %lf: %lf", tmp_angle, cos(tmp_angle));
        program->current_x -= (sin(tmp_angle) * program->current_length);
        program->current_y += (cos(tmp_angle) * program->current_length);
    }
    else if(program->current_angle >= 90){
        //printf("\nGreater than 90");
        //printf("\nSin of angle %lf: %lf", tmp_angle, sin(tmp_angle));
        //printf("\nCos of angle %lf: %lf", tmp_angle, cos(tmp_angle));
        program->current_x += (cos(tmp_angle) * program->current_length);
        program->current_y += (sin(tmp_angle) * program->current_length);
    }
    else{
        //printf("\nGreater than 0");
        //printf("\nCurrent angle: %d", program->current_angle);
        //printf("\nCurrent x: %d", program->current_x);
        //printf("\nCurrent y: %d", program->current_y);
        //printf("\nSin of angle %lf: %lf", tmp_angle, sin(tmp_angle));
        //printf("\nCos of angle %lf: %lf", tmp_angle, cos(tmp_angle));
        program->current_x += (sin(tmp_angle) * program->current_length);
        program->current_y -= (cos(tmp_angle) * program->current_length);
        //printf("\nCurrent x: %d", program->current_x);
        //printf("\nCurrent y: %d", program->current_y);
    }
}

int make_positive(int angle){
    
    if(angle >= 0){
        return angle % 360;
    }
    else{
        return make_positive(angle+360);
    }
}

int varnum(prog *program){
    //printf("\nIn Varnum");
    if(isNumber(program) == TRUE){
        return TRUE;
    }
    else if(isVar(program) == TRUE){
        return TRUE;
    }
    return FALSE;
    
    
}

int isNumber(prog *program){
    //printf("\nIn isNumber");
    int word_length, i;
    double number;
    word_length = strlen(program->words[program->current_word]);
    if(!isdigit(program->words[program->current_word][0]) && program->words[program->current_word][0] != '-'){
        return FALSE;
    }
    
    for( i = 1; i < word_length; i++){
        if(!isdigit(program->words[program->current_word][i]) && program->words[program->current_word][i] != '.'){
            fprintf(stdout, "\nThe value %s, is not valid with operation %s. Needs to be a whole number at least 1", program->words[program->current_word], program->words[program->current_word - 1]);
            return FALSE;
        }
    }
    
    number = atof(program->words[program->current_word]);
    //printf("\nNumber = %lf", number);
    if(number == 0){
        fprintf(stdout, "\nThe value %s, is not valid with operation %s. Needs to be a whole number above 1", program->words[program->current_word], program->words[program->current_word - 1]);
        return FALSE;
    }
    return TRUE;
}

int isVar(prog *program){
    //printf("\nIn isVar");
    int word_length;
    word_length = strlen(program->words[program->current_word]);
    if(word_length != 1){
        return FALSE;
    }
    if(isupper(program->words[program->current_word][0])){
        return TRUE;
    }
    return FALSE;
}

void initialise_words_array(prog *program){
    
    program->current_word = 0;
    program->current_x = WINDOW_WIDTH/2;;
    program->current_y = WINDOW_HEIGHT/2;
    program->current_angle = 0;
    program->draw_pointer = 2;
    program->polish = (stack*)malloc(sizeof(stack));
    program->polish->pointer = (polish_list*)malloc(sizeof(polish_list));
    memset(program->variable, 0, LETTERS);
    /*for(int i = 0; i < LETTERS; i++){
        program->variable[i] = 0;
        printf("\nLetter: %lf", program->variable[i]);   
    }*/
    program->test = FALSE;
    //Sets the first letter of each word to the NULL character
    for(int i = 0; i < PROGRAM_LENGTH; i++){
        program->words[i][0] = '\0';
        program->draw[i] = -1;
    }
    //Sets the start points for the turtle
    program->draw[0] = WINDOW_WIDTH/2;
    program->draw[1] = WINDOW_HEIGHT/2;
}

FILE* check_input(prog *program, int argc, char **argv){
    FILE *file_pointer = NULL;
    
    if(!(argc == 2)){
        fprintf(stdout, "\nYou must enter 2 commands:\n   the first should be the executable file,\n   the second should be the text file to read from,\n   or, if wanted should be the word 'test' this will run the test function");
        return NULL;
    }
    
    if(strings_match(argv[1], "test")){
        program->test = TRUE;
        return NULL;
    }
    if((file_pointer = fopen(argv[1], "r")) == NULL){
        fprintf(stdout, "\nCan't open the file you have specified");
        return NULL;
    }
    return file_pointer;
}
