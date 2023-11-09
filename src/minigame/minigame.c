#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

Board* make_board(int n_rows, int n_cols);
void print_board(Board* board, Player* Player);

Player* chooseIcon(char icon);
Player* gameplay(int horizontalPos, int verticalPos, Player* player, Board* Board);

int main(){
    int rows, cols;
    char icon;
    
    printf("Escolha a quantidade de linhas: ");
    scanf("%d", &rows);
    printf("Escolha a quantidade de colunas: ");
    scanf("%d", &cols);
    printf("Escolha seu icone: ");
    scanf(" %c", &icon);

    Board* board = make_board(rows, cols);
    Player* player = chooseIcon(icon);
    player = gameplay(0, 0, player, board);
   
    print_board(board, player);
}

Board* make_board(int n_rows, int n_cols){
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

    matrix->board = board;
    return matrix;
}

void print_board(Board* board, Player* player){
    board->board[player->horizontalPos][player->verticalPos] = player->icon;
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            printf("%c", board->board[i][j]);
            if (j < board->cols - 1) {
                printf("   ");
            }
        }
        printf("\n");
        if (i < board->rows - 1) {
            for (int k = 0; k < board->rows - 1; k++) {
                printf("----");
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

Player* gameplay(int horizontalPos, int verticalPos, Player* player, Board* board){
    if (horizontalPos >= 0 && horizontalPos < board->rows &&
        verticalPos >= 0 && verticalPos < board->cols) {
        player->horizontalPos = horizontalPos;
        player->verticalPos = verticalPos;    
    } else {
        printf("Posições inválidas para o jogador.\n");
    }
    return player; 
}