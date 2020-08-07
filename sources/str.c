#include "str.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"



void str_init(struct String *str, char *string){
    str->length = strlen(string)+1;
    str->buffer = (char *)malloc(str->length * sizeof(char));
    memcpy(str->buffer,string,str->length*sizeof(char));
}

void str_finalize(struct String *str){
    free(str->buffer);
}

void str_print(struct String *str){
    printf("%s\n",str->buffer);
}

struct String str_clone(struct String *string){
    struct String clone;
    clone.length = string->length;
    clone.buffer = (char*)malloc(clone.length*sizeof(char));
    memcpy(clone.buffer,string->buffer,clone.length);
    return clone;
}

struct String str_create(char *string){
    struct String result;
    result.length = strlen(string)+1;
    result.buffer = (char *)malloc(result.length*sizeof(char));
    memcpy(result.buffer,string,result.length*sizeof(char));
    return result;
}

int str_cmp(struct String *f, struct String *s){
    if(strcmp(f->buffer,s->buffer)==0)
        return 1;
    return 0;
}