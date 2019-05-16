#include <stdio.h>
#include <stdlib.h>
#include "Set.h"

char **superList;
char **dudList;

char **makeMatrix() {
    char **top = malloc(sizeof(char *) * NUM_WORDS);
    char *body = malloc(sizeof(char) * NUM_WORDS * LONG_WORD);
    int i;
    for (i = 0; i < NUM_WORDS; i++) {
        top[i] = &body[i * LONG_WORD];
    }
    return top;
}

void freeMatrix(char **thing) {
    free(thing[0]);
    free(thing);
}

int main(void) {
    superList = makeMatrix();
    dudList = makeMatrix();

    FILE *fin = fopen("allwords.txt", "r");

    int i;
    for (i = 0; i < NUM_WORDS; i++) {
        fscanf(fin, "%s", superList[i]);
        fscanf(fin, "%s", dudList[i]);
    }
    fclose(fin);

    Set set = initSet(superList);

    int nFailures = 0;
    for (i = 0; i < NUM_WORDS; i++) {
        if (!checkSet(set, superList[i])) nFailures++;
        if (checkSet(set, dudList[i])) nFailures++;
    }

    printf("Failures: %d\n", nFailures);

    freeSet(set);
    freeMatrix(superList);
    freeMatrix(dudList);
    return 0;
}