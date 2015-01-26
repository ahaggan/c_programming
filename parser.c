#include "parser.h"

int main(int argc, char **argv){
   	FILE *file_pointer;
    Prog program;
    
    initialise_words_array(&program);
    
    file_pointer = check_input(&program, argc, argv);
    program.file_pointer = file_pointer;
    if(parse(&program) == TRUE){
        draw_turtle(&program);
    }
    
}

int parse(Prog *program){
    
    words *new_word;
    words *previous_word;
    if(program->file_pointer == NULL){
        if(program->test == TRUE){
            test();
            return TRUE;
        }
        return FALSE;
    }
    
    program->current_word = &program->start_word;
    //printf("\nWORD: %s\n", fscanf(program->file_pointer, "%s", program->current_word->current));
    while(fscanf(program->file_pointer, "%s", program->current_word->current) != EOF){
        new_word = (words*)malloc(sizeof(words));
        previous_word = program->current_word;
        program->current_word->next = new_word;
        program->current_word = new_word;
        program->current_word->previous = previous_word;
    }
    /*if(i == PROGRAM_LENGTH){
        fprintf(stdout, "\nYour program may be too long for the parser to handle.\n");
    }*/
    program->current_word = &program->start_word;
    while(program->current_word->current != NULL){
        printf("\nCurrent word: %s", program->current_word->current);
        program->current_word = program->current_word->next;
    }
    if (validate(program) == FALSE){
        return FALSE;
    }
    
    
    fprintf(stdout, "\nPARSED OK!");
    return TRUE;
}

int validate(Prog *program){
    //printf("\nIn validate");
    program->current_word = &program->start_word;
    for(int i = 0; i < LETTERS; i++){
        //printf("\nLetter: %lf", program->variable[i]);   
    }
    if(!strings_match(program->current_word->current, "{")){
        fprintf(stdout, "\nProgram needs to start with '{'");
        return FALSE;
    }
    program->current_word = program->current_word->next;
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
    
    
    if(program->current_word == NULL){
        fprintf(stdout, "\nProgram needs to end with '}'.");
    }
    else{
//Not sure wether to include this error
        fprintf(stdout, "\nERROR around the word '%s'", program->current_word->current);   //NEED TO LOOK HOW TO GIVE END MESSAGE
        program->current_word = program->current_word->next;
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
    
    if(!(strings_match(program->current_word->current, "{"))){
        fprintf(stdout,"\nThe condition statement in a loop needs to end with a {\n");
        return FALSE;
    }
    
    return perform_loop(program);
} 

int loop_condition(Prog *program){
    if(!(strings_match(program->current_word->current, "FROM"))){
        fprintf(stdout, "\nThe variable in your loop needs to be followed by the word FROM\n");
        return FALSE;
    }
    program->current_word = program->current_word->next;
    if((program->loop[start] = get_parameter(program)) == -1){
        fprintf(stdout, "\nThe word FROM needs to be follwed by a variable A - Z or a number\n");
        return FALSE;
    }
    
    
    program->current_word = program->current_word->next;
    
    if(!(strings_match(program->current_word->current, "TO"))){
        fprintf(stdout, "\nThe word DO needs to be follwed by a variable A - Z\n");
        return FALSE;
    }
    
    program->current_word = program->current_word->next;
    
    if((program->loop[stop] = get_parameter(program)) == -1){
        fprintf(stdout, "\nThe word TO needs to be follwed by a variable A - Z or a number\n");
        return FALSE;
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

int perform_loop(Prog *program){
    words *program_marker;
    int i;
    if(program->loop[start] > program->loop[stop]){
        fprintf(stdout, "\nThe start of your loop has to be less than the end\n");
        return FALSE;
    }
    
   
    program->current_word = program->current_word->next;
    program_marker = program->current_word;
    for(i = program->loop[start]; i <= program->loop[stop] ; i++){
        program->variable[program->loop[letter]] = i;
        program->current_word = program_marker;
        if (instrctlst(program) == FALSE){
            return FALSE;
        }
    }
    return TRUE;
}

    
int set(Prog *program){
    //printf("\nIn Set");
    int variable_index;
    if(!(strings_match(program->current_word->current, "SET"))){
        return FALSE;
    }
    program->current_word = program->current_word->next;
    
    if (is_var(program) == FALSE){
        fprintf(stdout, "\nOperation SET needs to be followed by a variable A - Z\n");
        return FALSE;
    }
    
    variable_index = program->current_word->current[0] - 'A';
    //printf("\nVariable_index = %d", variable_index); 
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
            program->variable[variable_index] = program->result;
        return TRUE;
    }
    return FALSE;
}

int polish(Prog *program){
    //printf("\nIn Polish");
    int variable_index;
    
    if(strings_match(program->current_word->current, ";")){
        
            program->result = pop(program->polish);
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

double pop(stack *tmp_pointer){
    //printf("\nIn Pop");
    double number;
    if (tmp_pointer->pointer == NULL){
        return FALSE;
    }
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

int add(Prog *program){
    //printf("\nIn Add");
    double one, two, result;
    one = pop(program->polish);
    two = pop(program->polish);
    
    result = one + two;
    push(program->polish, result);
    return TRUE;    
    
}

int subtract(Prog *program){
    double one, two, result;
    one = pop(program->polish);
    two = pop(program->polish);
    
    result = two - one; // if this was other way round and I got a negative number, the line is just smaller not opposite?
    push(program->polish, result);
    return TRUE;  
}

int multiply(Prog *program){
    double one, two, result;
    one = pop(program->polish);
    two = pop(program->polish);
    
   
    result = one * two; 
    
    push(program->polish, result);
    return TRUE;  
}

int divide(Prog *program){
    double one, two, result;
    one = pop(program->polish);
    two = pop(program->polish);
    
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

void assign_draw(Prog *program){
    //printf("\nCurrent angle = %d", program->current_angle);
    draw *new_coordinate;
    new_coordinate = (draw*)malloc(sizeof(draw));
    program->current_angle = make_positive(program->current_angle); //incase current angle has become negative
    //printf("\nCurrent angle = %d", program->current_angle);
    program->coordinate->next = new_coordinate;
    new_coordinate->previous = program->coordinate;
    new_coordinate->current_x = program->coordinate->current_x;
    new_coordinate->current_y = program->coordinate->current_y;
    program->coordinate = new_coordinate;
    set_new_xy(program);
    
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
    
    int word_length, i;
    //double number;
    word_length = strlen(program->current_word->current);
    if(!isdigit(program->current_word->current[0]) && program->current_word->current[0] != '-'){
        
        return FALSE;
    }
    //NEED TO MAKE SURE YOU CAN ONLY HAVE ONE DECIMAL PLACE
    for( i = 1; i < word_length; i++){
        if(!isdigit(program->current_word->current[i]) && program->current_word->current[i] != '.'){
            fprintf(stdout, "\nThe value %s, is not valid with operation %s. Needs to be a whole number at least 0", program->current_word->current, program->current_word->previous->current);
            return FALSE;
        }
    }
    /*
    number = atof(program->words[program->current_word]);
    
    if(number == 0){
        fprintf(stdout, "\nThe value %s, is not valid with operation %s. Needs to be a whole number above 1", program->words[program->current_word], program->words[program->current_word - 1]);
        return FALSE;
    }
    */
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

void initialise_words_array(Prog *program){
    
    program->current_word = (words*)malloc(sizeof(words));
    program->start_coordinate.current_x = WINDOW_WIDTH/2;;
    program->start_coordinate.current_y = WINDOW_HEIGHT/2;
    program->current_angle = 0;
    program->coordinate = &program->start_coordinate;
    program->polish = (stack*)malloc(sizeof(stack));
    program->polish->pointer = (polish_list*)malloc(sizeof(polish_list));
    memset(program->variable, 0, LETTERS);
   
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
