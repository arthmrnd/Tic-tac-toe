#include<bits/stdc++.h>
#include<locale.h>
using namespace std;

// define os players
#define COMPUTER 1
#define HUMAN 2

#define SIDE 3 // tamanho do tabuleiro

//computer irá usar o 'O'
#define COMPUTERMOVE 'O'
//humano irá usar o 'x'
#define HUMANMOVE 'X'

//função para mostrar o tabuleiro
void showboard (char board[][SIDE])
{
    printf("\n\n");
    printf("\t\t\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t\t\t----------------\n");
    printf("\t\t\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t\t\t----------------\n");
    printf("\t\t\t %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    return;
}

//Uma função para mostrar as instruções
void showinstructions ()
{
    setlocale(LC_ALL, "Portuguese");
    printf("\t\t\t Jogo da Velha\n\n");
    printf("Escolha o espaço de 1 a 9 no tabuleiro abaixo\n\n");
    printf("\t\t\t 1 | 2 | 3 \n");
    printf("\t\t\t----------------\n");
    printf("\t\t\t 4 | 5 | 6 \n");
    printf("\t\t\t----------------\n");
    printf("\t\t\t 7 | 8 | 9 \n");
    printf("\t\t\t----------------\n");

    printf("\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-n\n");

    return;
}

