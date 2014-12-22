#include "parser.h"

int main(int argc, char **argv){
   /*FILE *file_pointer
    file_pointer = check_input(argc, argv);*/
    test();
}

FILE* check_input(int argc, char **argv){
    FILE *file_pointer;
    if(argc != 2){
        fprintf(stderr, "\nYou must enter 2 commands,\nthe first should be the executable file,\nthe second should be the text file to read from.");
        return NULL;
    }
    if((file_pointer = fopen(argv[1], "r")) == NULL){
        fprintf(stderr, "\nCan't open the file you have specified");
        return NULL;
    }
    return file_pointer;
}
