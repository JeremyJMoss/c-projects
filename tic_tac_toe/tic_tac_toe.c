#include <stdio.h>
#include <stdbool.h>

void drawBoard(char board[3][3]);

int checkWin(char board[3][3]);

bool addToBoard(int squareNumber, char board[3][3], int playerNumber);


void main(){
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

    printf("\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    int playerTurn = 1;
    while (checkWin(board) == -1){
        drawBoard(board);
        printf("\n");
        while (true){
            int squareNumber;
            printf("\nPlayer %d pick a square: ", (playerTurn % 2) ? 1 : 2);
            scanf("%d", &squareNumber);
            if (squareNumber < 1 || squareNumber > 10){
                printf("\nPlease pick a number that is availble on board");
            }
            else if (addToBoard(squareNumber, board, (playerTurn % 2) ? 1 : 2)){
                printf("\n");
                break;
            }
            else{
                printf("\nThat square is already occupied\n");
            }
        }

        playerTurn++;
    }
    printf("\n");
    drawBoard(board);
    playerTurn--;
    if (checkWin(board) == 1){    
        printf("\nCongratulations Player %d!\n", (playerTurn % 2) ? 1 : 2);
    } else {
        printf("\nIt's a Draw!\n");
    }

}

void drawBoard(char board[3][3]){
    for (int i = 0; i < 3; i++){
        printf("   |   |   \n");
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i == 2) {
            printf("   |   |   \n");
            break;
        }
        printf("___|___|___\n");
    }
}

int checkWin(char board[3][3]) {
    // Checking rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Checking columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // Checking diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return 1;
    }

    if (board[0][0] != '1' && board[0][1] != '2' && board [0][2] != '3' &&
        board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6' &&
        board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9'){
        return 0;
    }

    return -1; // If no winner yet
}

bool addToBoard(int squareNumber, char board[3][3], int playerNumber){
    char playerSymbol = (playerNumber == 1) ? 'X' : 'O';
    
    int row = (squareNumber - 1) / 3;
    int col = (squareNumber - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O'){
        return false;
    }

    board[row][col] = playerSymbol;
    return true;
}