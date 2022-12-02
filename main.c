#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

int main()
{
    p_conta vtrContas[1000];
    int p = 0;

    inicializar(vtrContas,1000);

    //montar o menu
    int opcao;
    do{
        system("cls");
        printf("Cadastro de produtos \n");
        printf("1. Cadastrar Conta\n");
        printf("2. Atualizar Conta\n");
        printf("3. Procurar Conta\n");
        printf("4. Listar Contas\n");
        printf("5. Depositar\n");
        printf("6. Sacar\n");
        printf("7. Imprimir Conta\n");
        printf("8. Saldo Geral\n");
        printf("9. Sair \n");
        printf("Digite sua opcao:  \n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                inserir(vtrContas, p);
                p++;
                break;
            case 2:
                //atualizar(vtrProdutos, p);
                break;
            case 3:
                //comprar(vtrProdutos, p);
                break;
            case 4:
                listar(vtrContas, p);
                break;
            case 5:
                depositar(vtrContas, p);
                break;
            case 6:
                sacar(vtrContas, p);
                break;
            case 7:
                //imprimir(vtrProdutos, p);
                break;
            case 8:
                //imprimir(vtrProdutos, p);
                break;
            case 9:
                //printf("Fim do programa \n");
                exit(0);
        }
    }while(opcao!=9);

    return 0;
}
