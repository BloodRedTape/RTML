#include "registry.h"
#include "str.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
static long hash(struct Registry *reg, char *k);

void variable_init(struct Variable *var, char *name, char *value){
    str_init(&var->name,name);
    str_init(&var->value,value);
}
void variable_finalize(struct Variable *var){
    str_finalize(&var->name);
    str_finalize(&var->value);
}


void registry_init(struct Registry *reg,int capacity){
    reg->capacity = capacity;
    reg->used = 0;
    reg->map = (struct Bucket **)malloc(sizeof(struct Bucket *) * reg->capacity);
    memset(reg->map,0,reg->capacity);
}
void variable_add(struct Registry *reg, char *name, char *value){
    struct Bucket **bkt = reg->map+hash(reg,name);
    while(*bkt!=NULL)
        bkt = &((*bkt)->next);
    *bkt = (struct Bucket *)malloc(sizeof(struct Bucket));
    (*bkt)->next = NULL;
    str_init(&(*bkt)->variable.name,name);
    str_init(&(*bkt)->variable.value,value);
}
void registry_remove(struct Registry *reg, char *key){
    struct Bucket **bkt = registry_find_storage(reg,key);
    struct Bucket *rm = *(bkt);
    *bkt = (*bkt)->next;
    free(rm);
}
void registry_finalize(struct Registry *reg){
    for(int i = 0; i<reg->capacity; i++){
        struct Bucket *prev, *bkt = *(reg->map+i);
        while(bkt!=NULL){
            prev = bkt;
            bkt = bkt->next;
            free(prev);
        }
    }
    free(reg->map);
}

void registry_print(struct Registry *reg){
    puts("REG");
    for(int i = 0; i<reg->capacity; i++){
        printf("%p\t|",*(reg->map + i));
        struct Bucket *bkt = *(reg->map+i);
        while(bkt!=NULL){
            printf("key:%s value:%s | ",bkt->variable.name.buffer,bkt->variable.value.buffer);
            bkt = bkt->next;
        }
        printf("\n");
    }
    puts("END");
}

static long hash(struct Registry *reg, char *k){
    unsigned long hash = 5381;
    int c;
    while (c = *k++)
        hash = ((hash << 5) + hash) + c;
    hash%=reg->capacity;
    return hash;
}

struct Bucket **registry_find_storage(struct Registry *reg, char *key){
    struct Bucket **bkt = reg->map+hash(reg,key);
    while(*bkt!=NULL){
        if(strcmp((*bkt)->variable.name.buffer,key)==0)
            return bkt;
        bkt = &((*bkt)->next);
    }
    return bkt;
}
struct Bucket *registry_find(struct Registry *reg, char *key){
    return *registry_find_storage(reg,key);
}

