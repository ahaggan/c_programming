#include "parser.h"

int main(int argc, char **argv){
   	//FILE *file_pointer;
    //file_pointer = check_input(argc, argv);
    test();
}

FILE* check_input(int argc, char **argv){
    FILE *file_pointer;
    
    if(!(argc == 2 || argc == 3)){
        fprintf(stderr, "\nYou must enter 2 or 3 commands:\n   the first should be the executable file,\n   the second should be the text file to read from,\n   the third, if wanted should be the word 'test' this will run the test function");
        return NULL;
    }
    if(argc == 3){
    	if(!(strings_match(argv[2], "test"))){
    		fprintf(stderr, "\nYour 3rd input needs to be the word 'test', if used at all.");
    		return NULL;
    	}
    }
    if((file_pointer = fopen(argv[1], "r")) == NULL){
        fprintf(stderr, "\nCan't open the file you have specified");
        return NULL;
    }
    return file_pointer;
}
