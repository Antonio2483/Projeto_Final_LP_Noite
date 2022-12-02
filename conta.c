#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

struct Conta{
    int numero;
    char cliente[51];
    int especial;
    float saldo;
};

void inicializar(p_conta pConta[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        pConta[i] = NULL;
    }
}

void inserir(p_conta pConta[], int posicao){

    pConta[posicao] = (p_conta) malloc(sizeof(struct Conta));

    printf("Digite o numero da conta \n");
    scanf("%d",&pConta[posicao] ->numero);

    fflush(stdin);
    printf("Digite o nome do cliente \n");
    gets(pConta[posicao] ->cliente);

    printf("Informe se a conta e especial(0 para conta normal 1 para especial) \n");
    int especialInt = 0;
    scanf("%d",&especialInt);

    while(especialInt !=1 && especialInt != 0){
        printf("valor incorreto, Digite 1 Para conta especial e 0 para conta comum \n");
        scanf("%d",&especialInt);
    };

    pConta[posicao] ->especial = especialInt;

    pConta[posicao] ->saldo = 0;

    printf("Conta cadastrada com sucesso \n");
    system("pause");

}

void listar(p_conta pConta[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("\n");
        imprimirConta(pConta,i);
        printf("-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    }
    system("pause");
}

void depositar(p_conta pConta[], int tamanho){
    int posicao = procurarConta(pConta,tamanho);
    int deposito = 0;

    printf("Conta do cliente: %s \n", pConta[posicao]->cliente);

    while(1){
        printf("Digite o valor para o deposito \n");
        scanf("%d",&deposito);

        if(deposito <= 0){
            printf("Digite um valor valido para o deposito \n");
            continue;
        }else{
            pConta[posicao] ->saldo += deposito;
            printf("Deposito efetuado com sucesso \n");
            system("pause");
            return;
        }
    }
}

void sacar(p_conta pConta[], int tamanho){
    int posicao = procurarConta(pConta,tamanho);
    int saque = 0;

    printf("Conta do cliente: %s \n", pConta[posicao]->cliente);

    while(1){
        printf("Digite o valor para o saque \n");
        scanf("%d",&saque);

        if(saque <= 0){
            printf("Digite um valor valido para o Saque \n");
            continue;
        }else{
            pConta[posicao] ->saldo -= saque;
            printf("Saque efetuado com sucesso \n");
            system("pause");
            return;
        }
    }
}

void imprimirConta(p_conta const *pConta, int i) {
    printf("Numero: %d \n", pConta[i]->numero);
    printf("Cliente: %s \n", pConta[i]->cliente);
    if(pConta[i]->especial == 1){
        printf("Especial: Sim \n");
    }else{
        printf("Especial: Nao \n");
    }
    printf("Saldo: %.2f \n", pConta[i]->saldo);
}

int procurarConta(p_conta pConta[], int tamanho){
    int numeroProcurar = 0;
    int posicao = -1;

    while(posicao == -1){
        printf("Digite o numero da conta\n");
        scanf("%d",&numeroProcurar);

        for(int i = 0; i < tamanho; i++){
            if(numeroProcurar == pConta[i]->numero){
            return i;
            }
        }
        printf("Codigo nao encontrado digite novamente \n");
    }
}
