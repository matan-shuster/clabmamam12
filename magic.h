/**
 * Checks if the matrix is a magic square or not
 *
 * @author Matan Shuster
 * @version 11/12/2021
 */
#define TRUE 1
#define FALSE 0
#define N 4

/* This functions accepts an array of numbers from the main program and then calculates the first row sum. */
/* Afterwards it calculates the sum of each row, column and diagonal and compares it to the first row sum */
/* and checks if each is equal to the first row sum. If they are then it returns that the matrix is a magic square */
/* otherwise it returns that the array is not a magic square. */
int isMagicSquare(int arr[]) {
    int i,row, col, currentSum;
    int firstRowSum = 0;
    int currentCell = 0;
    int twoDarray[N][N];
    /* Converts arr from 1D array to 2D array */
    for(row = 0; row<N ; row++) {
        for (col = 0; col < N; col++) {
            twoDarray[row][col] = arr[currentCell];
            currentCell++;
        }
    }
    /*Calculate sum of first row */
    for (col = 0; col < N; col++) {
        firstRowSum += twoDarray[0][col];
    }
    /*Calculate sum of each row except first row */
    for (row = 1; row < N; row++) {
        currentSum = 0;
        for (col = 0; col < N; col++) {
            currentSum += twoDarray[row][col];
        }
        if (currentSum != firstRowSum) {
            return FALSE;
        }
    }
    /*Calculate sum of each column */
    for (col = 0; col < N; col++) {
        currentSum = 0;
        for (row = 0; row < N; row++) {
            currentSum += twoDarray[row][col];
        }
        if (currentSum != firstRowSum) {
            return FALSE;
        }
    }
    /*Calculates the sum of the top left to bottom right diagonal */
    currentSum = 0;
    for(i = 0; i< N; i++){
        currentSum += twoDarray[i][i];
    }
    if (currentSum != firstRowSum) {
        return FALSE;
    }
    /*Calculate the sum of the bottom right to top left diagonal */
    currentSum = 0;
    for (i = N-1; i >= 0; i--){
        currentSum += twoDarray[i][i];
    }
    if (currentSum != firstRowSum) {
        return FALSE;
    }
    /*If all the sums are then the matrix is a magic square and the function returns true */
    return TRUE;
}

