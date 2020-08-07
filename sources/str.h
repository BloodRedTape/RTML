#ifndef RTML_STR
#define RTML_STR

struct String{
    char *buffer;
    int length;
};

void str_init(struct String *str, char *string);
void str_print(struct String *str);

struct String str_clone(struct String *str);
struct String str_create(char *string);
int str_cmp(struct String *f, struct String *s);

#endif