#include "parser.h"

int main(int argc, char **argv){
   	
    Prog program;
    
    
    initialise_program(&program);
    program.file_pointer = check_input(&program, argc, argv);
    
    if(program.file_pointer == NULL){
        if(program.test == TRUE){
            test();
            return 0;
        }
        return 1;
    }
    else{
        if(parse(&program) == TRUE){
            
            draw_turtle(&program);
            return 0;
        }
    }
    return 1;
    
}


void initialise_program(Prog *program){
    int i;
    program->current_word = (words*)malloc(sizeof(words));
    program->start_coordinate.current_x = WINDOW_WIDTH/2;
    program->start_coordinate.current_y = WINDOW_HEIGHT/2;
    
    program->assign = TRUE; 
    strcpy(program->colour, "WHITE");
    program->current_angle = 0;
    program->coordinate = &program->start_coordinate;
    program->polish = (stack*)malloc(sizeof(stack));
    //program->polish->pointer = (polish_list*)malloc(sizeof(polish_list));
    for(i = 0; i < LETTERS; i++){
        program->variable[i] = 0;
    }
   
    program->test = FALSE;
   
    
}

FILE* check_input(Prog *program, int argc, char **argv){
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

int parse(Prog *program){
    
    words *new_word;
    words *previous_word;
    
    program->current_word = &program->start_word;
    //Loop creates a linked list of the program
    while(fscanf(program->file_pointer, "%s", program->current_word->current) != EOF){
        new_word = (words*)malloc(sizeof(words));
        previous_word = program->current_word;
        program->current_word->next = new_word;
        program->current_word = new_word;
        program->current_word->previous = previous_word;
    }
    program->current_word = &program->start_word; //Sets the current word to the beginning of the linked list
  
    if (validate(program) == FALSE){
        return FALSE;
    }
    
    fprintf(stdout, "\nPARSED OK!");
    return TRUE;
}

int validate(Prog *program){
    
    
    if(!strings_match(program->current_word->current, "{")){
        fprintf(stdout, "\nProgram needs to start with '{'");
        return FALSE;
    }
    program->current_word = program->current_word->next;
    if(instrctlst(program) == FALSE){
        return FALSE;
    }
    return TRUE;
}

int instrctlst(Prog *program){
    if(strings_match(program->current_word->current, "}")){
        return TRUE;
    }
    if(instruction(program) == TRUE){
        program->current_word = program->current_word->next;
        if (instrctlst(program) == TRUE){
            return TRUE;
        }
    }
    
       
    return FALSE;
}

int instruction(Prog *program){
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
    
    if(if_condition(program) == TRUE){
        return TRUE;
    }
        
    if(program->current_word == NULL){
        fprintf(stdout, "\nProgram needs to end with '}'.");
    }
    else{
        fprintf(stdout, "\nERROR around the word '%s'\n", program->current_word->current);   //NEED TO LOOK HOW TO GIVE END MESSAGE
        program->current_word = program->current_word->next;
    }
    return FALSE;
}

int fd(Prog *program){
    int length, variable_index;
    
    if(!(strings_match(program->current_word->current, "FD"))){
        return FALSE;
    }
    program->current_word = program->current_word->next;
    
    if (varnum(program) == TRUE){
        if (is_var(program) == TRUE){
            variable_index = program->current_word->current[0] - 'A';
            
            length = program->variable[variable_index];
        }
        else{
            length = atoi(program->current_word->current);
        }
        
        program->current_length = length;
        assign_draw(program);
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int lt(Prog *program){
    if(!(strings_match(program->current_word->current, "LT"))){
        return FALSE;
    }
    program->current_word = program->current_word->next;
    if (varnum(program) == TRUE){
        program->current_angle -= atoi(program->current_word->current);
        return TRUE;
    }
    else{
    
        return FALSE;
    }
}

int rt(Prog *program){
    if(!(strings_match(program->current_word->current, "RT"))){
        return FALSE;
    }
    program->current_word = program->current_word->next;
    if (varnum(program) == TRUE){
        program->current_angle += atoi(program->current_word->current);
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int varnum(Prog *program){
    
    if(is_number(program) == TRUE){
        return TRUE;
    }
    else if(is_var(program) == TRUE){
        return TRUE;
    }
    return FALSE;
    
}

int is_number(Prog *program){
    
    int word_length, i, decimal_point = 0;
    //double number;
    word_length = strlen(program->current_word->current);
    if(!isdigit(program->current_word->current[0])){
        if((program->current_word->current[0] != '-') || word_length == 1){
            return FALSE;
        }
    }
    //NEED TO MAKE SURE YOU CAN ONLY HAVE ONE DECIMAL PLACE
    for( i = 1; i < word_length; i++){
        if(!isdigit(program->current_word->current[i])){
            if((program->current_word->current[i] != '.') || decimal_point > 0){
                fprintf(stdout, "\nThe value %s, is not valid with operation %s. Needs to be a number.", program->current_word->current, program->current_word->previous->current);
                return FALSE;
            }
            else{
                decimal_point += 1;
            }
        }
    }
    return TRUE;
}

int is_var(Prog *program){
    
    int word_length;
    word_length = strlen(program->current_word->current);
    if(word_length != 1){
        return FALSE;
    }
    if(isupper(program->current_word->current[0])){
        return TRUE;
    }
    return FALSE;
}

int set(Prog *program){
    //printf("\nIn Set");
    
    if(!(strings_match(program->current_word->current, "SET"))){
        return FALSE;
    }
    program->current_word = program->current_word->next;
    
    if (is_var(program) == TRUE){
        return set_letter(program);
    }
    else if(strings_match(program->current_word->current, "COLOUR")){
        return set_colour(program);    
    }
    else{
        fprintf(stdout, "\nOperation SET needs to be followed by a variable A - Z or word 'COLOUR'\n");
        return FALSE;
    }
    
    
}

int set_letter(Prog *program){
    int variable_index;
    
    variable_index = program->current_word->current[0] - 'A';
    program->current_word = program->current_word->next;
    if(!(strings_match(program->current_word->current, ":="))){
        return FALSE;
    }
    program->current_word = program->current_word->next; 
    if(polish(program) == TRUE){  
        if(strings_match(program->current_word->previous->current, ":=")){        //PROBLEM HERE WITH PREVIOUS WORD
            fprintf(stdout, "\nNeed to enter a nuber of variable to SET a value to.\n");
            return FALSE;
        }
        if(program->assign == TRUE){
            program->variable[variable_index] = program->result;
        }
        return TRUE;
    }
    return FALSE;
}

int set_colour(Prog *program){
    char *colours[COLOUR_CHOICE] = {"RED", "BLUE", "GREEN", "WHITE"};
    int i, found = FALSE;
    program->current_word = program->current_word->next;
    if(!(strings_match(program->current_word->current, ":="))){
        return FALSE;
    }
    program->current_word = program->current_word->next; 
    for(i = 0; i < COLOUR_CHOICE; i++){
        if(strings_match(program->current_word->current, colours[i])){
            
            if(program->assign == TRUE){
                strcpy(program->colour, colours[i]);
            }
            found = TRUE;
        }
    }
    if(found == FALSE){
        fprintf(stdout, "\nThe colour you entered is not valid.\n");
        return FALSE;
    }
    program->current_word = program->current_word->next;
    if(strings_match(program->current_word->current, ";")){
        return TRUE;
    }
    fprintf(stdout, "\nSET command needs to end with ;\n");
    return FALSE;
}

int polish(Prog *program){
    //printf("\nIn Polish");
    int variable_index;
    
    if(strings_match(program->current_word->current, ";")){
        
            program->result = pop(program);
           
            return TRUE;
        
    }
    else if(varnum(program) == TRUE){
        if(is_var(program) == TRUE){
            variable_index = program->current_word->current[0] - 'A';
           
            push(program->polish, program->variable[variable_index]);
        }
        else{
            
            push(program->polish, atof(program->current_word->current));
            
        }
        program->current_word = program->current_word->next;
        return polish(program);
    }
    else if(op(program) == TRUE){
        
        program->current_word = program->current_word->next;
        return polish(program);
    }
    else{
        return FALSE;
    }
}



int op(Prog *program){
    //printf("\nIn Op");
    if(check_stack(program) == FALSE){
    
        fprintf(stdout, "\nAn operation +, -, * or / needs to be preceeded by at least 2 numbers or variables\n");
        return FALSE;
    }
    else if(strings_match(program->current_word->current, "+")){
        return add(program);
    }
    else if(strings_match(program->current_word->current, "-")){
        return subtract(program);
    }
    else if(strings_match(program->current_word->current, "*")){
        return multiply(program);
    }
    else if(strings_match(program->current_word->current, "/")){
        return divide(program);
    }
    else{
        return FALSE;
    }
}

double pop(Prog *program){
    //printf("\nIn Pop");
    double number;
    polish_list *tmp;
    if (program->polish->pointer == NULL){
        return FALSE;   //Should never happen because check stack would be called before this to check stack has numbers, this will just return 0
    }
    number = program->polish->pointer->number;
    tmp = program->polish->pointer->previous;
    free(program->polish->pointer);
    program->polish->pointer = tmp;
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

int add(Prog *program){
    //printf("\nIn Add");
    double one, two, result;
    one = pop(program);
    two = pop(program);
    
    result = one + two;
    push(program->polish, result);
    return TRUE;    
    
}

int subtract(Prog *program){
    double one, two, result;
    one = pop(program);
    two = pop(program);
    
    result = two - one; // if this was other way round and I got a negative number, the line is just smaller not opposite?
    push(program->polish, result);
    return TRUE;  
}

int multiply(Prog *program){
    double one, two, result;
    one = pop(program);
    two = pop(program);
    
   
    result = one * two; 
    
    push(program->polish, result);
    return TRUE;  
}

int divide(Prog *program){
    double one, two, result;
    one = pop(program);
    two = pop(program);
    
    result = two / one; 
    push(program->polish, result);
    return TRUE;  
}  

int check_stack(Prog *program){
    //printf("\nIn Check_stack");
    stack *tmp_stack;
   
    tmp_stack = program->polish;
    
    if(tmp_stack->pointer != NULL && tmp_stack->pointer->previous != NULL){
        return TRUE;
    }
    return FALSE; 
}

int loop(Prog *program){
    
    if(!(strings_match(program->current_word->current, "DO"))){
        //fprintf(stdout,"\nA loop needs to begin with the word DO\n");
        return FALSE;
    }
    program->current_word = program->current_word->next;
    
    if(is_var(program) == FALSE){
        fprintf(stdout,"\nThe word DO needs to be follwed by a variable A - Z\n");
        return FALSE;
    }
    program->loop[letter] = program->current_word->current[0] - 'A';
    program->current_word = program->current_word->next;
    
    if (loop_condition(program) == FALSE){
        return FALSE;
    }
    program->current_word = program->current_word->next;
    
    return perform_loop(program);
} 

int loop_condition(Prog *program){
        
    
    if(!(strings_match(program->current_word->current, "FROM"))){
        fprintf(stdout, "\nThe variable in your loop needs to be followed by the word FROM\n");
        return FALSE;
    }
    program->current_word = program->current_word->next;
    if((program->loop[start] = get_parameter(program)) == -1){
        fprintf(stdout, "\nThe word FROM needs to be follwed by a variable A - Z or a number 0 or above\n");
        return FALSE;
    }
    
    program->current_word = program->current_word->next;
    
    if(!(strings_match(program->current_word->current, "TO"))){
        fprintf(stdout, "\nThe word DO needs to be follwed by a variable A - Z\n");
        return FALSE;
    }
    
    program->current_word = program->current_word->next;
    
    if((program->loop[stop] = get_parameter(program)) == -1){
        fprintf(stdout, "\nThe word TO needs to be follwed by a variable A - Z or a number 0 or above\n");
        return FALSE;
    }
    return TRUE;
}

int perform_loop(Prog *program){
    words *program_marker;
    if(program->loop[start] < 0 || program->loop[stop] < 0){
        fprintf(stdout, "\nA DO loop needs positive values to iterate through.\n");
    }
    if(program->loop[start] > program->loop[stop]){
        fprintf(stdout, "\nThe start of your loop has to be less than the end\n");
        return FALSE;
    }   
    
    program_marker = program->current_word;
    for(int i = program->loop[start]; i <= program->loop[stop] ; i++){
        program->variable[program->loop[letter]] = i;
        program->current_word = program_marker;
        if (validate(program) == FALSE){
            return FALSE;
        }
    }
    return TRUE;
}

int get_parameter(Prog *program){

    if(varnum(program) == TRUE){
        if(is_var(program) == TRUE){
            return program->variable[program->current_word->current[0] - 'A'];
        }
        else{
            return atoi(program->current_word->current);
        }
    }
    else{
        return -1;
    }
}



int if_condition(Prog *program){
    if(!(strings_match(program->current_word->current, "IF"))){
        return FALSE;
    }
    program->current_word = program->current_word->next;
    
    if (is_var(program) == TRUE){
        return if_letter(program);
    }
    else if(strings_match(program->current_word->current, "COLOUR")){
        return if_colour(program);    
    }
    else{
        fprintf(stdout, "\nOperation IF needs to be followed by a variable A - Z\n");
        return FALSE;
    }
}

int if_letter(Prog *program){
    int variable_index_check, variable_index_result;
    double result;
    variable_index_check = program->current_word->current[0] - 'A';
    program->current_word = program->current_word->next;
    if(!(strings_match(program->current_word->current, ":="))){
        return FALSE;
    }
    program->current_word = program->current_word->next; 
    if(varnum(program) == TRUE){ 
        if(is_var(program) == TRUE){
            variable_index_result = program->current_word->current[0] - 'A';
            result = program->variable[variable_index_result];
        }
        else{
            result = atof(program->current_word->current);
        }
    }
    else{
        fprintf(stdout, "\nAn IF statement needs to check a variable against another variable or a number.\n");
        return FALSE;
    }
    if(program->variable[variable_index_check] != result){
        
        program->assign = FALSE;
    }
    
    program->current_word = program->current_word->next;
    if (validate(program) == FALSE){
        return FALSE;
    }
    program->assign = TRUE;
    
    return TRUE; //Parses correctly if the if condition is not met
}

int if_colour(Prog *program){
    char colour[LONGEST_COLOUR];
    program->current_word = program->current_word->next;
    if(!(strings_match(program->current_word->current, ":="))){
        return FALSE;
    }
    program->current_word = program->current_word->next; 
    if(strlen(program->current_word->current) > LONGEST_COLOUR){
        fprintf(stdout, "\n%s is not a valid colour.\n", program->current_word->current);
        return FALSE;
    }
    printf("\nColour in IF statement %s\n", program->current_word->current);
    strcpy(colour, program->current_word->current);
    
    
    if(!strings_match(colour, program->colour)){
        program->assign = FALSE;
    }
    program->current_word = program->current_word->next;
    if (validate(program) == FALSE){
        return FALSE;
    }
    program->assign = TRUE;
    return TRUE; //Parses correctly if the if condition is not met
}

void assign_draw(Prog *program){
    //printf("\nCurrent angle = %d", program->current_angle);
    if(program->assign == TRUE){
    
        draw *new_coordinate;
        new_coordinate = (draw*)malloc(sizeof(draw));
        program->current_angle = make_positive(program->current_angle); //incase current angle has become negative
        //printf("\nCurrent angle = %d", program->current_angle);
        program->coordinate->next = new_coordinate;
        new_coordinate->previous = program->coordinate;
        new_coordinate->current_x = program->coordinate->current_x;
        new_coordinate->current_y = program->coordinate->current_y;
        assign_colour(program);
        program->coordinate = new_coordinate;
        set_new_xy(program);
    }
    
}

void assign_colour(Prog *program){
    if(strings_match(program->colour, "WHITE")){
        program->coordinate->red = 255;
        program->coordinate->green = 255;
        program->coordinate->blue = 255;
    }
    else if(strings_match(program->colour, "RED")){
        program->coordinate->red = 255;
        program->coordinate->green = 0;
        program->coordinate->blue = 0;
    }
    else if(strings_match(program->colour, "GREEN")){
        program->coordinate->red = 0;
        program->coordinate->green = 255;
        program->coordinate->blue = 0;
    }
    else if(strings_match(program->colour, "BLUE")){
        program->coordinate->red = 0;
        program->coordinate->green = 0;
        program->coordinate->blue = 255;
    }
}

void set_new_xy(Prog *program){
    double tmp_angle;
    tmp_angle = DEGTORAD(program->current_angle % 90);
    if(program->current_angle >= 270){
        
        program->coordinate->current_x -= (cos(tmp_angle) * program->current_length);
        program->coordinate->current_y -= (sin(tmp_angle) * program->current_length);
        
    }
    else if(program->current_angle >= 180){
        
        program->coordinate->current_x -= (sin(tmp_angle) * program->current_length);
        program->coordinate->current_y += (cos(tmp_angle) * program->current_length);
        
    }
    else if(program->current_angle >= 90){
        
        program->coordinate->current_x += (cos(tmp_angle) * program->current_length);
        program->coordinate->current_y += (sin(tmp_angle) * program->current_length);
        
    }
    else{
        
        program->coordinate->current_x += (sin(tmp_angle) * program->current_length);
        program->coordinate->current_y -= (cos(tmp_angle) * program->current_length);
        
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


