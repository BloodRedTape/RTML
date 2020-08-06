#ifdef __unix__
    #define _GNU_SOURCE
#endif
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "parser.h"
#include "utils.h"


int parse_unit(const struct ParseProps* props,char *filename){
    char filename_out[strlen(filename)+1];
    memcpy(filename_out,filename,sizeof_array(filename_out));
    replace_extension("txt",filename_out);

    FILE *file_out = fopen(filename_out,"wb");
    if(file_out==NULL)
        error_f("Can't open %s file",filename_out);
    
    return parse_file(props,filename,file_out);
}

int parse_file(const struct ParseProps* props,char *filename,FILE* file_out){
    FILE* file_in = fopen(filename,"rb");
    if(file_in == NULL)
        error_f("Can't open %s file",filename);
    char *buffer;
    size_t buffer_size = 0;
    ssize_t string_size;
    while((string_size = getline(&buffer,&buffer_size,file_in))!=-1){
        printf("%s",buffer);
    }
    free(buffer);
}



void print_props(const struct ParseProps *props){
    printf("pragma:\t\t\t%c\n"
           "brackets open:\t\t%c\n"
           "brackets close:\t\t%c\n"
           "shield char:\t\t%c\n"
           "single line comment:\t%s\n"
           "include directive:\t%s\n"
           "variable directive:\t%s\n",
           props->pragma,
           props->brackets_open,
           props->brackets_close,
           props->shield_char,
           props->single_line_comment,
           props->include_directive,
           props->variable_directive);
}