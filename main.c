#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "functions.h"

generic *genList;
void menu(int op);
void opt(int op);

int main(void)
{
    int op;
    genList = (generic *)malloc(sizeof(generic));
    genList->next = NULL;
    menu(op);
    printf("Volte sempre!!!\n");
    return 0;
}

void menu(int op)
{

    if (op != 0)
        printf("Bem vindo ao sistema de matrícula!!!\n");
    else
        printf("Bem vindo de volta ao menu principal!!!\n");
    printf("Digite 0 para retornar a esse menu!\n");
    printf("Digite 1 para inserir um novo aluno no sistema!\n");
    printf("Digite 2 para buscar um aluno no sistema!\n");
    printf("Digite 3 para ver os aluno!\n");
    printf("Digite 4 para excluir um aluno do sistema!\n");
    printf("Digite 5 para verificar se existem alunos no sistema!\n");
    printf("Digite qualquer outro digito para sair do sistema!\n");
    printf("Digite sua escolha: ");
    scanf("%d", &op);
    opt(op);
}

void opt(int op)
{
    int mat;
    char *t = malloc(50);
    do
    {
        switch (op)
        {
        case 0:
            op = 0;
            menu(op);
            break;
        case 1:
            printf("Insira os dados do aluno: \n");
            insert(genList);

            break;
        case 2:
            printf("Deseja procurar por matricula ou nome? Digite um para matricula ou 0 para nome: ");
            scanf("%d", &op);
            if (op == 1)
            {
                printf("\nDigite o número da matricula desejado: ");
                scanf("%i", &mat);
                findByMat(genList, mat, "0", 0, printMat);
            }
            else
            {
                printf("\nDigite o nome do aluno desejado: ");
                scanf("%s", t);
                findByMat(genList, 0, t, 0, printMat);
            }
            op = 2;
            break;
        case 3:
            printf("Aqui estao todos os alunos!!! \n");
            findAll(genList, printMat);

            break;
        case 4:
            printf("Tenha cuidado matriculas excluidas nao poderao ser recuperadas\n");
            printf("Digite a matricula que deseja excluida: ");
            scanf("%d", &mat);
            removeOne(genList, mat, findByMat);

            break;
        case 5:
            t = (empty(genList) == 1) ? "Nao existem alunos no sistema\n" : "Existem alunos no sistema\n";
            printf("%s", t);

            break;
        default:
            exit(1);
            break;
        }
        printf("Digite %d para continuar o que estava fazendo ou 0 para voltar ao menu principal: ", op);
        scanf("%d", &op);
    } while (op != 9);
}