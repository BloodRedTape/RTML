#ifndef RTML_PARSER_H
#define RTML_PARSER_H

struct ParseProps{
    char pragma;
    char brackets_open;
    char brackets_close;
    char shield_char;
    char *single_line_comment;
    char *include_directive;
    char *variable_directive;
};

int parse_unit(const struct ParseProps* props,char *filename);

int parse_file(const struct ParseProps* props,char *filename, FILE* file_out);

int parse_line(const struct ParseProps* props,char *line,FILE* file_out);


void print_props(const struct ParseProps* props);

#endif