#include <stdio.h> 
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>

int toInt(char * digit) {

    int number = *digit - '0';
    return number;
}

void erroMessage(){
    printf("[!] Valores inválidos! Tente novamente\n");
}

void ordemMatriz(int *linhas, int *colunas){
    char l_input, c_input;
    int test = 0, loop = 1;

    do
    {
        printf("[*] Linhas: ");
        _flushall();
        scanf("%c",&l_input);

        printf("[*] Colunas: ");
        _flushall();
        scanf("%c",&c_input);

        if(isalpha(l_input) || isalpha(c_input)){
            erroMessage();
            test++;
        
        }else if(ispunct(l_input) || ispunct(c_input)){
            erroMessage();
            test++;
        
        }else if(isdigit(l_input) || isdigit(c_input)){
            *linhas = toInt(&l_input);
            *colunas = toInt(&c_input);

            if(*linhas <= 0 || *colunas <= 0){
                erroMessage();
                test++;
            }
        }


        if(!(test != 0)){
         loop = 0;
        }
        
        test--;

    } while (loop);
    
   

}

int **gerarMatriz(int *linhas, int *colunas, int **matriz){

    matriz =(int **)malloc(*linhas * sizeof(int));

    for(int i = 0; i < *linhas; i++){
        matriz[i] =(int *)malloc(*colunas * sizeof(int));
    }

    printf("\n\n[  MATRIZ GENÉRICA  ]\n");
    for(int i = 0; i < *linhas; i++){
        printf("| ");

        for(int j = 0; j < *colunas; j++){
            printf("a%d%d  ", i + 1, j + 1);
        }

        printf("|\n");
    }

    return matriz;



}

void selectOption(char *opcao){

    do
    {
        printf("\n\n[*] Preencher matriz manualmente?(s/n) ");
        _flushall();
        scanf("%c",opcao);

        if((*opcao != 'S' && *opcao != 's') && (*opcao != 'n' && *opcao != 'N'))
            erroMessage();

        

        switch(*opcao){
            case 'S':
                *opcao = 's';
                break;
            case 'N':
                *opcao = 'n';
                break;

            default:
                break;
        }


    } while ((*opcao != 'S' && *opcao != 's') && (*opcao != 'n' && *opcao != 'N'));
    

}

void preencherMatriz(int **matriz, char *opcao, int *linhas, int *colunas){

    switch(*opcao){
        case 's':
            printf("[*] Preencher Matriz Manualmente\n");
    
            for(int i = 0; i < *linhas; i++){
                for(int j = 0; j < *colunas; j++){

                    printf("    a[%d][%d] = ", i+1, j+1 );
                    scanf("%d", &matriz[i][j]);
                }
            }
            break;

        case 'n':
            printf("[*] Preencher Matriz Automaticmente\n");
            srand(time(NULL));
            int random_number;
            for(int i = 0; i < *linhas; i++){
                for(int j = 0; j < *colunas; j++){

                    printf("   a[%d][%d] = ", i+1, j+1 );
                    random_number = rand() % 12;
                    printf("%d\n", random_number);

                    matriz[i][j] = random_number;
                }
            }
            break;
        
        default:
            break;

    }


    
}

void mostrarMatriz(int **matriz, int *linhas, int *colunas){
    printf("\n\n[    MATRIZ   ]\n");
    for(int i=0; i < *linhas; i++){
        printf("| ");
        for(int j=0; j < * colunas; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("|\n");
    }
}

void classMatriz(int *determinante){

    if(*determinante != 0){
        printf("[+] Classificação: MATRIZ NÃO SINGULAR\n");
    }else{
        printf("[+] Classificação: MATRIZ SINGULAR\n");
    }
}

void calculoDeterminante(int **matriz, int *linhas){
    
    int dPrincipal = 1, 
    dSecundaria = 1, 
    determinante = 0,
    d1, d2, d3, d4, d5, d6;

    
    switch (*linhas){
    //Ordem 1
    case 1:
        printf("[+] Ordem 1 \n");
        printf("[+] Determinante = %d", matriz[0][0]);
        break;
    //Ordem 2
    case 2:
        
        printf("[+] Ordem 2 \n");
        for (int i = 0; i < *linhas; i++){
            // printf("[+] Principal: a[%d][%d] \n", i+1, i+1);
            dPrincipal *= matriz[i][i];
        }

        for (int i = 0; i < *linhas; i++){
            // printf("[+] Secundária: a[%d][%d] \n", i+1, (*linhas -1 -i) + 1);
            dSecundaria *= matriz[i][*linhas -1 -i]; 
        }
        determinante = dPrincipal - dSecundaria;
        printf("[+] Determinante = %d\n", determinante);

        break;
    
    case 3:

        printf("[+] Ordem 3 \n");

        d1 = matriz[0][0] * matriz[1][1] * matriz[2][2];
        d2 = matriz[1][0] * matriz[2][1] * matriz[0][2];
        d3 = matriz[2][0] * matriz[0][1] * matriz[1][2];

        d4 = matriz[2][0] * matriz[1][1] * matriz[0][2];
        d5 = matriz[0][0] * matriz[2][1] * matriz[1][2];
        d6 = matriz[1][0] * matriz[0][1] * matriz[2][2];


        determinante = d1 + d2 + d3 - d4 - d5 - d6;

        printf("[+] Determinante: %d\n", determinante);
        break;



    default:
        break;
    }

    classMatriz(&determinante);

}

void main(){

    char opcao;
    int linhas, colunas;
    int **matriz;


    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("|              MATRIX GENERATOR                 |\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");

    setlocale(LC_ALL,"Portuguese");

    //Ordem da Matriz
    printf("[*] Informe a ordem da matriz: \n");
    ordemMatriz(&linhas, &colunas); 

    printf("[+] Ordem da matriz: %d x %d\n", linhas, colunas);


    //Gerar Matriz
    matriz = gerarMatriz(&linhas, &colunas, matriz);


    //Preencher Matriz Manualmente 

    selectOption(&opcao);

    switch(opcao){
        case 's':
            preencherMatriz(matriz, &opcao, &linhas, &colunas);
            mostrarMatriz(matriz, &linhas, &colunas);
            break;
            
        case 'n':
            preencherMatriz(matriz, &opcao, &linhas, &colunas);
            mostrarMatriz(matriz, &linhas, &colunas);
            break;

        default:
            printf("[-] Algo deu errado!");
            break;
    }


    // Veficar Matriz Quadrada

    if(linhas == colunas){
        printf("\n[+] Matriz quadrada. Calculando determinante...\n");
        sleep(2);
        calculoDeterminante(matriz, &linhas);
    }else{
        printf("\n[+] Matriz não quadrada. Não é possível calcular o determinante\n");
    }
    

    
}