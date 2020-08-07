#ifndef RTML_REGISTRY_H
#define RTML_REGISTRY_H


#include "str.h"

struct Variable{
    struct String name;
    struct String value;
};

void variable_init(struct Variable *var, char *name, char *value);
void variable_finalize(struct Variable *var);

struct Bucket{
    struct Variable variable;
    struct Bucket *next; 
};

struct Registry{
    struct Bucket **map;
    int capacity;
    int used;
};

void registry_init(struct Registry *reg,int capacity);
void variable_add(struct Registry *reg, char *name, char *value);
void registry_remove(struct Registry *reg, char *key);
void registry_finalize(struct Registry *reg);

void registry_print(struct Registry *reg);

struct Bucket **registry_find_storage(struct Registry *reg, char *key);
struct Bucket *registry_find(struct Registry *reg, char *key);
#endif