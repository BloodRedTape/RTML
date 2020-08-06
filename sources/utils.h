#ifndef RTML_UTILS_H
#define RTML_UTILS_H

extern int printf (const char *__restrict __format, ...);
extern void exit(int status);
extern int puts(const char *);

#define error_f(msg,...) {printf("[ERROR]:"msg"\n",__VA_ARGS__);exit(-1);}
#define error(msg) {puts("[ERROR]:"msg); exit(-1);}
#define info(msg) {puts("[INFO]:"msg);}

#define sizeof_array(array) (sizeof(array)/sizeof(array[0]))

int replace_extension(const char *to, char* filename_buffer);
//string should be NULL terminated
char *find_last_char(char ch, char *string);

void fllte(char *str, char ch);

//string should be NULL terminated
char *clone_string(char *string);

#endif