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


int board() {
    int row = 0, col = 0;
    int arr[3][3] = {{0,1,2}, {3,4,5}, {6,7,8}};

    //loop for row
    for (row = 0; row < 3; ++row) {
        //loop for col
        for (col = 0; col < 3; ++col) {
            //for each row, col if there is an empty,
            printf("row[%d], col[%d] = %d \n", row,col,arr[row][col]);
        }
    }
    return 0;
}

int win() {
    
}

// int minimax() {

// }

// int max() {

// }

// int min() {

// }