// Name: Anish Gondhi 
// Course: CSCI 2122 Assignment 1 
/* This program helps the scrabble players to place words correctly
   on the board */

#include <stdio.h>
#include <string.h>

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

    //taking input for all the words
    for (int i = 0; i < w; ++i) {
        scanf("%d %d %c %s",&x,&y,&d,s);
    }
    scanf("%d",&f);

    if(d == 'V') {
        for (int i = 0; i < strlen(s); ++i) {
            board[y++][x] = s[i];
        }
    }
    else if (d == 'H') {
        for (int i = 0; i < strlen(s); ++i) {
            board[y][x++] = s[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%c",board[i][j]);
        }
        printf("\n");
    }

    return 0;
}
