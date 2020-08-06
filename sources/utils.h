#ifndef RTML_UTILS_H
#define RTML_UTILS_H

extern int printf (const char *__restrict __format, ...);
extern void exit(int status);


#define error_f(msg,...) {printf("[ERROR]:"msg,__VA_ARGS__);exit(-1);}
#define error(msg) {puts("[ERROR]:"msg); exit(-1);}

#endif