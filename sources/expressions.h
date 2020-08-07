#ifndef RTML_EXPRESSIONS_H
#define RTML_EXPRESSIONS_H

#include "parser.h"

int comment(const struct ParseProps *props,char *begin, FILE *file_out);
int include(const struct ParseProps *props,char *begin, FILE *file_out);
#endif