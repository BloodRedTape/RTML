#include "utils.h"
#include "stddef.h"
#include "string.h"
#include "stdlib.h"

int replace_extension(const char *to, char* filename){
    char *extension_start = find_last_char('.',filename);
    size_t to_size = strlen(to);
    if(!extension_start){
        info("no extension found");
        return -1;
    }
    if(strlen(extension_start)<to_size){
        info("filename buffer is too small");
        return -1;
    }
    memcpy(++extension_start,to,(to_size)*sizeof(char));
    fllte(extension_start+to_size,0);
    return 0;
}

char *find_last_char(char ch, char *string){
    char *result = NULL;
    while(*string!=0){
        if(*string == ch)
            result = string;
        string++;
    }
    return result;
}

void fllte(char *string,char ch){
    while(*string!=0){
        *string = ch;
        string++;
    }
}

char *clone_string(char *string){
    size_t length = strlen(string)+1;
    char *clone = (char *)malloc(length*sizeof(char));
    memcpy(clone,string,length);
    return clone;
}