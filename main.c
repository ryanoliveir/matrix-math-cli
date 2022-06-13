#include <stdio.h> 
#include <stdlib.h>
#include <locale.h>

void main(){



    int linhas,
    colunas,
    length;

    float valor;

    char option;

    
    printf("%s\n",setlocale(LC_ALL, "Portuguese"));

    printf("+++++++++++++++++++++++++++++++++++++++++\n");
    printf("|             MATRIZ GENERATOR           |\n");
    printf("+++++++++++++++++++++++++++++++++++++++++\n");


    do
    {
        
        printf("[*] Informe a dimenùùo da matriz: \n");

        printf("[*] Linhas: ");
        scanf("%d", &linhas);

        printf("[*] Colunas: ");
        scanf("%d", &colunas);

        if(linhas <= 0 || colunas <= 0)
            printf("[-] Informe valores vùlidos! Tentente novamente...\n\n");

    } while (linhas <= 0 || colunas <= 0);
    
    printf("\n[Gerando matriz...]\n");

    float matriz[linhas][colunas];
    //length = linhas * colunas;
    // mostrando matriz
    printf("[Mostrando Matriz...]\n\n");

    for (int i = 0; i < linhas; i++){
        printf("|");
        for(int j = 0; j < colunas; j++){
            printf("a%d%d\t", i + 1, j + 1);
        }
        printf("|\n");
    }   

    


    //Preenchimento da matriz

    do
    {
        printf("\n[?] Preencher matriz manualmente?(s/n): ");
        _flushall();
        scanf("%c", &option);
        
        if((option != 'n') && (option != 's'))
            printf("[!] ERRO: Infomre uma opùùo vùlida! Tente novamente!\n");

    } while ((option != 'n') && (option != 's'));
    

    switch (option)
    {
    case 'n' :
        break;
    
    case 's':
        
        printf("\n[*] Preencher Matriz\n");
        printf("[*] Forneùa os valores para cada posiùùo: \n");


        for(int i = 0; i < linhas; i++){

            for(int j = 0; j < colunas; j++){
                printf("    a[%d][%d] = ", i + 1, j + 1);
                scanf("%f", &valor);

                matriz[i][j] = valor;
            }

        }

        printf("\n[Mostrando Matriz...]\n\n");

    for (int i = 0; i < linhas; i++){
        printf("|\t");
        for(int j = 0; j < colunas; j++){
            printf("%.0f\t", matriz[i][j]);
        }
        printf("|\n");
    }   

    

    default:
        break;
    }
}