#ifndef SET_H
#define SET_H

#define NUM_WORDS 25000
#define LONG_WORD 16

typedef struct _SetRep *Set;

Set initSet(char **super_list);
int checkSet(Set s, char *word);
void freeSet(Set s);

#endif