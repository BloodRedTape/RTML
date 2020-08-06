#include <stdio.h>
#include "utils.h"
#include "parser.h"

int main(int argc, char **argv){
    if (argc == 1)
        error("No input files");
    // to do later
    //pthread_t threads[argc-1];

    const struct ParseProps props={
        .pragma = '#',
        .brackets_open = '\"', //  "  char
        .brackets_close = '\"',//  "  char
        .shield_char = '\\',   //  \  char
        .single_line_comment = "#",
        .include_directive = "include",
        .variable_directive = "set"
    };
    print_props(&props);

    for(int i = 1; i<argc; i++){
        parse_unit(&props,*(argv+i));
    }
}