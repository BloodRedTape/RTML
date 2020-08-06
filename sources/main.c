#include <stdio.h>
#include "utils.h"
#include "parser.h"

int main(int argc, char **argv){
    if (argc == 1)
        error("No input files");
    // to do later
    //pthread_t threads[argc-1];

    for(int i = 1; i<argc; i++){
        parse(*(argv+i));
    }
}