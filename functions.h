#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
void insert(generic *gen);
generic *findByMat(generic *gen, int mat, char *name, short int validate, void (*callback)(void *));
void findAll(generic *gen, void (*callback)(void *));
void removeOne(generic *gen, int mat, generic *(*callback)(generic *, int, char *, short int, void (*call)(void *)));
void printMat(void *param);
void validateMat(void *param);
int empty(generic *gen);
#endif