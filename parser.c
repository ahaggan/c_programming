#include "parser.h"

int main(int argc, char **argv){
   	FILE *file_pointer;
    file_pointer = check_input(argc, argv);
    prog program;
    
    int i;
    //test();
    
    initialise_words_array(&program);
    
    if(file_pointer == NULL){
        exit(1);
    }
    i = 0;
    while(fscanf(file_pointer, "%s", program.words[i]) != EOF && i < PROGRAM_LENGTH){
        i++;
    }
    if(i == PROGRAM_LENGTH){
        fprintf(stdout, "\nYour program may be too long for the parser to handle.\n");
    }
    if (validate(&program) == FALSE){
        exit(1);
    }
    fprintf(stdout, "\nPARSED OK!");
    draw_turtle(&program);
    return 0;
}

int validate(prog *program){
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
    if(program->words[program->current_word][0] == '\0'){
        fprintf(stdout, "\nProgram needs to end with '}'.");
    }
    else{
        fprintf(stdout, "\nERROR in the word '%s'", program->words[program->current_word]);   //NEED TO LOOK HOW TO GIVE END MESSAGE
    }
    return FALSE;
}

int fd(prog *program){
    if(!(strings_match(program->words[program->current_word], "FD"))){
        return FALSE;
    }
    program->current_word += 1;
    
    if (varnum(program) == TRUE){
        program->current_length = atoi(program->words[program->current_word]);
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
    program->current_angle = make_positive(program->current_angle); //incase current angle has become negative
    program->current_angle = program->current_angle % 360; //incase turtle has rotated more than 360 degrees
    set_new_xy(program);
    program->draw[program->draw_pointer] = program->current_x;
    program->draw_pointer += 1;
    program->draw[program->draw_pointer] = program->current_y;
    program->draw_pointer += 1;
}

void set_new_xy(prog *program){
    int tmp_angle;
    tmp_angle = program->current_angle % 90;
    if(program->current_angle >= 270){
        printf("\nGreater than 270");
        program->current_x -= (cos(tmp_angle) * program->current_length);
        program->current_y -= (sin(tmp_angle) * program->current_length);
    }
    else if(program->current_angle >= 180){
        printf("\nGreater than 180");
        program->current_x -= (sin(tmp_angle) * program->current_length);
        program->current_y += (cos(tmp_angle) * program->current_length);
    }
    else if(program->current_angle >= 90){
        printf("\nGreater than 90");
        program->current_x += (cos(tmp_angle) * program->current_length);
        program->current_y += (sin(tmp_angle) * program->current_length);
    }
    else{
        printf("\nGreater than 0");
        printf("\nCurrent angle: %d", program->current_angle);
        printf("\nCurrent x: %d", program->current_x);
        printf("\nCurrent y: %d", program->current_y);
        program->current_x += (sin(tmp_angle) * program->current_length);
        program->current_y -= (cos(tmp_angle) * program->current_length);
        printf("\nCurrent x: %d", program->current_x);
        printf("\nCurrent y: %d", program->current_y);
    }
}

int make_positive(int angle){
    if(angle >= 0){
        return angle;
    }
    else{
        return make_positive(angle+360);
    }
}

int varnum(prog *program){
    int number;
    number = atoi(program->words[program->current_word]);
    if(number == 0){
        fprintf(stdout, "\nThe value %s, is not valid with operation %s. Needs to be a whole number above 1", program->words[program->current_word], program->words[program->current_word - 1]);
        return FALSE;
    }
    return TRUE;
}
void initialise_words_array(prog *program){
    program->current_word = 0;
    program->current_x = WINDOW_WIDTH/2;;
    program->current_y = WINDOW_HEIGHT/2;
    program->current_angle = 0;
    program->draw_pointer = 2;
    //Sets the first letter of each word to the NULL character
    for(int i = 0; i < PROGRAM_LENGTH; i++){
        program->words[i][0] = '\0';
        program->draw[i] = -1;
    }
    //Sets the start points for the turtle
    program->draw[0] = WINDOW_WIDTH/2;
    program->draw[1] = WINDOW_HEIGHT/2;
}

FILE* check_input(int argc, char **argv){
    FILE *file_pointer;
    
    if(!(argc == 2 || argc == 3)){
        fprintf(stdout, "\nYou must enter 2 or 3 commands:\n   the first should be the executable file,\n   the second should be the text file to read from,\n   the third, if wanted should be the word 'test' this will run the test function");
        return NULL;
    }
    if(argc == 3){
    	if(!(strings_match(argv[2], "test"))){
    		fprintf(stdout, "\nYour 3rd input needs to be the word 'test', if used at all.");
    		return NULL;
    	}
    	
    }
    if((file_pointer = fopen(argv[1], "r")) == NULL){
        fprintf(stdout, "\nCan't open the file you have specified");
        return NULL;
    }
    return file_pointer;
}
