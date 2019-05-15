#include "Set.h"
#include <string.h>
#include <stdlib.h>

struct _SetRep {
    char **words;
};

Set initSet(char **words) {
    Set s = malloc(sizeof(struct _SetRep));
    s->words = words;
    return s;
}

int checkSet(Set s, char *word) {
    int i;
    for (i = 0; i < NUM_WORDS; i++) {
        if (!strcmp(word, s->words[i])) {
            return 1;
        }
    }
    return 0;
}

void freeSet(Set s) {
    free(s);
}