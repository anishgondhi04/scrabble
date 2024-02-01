// Name: Anish Gondhi 
// Course: CSCI 2122 Assignment 1 
/* This program helps the scrabble players to place words correctly
   on the board */

#include <stdio.h>
#include <string.h>

static int first = 1;
static int n = 0;

static void printboard(char board[n][n]){

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
}

static void placeWord(char board[n][n], char* word,int row_loc, int column_loc, char direction){

    int len = strlen(word);

    if(direction == 'V') {
        for (int i = 0; i < len; ++i) {
            board[row_loc++][column_loc] = word[i];
        }
    }else if (direction == 'H') {
        for (int i = 0; i < len; ++i) {
            board[row_loc][column_loc++] = word[i];
        }
    }
}

static int validate(char board[n][n], char* word, int row_loc, int column_loc, char direction){

    int len = strlen(word);

    if(direction == 'V'){
        if( len + row_loc > n){
            return 0;
        }else if(first == 1){
            first = 0;
            return 1;
        }else{
            for (int i = 0; i < len; ++i) {
                if(board[row_loc++][column_loc] == word[i]){
                    return 1;
                }
            }
        }

    }else if(direction == 'H'){
        if( len + column_loc > n){
            return 0;
        }else if(first == 1){
            first = 0;
            return 1;
        }else{
            for (int i = 0; i < len; ++i) {
                if(board[row_loc][column_loc++] == word[i]){
                    return 1;
                }
            }
        }
    }

    return 0;
}

static void whereToPlace(char board[n][n],int before, char character, int after){

    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < n; ++j) {
            if(board[i][j] == character){
                if((i - before - 1 >= 0) && (i + after < n)){
                    int flag = 0;
                    for (int k = i-1; k >= i - before ; --k) {
                        if(board[k][j]!='.'){
                            flag++;
                        }
                    }
                    for (int k = i+1; k < i + after; ++k) {
                        if(board[k][j]!='.'){
                            flag++;
                        }
                    }
                    if(flag == 0){
                        printf("Place vertically at (%d,%d)\n",j,i);
                    }
                }
                if((j - before - 1 >= 0) && (j + after < n)){
                    int flag = 0;
                    for (int k = j-1; k >= j - before ; --k) {
                        if(board[i][k]!='.'){
                            flag++;
                        }
                    }
                    for (int k = j+1; k < j + after; ++k) {
                        if(board[i][k]!='.'){
                            flag++;
                        }
                    }
                    if(flag == 0){
                        printf("Place horizontally at (%d,%d)\n",j,i);
                    }
                }
            }
        }
    }
}

int main()
{
    // n is the size of the board N x N
    // w is the no of words, added to the board
    // x coordinate of the first character of the word
    // y coordinate of the first character of the word
    // f is a pointer, and it will be 0 indicating lowercase words

    int w,x,y,f;

    scanf("%d",&n);      // taking input in n
    scanf("%d",&w);       // taking input in w

    // d is the direction in which word is written V 'vertically' or H 'horizontally'
    // s is the word
    // board is 2D array representing game board
    char d, s[n], board[n][n];

    // initializing the board with '.'
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            board[i][j] = '.';
        }
    }

    //taking input for all the words and placing them on the board
    for (int i = 0; i < w; ++i) {
        scanf("%d %d %c %s",&x,&y,&d,s);

        int validity = validate( board,s,y,x,d);

        if(validity == 1){
            placeWord( board, s,y,x,d);
        }else if(validity == 0) {
            printf("Invalid word placement: (%d,%d) %c, %s\n", x, y, d, s);
        }
    }

    scanf("%d",&f);

    printboard(board);

    if( f > 0 ){
        int before,after;
        char character;

        for (int i = 0; i < f; ++i) {

            scanf("%d %c %d",&before,&character,&after);

            whereToPlace(board, before, character, after);
        }
    }

    return 0;
}
