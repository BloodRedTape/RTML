#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "parser.h"
#include "utils.h"

int parse_file(char *filename){
    FILE *file_in = fopen(filename,"rb");
    if(!file_in)
        error_f("can't open %s file\n",filename);

}