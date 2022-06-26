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

int **gerarMatriz(int *linhas, int *colunas, int **matriz){

    matriz =(int **)malloc(*linhas * sizeof(int));

    for(int i = 0; i < *linhas; i++){
        matriz[i] =(int *)malloc(*colunas * sizeof(int));
    }


    for(int i = 0; i < *linhas; i++){
        printf("|");

        for(int j = 0; j < *colunas; j++){
            printf("a%d%d\t", i + 1, j + 1);
        }

        printf("|\n");
    }

    return matriz;



}

void selectOption(char *opcao){

    do
    {
        printf("[*] Preencher matriz manualmente?(s/n) ");
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

                    printf("a[%d][%d] = ", i+1, j+1 );
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

                    printf("a[%d][%d] = ", i+1, j+1 );
                    random_number = rand() % 100;
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

    for(int i=0; i < *linhas; i++){
        printf("|");
        for(int j=0; j < * colunas; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("|\n");
    }
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

    
}