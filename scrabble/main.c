// Name: Anish Gondhi 
// Course: CSCI 2122 Assignment 1 
/* This program helps the scrabble players to place words correctly
   on the board */

#include <stdio.h>
#include <string.h>

extern int first = 1;

static void printboard(char **board, int size){

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
}

static void placeWord(char **board, int size, char* word,int row_loc, int column_loc, char direction){

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

static int validate(char **board, int size, char* word, int row_loc, int column_loc, char direction){

    int len = strlen(word);

    if(direction == 'V'){
        if( len + row_loc > size){
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
        if( len + column_loc > size){
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

int main()
{
    // n is the size of the board N x N
    // w is the no of words, added to the board
    // x coordinate of the first character of the word
    // y coordinate of the first character of the word
    // f is a pointer, and it will be 0 indicating lowercase words
    int n,w,x,y,f;

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

        int validity = validate(board,n,s,y,x,d);

        if(validity == 1){
            placeWord(board, n,s,y,x,d);
        }else if(validity == 0) {
            printf("Invalid word placement: (%d,%d) %c, %s\n", x, y, d, s);
        }
    }

    scanf("%d",&f);

    printboard(board,n);

    return 0;
}
