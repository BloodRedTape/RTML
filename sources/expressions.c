#include "utils.h"
#include "expressions.h"
#include "stdio.h"
#include "parser.h"
#include "string.h"

int comment(const struct ParseProps *props,char *expression, FILE *file_out){
    return line_length(expression);
}

int include(const struct ParseProps *props,char *expression, FILE *file_out){
    char * begin, *end;
    begin = find_first_char(props->brackets_open,expression)+1;
    if(!begin)
        error_f(" %c%s pragma is not complete\nmissed string argument: %s",props->pragma,props->include_directive,expression);
    end = find_first_char(props->brackets_close,begin);
    if(!end)
        error_f(" %c%s pragma is not complete\nmissed closing brackets: %s",props->pragma,props->include_directive,expression);
    if((end-begin)==0)
        error_f(" %c%s pragma is not complete\nprovided empty string: %s",props->pragma,props->include_directive,expression);
    *end = 0;
    parse_file(props,begin,file_out);
    return (int)(end-expression);
}