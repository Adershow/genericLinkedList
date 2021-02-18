#ifndef STRUCTS_H_
#define STRUCTS_H_
struct Aluno
{
    int mat;
    char name[50];
};
struct Generic
{
    void *data;
    struct Generic *next;
};
typedef struct Aluno aluno;
typedef struct Generic generic;
extern generic *genList;
#endif
