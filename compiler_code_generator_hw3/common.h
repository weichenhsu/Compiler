#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scope, scope_com, address, lineno;
char *print_type;

/* struct ... */
struct table{
    int index;
    char *name;
    char *type;
    int address;
    int lineno;
    char *element_type;
    int scope_level;
    struct table *next;
    struct table *prev_head;
    struct table *prev;
};

struct table *head, *current, *current_head;


#endif /* COMMON_H */