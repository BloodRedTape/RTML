#ifdef __unix__
    #define _GNU_SOURCE
#endif
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "parser.h"
#include "utils.h"
#include "expressions.h"

int parse_unit(const struct ParseProps *props,char *filename){
    char filename_out[strlen(filename)+1];
    memcpy(filename_out,filename,sizeof_array(filename_out));
    replace_extension("txt",filename_out);

    FILE *file_out = fopen(filename_out,"wb");
    if(file_out==NULL)
        error_f("Can't open %s file",filename_out);
    
    return parse_file(props,filename,file_out);
}

int parse_file(const struct ParseProps *props,char *filename,FILE *file_out){
    FILE* file_in = fopen(filename,"rb");
    if(file_in == NULL)
        error_f("Can't open %s file",filename);
    char *buffer;
    size_t buffer_size = 0;
    ssize_t string_size;
    while((string_size = getline(&buffer,&buffer_size,file_in))!=-1){
        parse_line(props,buffer,file_out);
    }
    free(buffer);
    return 0;
}

int parse_line(const struct ParseProps *props,char *line,FILE *file_out){
    while(*line != 0){
        if(*line==props->pragma){   
            // add expression size without pragma char
            line += parse_expression(props,++line,file_out);
            continue;
            
        }
        if(*line==props->shield_char && *(line+1)==props->pragma){
            ++line;
        }

        putc(*line,file_out);
        ++line;
    }
}

int parse_expression(const struct ParseProps *props, char* begin, FILE *file_out){
    int expr_size = word_size(begin);
    char expr[expr_size+1];
    expr[expr_size]=0;
    memcpy(expr,begin,expr_size);

    if(!strncmp(expr,props->single_line_comment,strlen(props->single_line_comment)))
        return comment(props,begin,file_out);
    if(!strncmp(expr,props->include_directive,expr_size))
        return include(props,begin,file_out);
    error_f(" wrong directive: %s",expr);
    return expr_size;
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