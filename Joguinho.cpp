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

//função que inicialisa o jogo
void initialise (char board[][SIDE], int moves[])
{
    //inicia um numero random
    srand(time(NULL));
    //inicia o tabuleiro vazio
    for (int i = 0; i < SIDE; i++)
    {
        /* code */
        for (int j = 0; j < SIDE; j++)
        {
            /* code */
            board[i][j] = ' ';

        }
        
    }
    
    //preenche o tabuleiro com numeros
    for (int i = 0; i < SIDE*SIDE; i++)
    {
        /* code */
        moves[i] = i;
    }

    // torna as jogadas aleatorias
    random_shuffle(moves, moves + SIDE*SIDE);

    return;
}

//declara o vencedor do jogo

void declarewinner (int whoseturn)
{
    if (whoseturn == COMPUTER)
    {
        printf("O Computador Ganhou!\n");
    }
    else
    {
        printf("Tu ganhaste!\n");
    }
     return;
}

// função que retorna um booleano se para as se cruza com as jogadas dos players
bool rowcrossed(char board[][SIDE])
{
    for (int i = 0; i < SIDE; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return(true);
        }
        
    }
    return(false);
}

// funçao se a coluna se cruzam 
bool columncrossed(char board[][SIDE])
{
    for (int i = 0; i < SIDE; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        {
            return(true);
        }
        
    }
    return(false);
}

//função para se a diagonal se cruzarem com a jogada dos players
bool diagonalcrossed(char board[][SIDE])
{
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        {
            return(true);
        }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        {
            return(true);
        }
    return(false);
}

//função que diz se o jogo terminou
bool gameover(char board[][SIDE])
{
    return (rowcrossed(board) || columncrossed(board) || diagonalcrossed(board));
} 

//função par jogar o joguineo
void playvelha(int whoseturn)
{
    // tabuleiro 3x3
    char board [SIDE][SIDE];
    int moves[SIDE*SIDE];
    
    // iniciar o jogo
    initialise(board, moves);

    //chamando a função que mostra as instruçoes
    showinstructions();

    int moveindex = 0, x, y;

    //jogando o jogo

    while (gameover(board) == false && moveindex != SIDE*SIDE)
    {
        if (whoseturn == COMPUTER)
        {
            x = moves[moveindex] / SIDE;
            y = moves[moveindex] % SIDE;
            board [x][y] = COMPUTERMOVE;
            printf("Computador colocou %c no espaço%d\n",COMPUTERMOVE, moves[moveindex]+1);
            showboard(board);
            moveindex++;
            whoseturn = HUMAN;
            
        }
        else if (whoseturn = HUMAN)
        {
            x = moves[moveindex] / SIDE;
            y = moves[moveindex] % SIDE;
            board [x][y] = HUMANMOVE;
            printf("Você colocou %c no espaço%d\n", HUMANMOVE, moves[moveindex]+1);
            showboard(board);
            moveindex++;
            whoseturn = COMPUTER;
        }
        
    }
    //se o jogo empatar
    if (gameover(board) == false && moveindex == SIDE*SIDE)
    {
        printf("Empatou\n");
    }
    //se tiver um vencedor
    else
    {
        if (whoseturn == COMPUTER)
        {
            whoseturn = HUMAN;
        }
        else if (whoseturn == HUMAN)
        {
            whoseturn = COMPUTER;
        }
        
        declarewinner(whoseturn);
        return;    
    }
}

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    playvelha(COMPUTER);
    
    return(0);
}
