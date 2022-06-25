#include <stdio.h> 
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

int toInt(char * digit) {

    int number = *digit - '0';
    return number;
}

void erroMessage(){
    printf("[!] Valores inválidos! Tente novamente\n\n");
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

void gerarMatriz(int *linhas, int *colunas, float **matriz){

    matriz = (float **)malloc(*linhas * sizeof(float));

    for(int i = 0; i < *linhas; i++){
        matriz[i] = (float *)malloc(*colunas * sizeof(float));
    }


    for(int i = 0; i < *linhas; i++){
        printf("|");

        for(int j = 0; j < *colunas; j++){
            printf("a%d%d\t", i + 1, j + 1);
        }

        printf("|\n");
    }



}


void main(){

    
    int linhas, colunas;
    float **matriz;

    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("|              MATRIX GENERATOR                 |\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");

    setlocale(LC_ALL,"Portuguese");

    //Ordem da Matriz
    printf("[*] Informe a ordem da matriz: \n");
    ordemMatriz(&linhas, &colunas); 

    printf("[+] Ordem da matriz: %d x %d\n", linhas, colunas);


    //Gerar Matriz
    gerarMatriz(&linhas, &colunas, matriz);
    
}