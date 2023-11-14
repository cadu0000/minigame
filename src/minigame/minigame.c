#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

#define MAX_ENEMIES 10

typedef struct Board {
    int rows;
    int cols;
    char** board;
} Board;

typedef struct Player {
    int horizontalPos;
    int verticalPos;
    char icon;
} Player;

typedef struct Enemies {
    Player* enemies[MAX_ENEMIES];
    int n_enemies;
} Enemies;

typedef struct Gambiarra {
    Board* board;
    Enemies* enemies;
} Gambiarra;

Gambiarra* makeBoard(int n_rows, int n_cols);

void printBoard(Board* board, Player* player, int horizontalPos, int verticalPos);
void gameplay(Player* player, Gambiarra* Gambiarra);
void freeBoard(Board* board);
void freePlayer(Player* player);
void enemyGameplay(Gambiarra* gambiarra);

bool thePlayIsValid(Player* player, Board* board);

Player* chooseIcon(char icon);

Enemies* createEnemies(int n_rows, int n_cols);

int main(){
    srand(time(NULL)); 
    int rows, cols;
    char icon;
    
    printf("Escolha a quantidade de linhas: ");
    scanf("%d", &rows);
    printf("Escolha a quantidade de colunas: ");
    scanf("%d", &cols);
    printf("Escolha seu icone: ");
    scanf(" %c", &icon);

    Gambiarra* board = makeBoard(rows, cols);
    Player* player = chooseIcon(icon);
    player->horizontalPos=0;
    player->verticalPos=0;
    gameplay(player, board);
    
    freeBoard(board->board);
    freePlayer(player);
    return 0;
}

Gambiarra* makeBoard(int n_rows,int n_cols){
    Gambiarra* gambiarra = malloc(sizeof(Gambiarra));
    Board* matrix = malloc(sizeof(Board));
    matrix->rows = n_rows;
    matrix->cols = n_cols;

    char** board = (char**)malloc(n_rows*sizeof(char*));
        for(int i=0; i<n_rows; i++){
            board[i] = (char*)calloc(n_cols, sizeof(char));
        }

    for(int i=0; i<n_rows; i++){
        for (int j = 0; j < n_cols; j++){
            board[i][j] = '_';
        }
    }
    Enemies* enemy = malloc(sizeof(Enemies));
    
    enemy = createEnemies(n_rows, n_cols);

    for(int i=0; i<enemy->n_enemies; i++){
        board[enemy->enemies[i]->verticalPos][enemy->enemies[i]->horizontalPos] = '$';
    }

    gambiarra->board->board = matrix;
    gambiarra->enemies = enemy;
    return gambiarra;
}

void printBoard(Board* board, Player* player, int horizontalPos, int verticalPos){
    system("cls");
    board->board[verticalPos][horizontalPos] = '_';
    board->board[player->verticalPos][player->horizontalPos] = player->icon;
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            printf("%c", board->board[i][j]);
            if (j < board->cols - 1) {
                printf("  ");
            }
        }
        printf("\n");
        if (i < board->rows - 1) {
            for (int k = 0; k < board->rows - 1; k++) {
                printf("-------");
            }
            printf("--\n");
        }
    }
}

Player* chooseIcon(char icon){
    Player* player = malloc(sizeof(Player));
    player->icon = icon;
    return player;
}

void gameplay(Player* player, Gambiarra* gambiarra){
    char tecla;
    bool fim = false;
    do {
        int horizontalPos = player->horizontalPos;
        int verticalPos = player->verticalPos;
        if (kbhit()) {
            tecla = getch();
            switch (tecla) {
                case 'w':
                    player->verticalPos--;
                    break;

                case 's':
                    player->verticalPos++;
                    break;

                case 'a':
                    player->horizontalPos--;
                    break;

                case 'd':
                    player->horizontalPos++;
                    break;

                default:
                    break;
            }
            printBoard(gambiarra->board, player, horizontalPos, verticalPos); // colocar tudo em gambiarra
            enemyGameplay(gambiarra);
            printf("%d",  gambiarra->enemies->enemies[0]->horizontalPos);
            printf("ei ei olha o som");
        }
        if (thePlayIsValid(player, gambiarra->board)) {
            fim = true;
            break;
        }
    } while (!fim); 
    return;
}

bool thePlayIsValid(Player* player, Board* board){
    return (player->horizontalPos>=board->rows || player->verticalPos>=board->cols);
} 

void freeBoard(Board* board) {
    for (int i = 0; i < board->rows; i++) {
        free(board->board[i]);
    }
    free(board->board);
    free(board);
}

void freePlayer(Player* player) {
    free(player);
}

int randomMove(){
    int r = rand()%5;
    return r;
}

Enemies* createEnemies(int n_rows, int n_cols){
    int n_enemies;
    printf("escolha a quantidade de inimigos");
    scanf("%d", &n_enemies);
    Enemies* enemy = malloc(sizeof(Enemies));
    enemy->n_enemies = n_enemies;

    for(int i=0; i<n_enemies; i++){

        int randomHorizontalPos=0;
        while(randomHorizontalPos<=1){
            randomHorizontalPos = rand()%n_rows;
        }
        int randomVerticalPos=0;
        while(randomVerticalPos<=1){
            randomVerticalPos = rand()%n_cols;
        }
        printf("vert: %d; horizontal: %d\n", randomHorizontalPos, randomHorizontalPos);
        Player* enemyPlayer = malloc(sizeof(Player));
        enemyPlayer->horizontalPos = randomHorizontalPos;
        enemyPlayer->verticalPos = randomVerticalPos;
        enemyPlayer->icon = '$';
        enemy->enemies[i] = enemyPlayer;
        printf("enemyV: %d\n", enemy->enemies[i]->verticalPos);
        printf("enemyH: %d\n", enemy->enemies[i]->horizontalPos);
    }
    return enemy;
}

void enemyGameplay(Gambiarra* gambiarra){
    for (int i = 0; i < gambiarra->enemies->n_enemies; i++) {
        int movement = randomMove();
        switch (movement) {
            case 1:
                gambiarra->enemies->enemies[i]->verticalPos++;
                break;
            case 2:
                gambiarra->enemies->enemies[i]->verticalPos--;
                break;
            case 3:
                gambiarra->enemies->enemies[i]->horizontalPos++;
                break;
            case 4:
                gambiarra->enemies->enemies[i]->horizontalPos--;
                break;
            default:
                break;
        }
        printf("ei ta caindo aqui");
        printBoard(gambiarra->board, gambiarra->enemies->enemies[i], gambiarra->enemies->enemies[i]->horizontalPos,
         gambiarra->enemies->enemies[i]->verticalPos);
    }

}