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
