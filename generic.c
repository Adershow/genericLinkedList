#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "functions.h"

void insert(generic *gen)
{
    aluno *al = (aluno *)malloc(sizeof(aluno));
    generic *new = (generic *)malloc(sizeof(generic));
    char name[50];
    int mat;

    printf("Digite o nome do aluno: ");
    scanf("%s", name);
    printf("Digite a matricula do aluno: ");
    scanf("%i", &mat);
    al->mat = mat;
    strcpy(al->name, name);

    new->data = al;
    if (empty(gen))
    {
        gen->next = new;
    }
    else
    {
        aluno *al;
        generic *tmp = gen;
        findByMat(tmp, mat, "0", 1, validateMat);
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
}
generic *findByMat(generic *gen, int mat, char *name, short int validate, void (*callback)(void *))
{
    if (empty(gen))
    {
        printf("A lista está vazia\n");
        return NULL;
    }
    generic *aux1 = gen->next;
    aluno *aux = (aluno *)aux1->data;
    short int flag = 0;

    if (aux->mat == mat && mat != 0)
        callback(aux);
    else
    {
        aux1 = gen;
        while (aux1->next != NULL)
        {
            aux1 = aux1->next;
            aux = (aluno *)aux1->data;
            if ((aux->mat == mat && mat != 0) || (strcmp(name, "0") != 0 && strcmp(aux->name, name) == 0))
            {
                callback(aux);
                flag = 1;
                if (strcmp(name, "0") == 0)
                    break;
            }
        }
        if (flag != 1 && validate == 0)
        {
            printf("Registro não encontrado!!!\n");
            return NULL;
        }
    }
    return aux1;
}
void findAll(generic *gen, void (*callback)(void *))
{
    if (empty(gen))
    {
        printf("A lista está vazia\n");
        return;
    }
    aluno *aux;
    generic *aux1 = gen->next;
    while (aux1 != NULL)
    {
        aux = (aluno *)aux1->data;
        callback(aux);
        aux1 = aux1->next;
    }
}
void removeOne(generic *gen, int mat, generic *(*callback)(generic *, int, char *, short int, void (*call)(void *)))
{
    int op;
    generic *aux = callback(gen, mat, "0", 0, printMat);
    if (aux == NULL)
        return;

    printf("Deseja mesmo excluir a matricula assima? Digite 1 caso sim ou 0 caso nao: ");
    scanf("%d", &op);
    if (op == 0)
        return;

    generic *tmp = gen;
    if (tmp->next == aux)
    {
        tmp = aux->next;
    }
    else
    {
        while (tmp->next != NULL)
        {
            if (tmp->next == aux && aux->next != NULL)
            {
                tmp->next = aux->next;
                break;
            }
            else if (tmp->next == aux && aux->next == NULL)
            {
                tmp->next = NULL;
                break;
            }
            tmp = tmp->next;
        }
    }
    free(aux);
    findAll(gen, printMat);
}