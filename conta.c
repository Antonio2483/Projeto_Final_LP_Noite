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
    int numeroConta = 0;
    int posicaoVetor = 0;

    printf("Digite o numero da conta \n");
    scanf("%d",&numeroConta);

    posicaoVetor = procurarConta(pConta,posicao,numeroConta);

    while(posicaoVetor != -1){
        printf("O codigo ja existe, digite outro \n");
        scanf("%d",&numeroConta);
        posicaoVetor = procurarConta(pConta,posicao,numeroConta);
    }

    pConta[posicao] ->numero = numeroConta;

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

    pConta[posicao] ->saldo = 60;

    printf("Conta cadastrada com sucesso \n");
    system("pause");

}

void procurar(p_conta pConta[], int tamanho){

}

void alterar(p_conta pConta[], int tamanho){
    int codConta = lerConta();
    int posicao = procurarConta(pConta,tamanho,codConta);

    while(posicao == -1){
        printf("Cliente nao encontrado, digite um codigo valido \n");
        codConta = lerConta();
        posicao = procurarConta(pConta,tamanho,codConta);
    }

    printf("Conta encontrada \n");

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
    int codConta = lerConta();
    int posicao = procurarConta(pConta,tamanho,codConta);
    int deposito = 0;

    while(posicao == -1){
        printf("Cliente nao encontrado, digite um codigo valido \n");
        codConta = lerConta();
        posicao = procurarConta(pConta,tamanho,codConta);
    }

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
    int codConta = lerConta();
    int posicao = procurarConta(pConta,tamanho,codConta);
    int saque = 0;

    while(posicao == -1){
        printf("Cliente nao encontrado, digite um codigo valido \n");
        codConta = lerConta();
        posicao = procurarConta(pConta,tamanho,codConta);
    }

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

void imprimir(p_conta pConta[], int tamanho){
    int codConta = lerConta();
    int posicao = procurarConta(pConta,tamanho,codConta);
    while(posicao == -1){
        printf("Cliente nao encontrado, digite um codigo valido \n");
        codConta = lerConta();
        posicao = procurarConta(pConta,tamanho,codConta);
    }
    imprimirConta(pConta,codConta);
    system("pause");
}

void saldoGeral(p_conta pConta[], int tamanho){
    float saltoGeral = 0;

    for(int i =0; i < tamanho; i++){

        saltoGeral += pConta[i]->saldo;
        // Por algum motivo eu tenho que imprimir a variavel aqui
        // Se não ele quebra no final
        printf("Saldo var depois: %lf \n",saltoGeral);
    }

    printf("O saldo de todas as contas e de: %.2f \n",saldoGeral);
    system("pause");
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

int lerConta(){
    int codConta = 0;
    printf("Digite o numero da conta\n");
    scanf("%d",&codConta);

    return codConta;
}

int procurarConta(p_conta pConta[], int tamanho, int codConta){
    int numeroProcurar = 0;
    int posicao = -1;

    for(int i = 0; i < tamanho; i++){
        if(codConta == pConta[i]->numero){
            posicao = i;
            break;
        }
    }

    return posicao;

}
