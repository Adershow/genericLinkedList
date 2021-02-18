#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "functions.h"

void printMat(void *param)
{
    aluno *data = (aluno *)param;
    printf("Aluno encontrado: \n");
    printf("Matricula: %i\n", data->mat);
    printf("Nome: %s\n", data->name);
}
void validateMat(void *param)
{
    aluno *data = (aluno *)param;
    printf("Essa matricula ja esta cadastrada no sistema, matricula e um parametro unico\n");
    printf("Matricula pertence ao %s\n", data->name);
    printf("Insira uma matricula diferente!!!\n");
    insert(genList);
}
int empty(generic *gen)
{
    if (gen->next == NULL)
        return 1;
    else
        return 0;
}