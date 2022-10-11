#include <stdio.h>
#include <stdbool.h>

int board();
int minimax();
int min();
int max();

int main();
int main() {
    board();
    // minimax();
    // min();
    // max();
}

// this function is to read the board location for eg


//         Col1    Col2    Col3
// Row1   1 , 1 |  1 , 2 | 1 , 3
//        ______|________|______              
// Row2   2 , 1 | 2 , 2  | 2 , 3
//        ______|________|______
// Row3   3 , 1 | 3 , 2  | 3 , 3
//              |        |


int board(row, col) {
    int row;
    int col;
    int arr[3][3] = {{ , , }, { , , }, { , , }};

    //loop for row
    for (row = 1; row < 4; ++row) {
        //loop for col
        for (col = 1; col < 4; ++col) {
            //for each row, col if there is an empty,
            if (arr[row][col] == " ");
            //return true
            return true;
        }
    }
    return false;
}

int win() {
    
}

// int minimax() {

// }

// int max() {

// }

// int min() {

// }