/**
 * Receives matrix from user and checks if it's a magic square or not
 *
 * @author Matan Shuster
 * @version 11/12/2021
 */
#include <stdio.h>
#include "magic.h"

/* Checks if there's any duplicate numbers in the array. Returns TRUE if there is any */
int duplicateNumbers(int arr[]){
        int i,j;
        for(i = 0; i < N*N; i++){
            for(j = i+1; j < N*N-i-1; j++){
                if(arr[i] == arr[j]){
                return TRUE;
                }
             }
         }
        return FALSE;
}

/*Checks if there's a lower number than 1-N*N. Returns TRUE if there is any */
int lowNumber(int arr[]){
    int i;
    for(i = 0; i<(N*N); i++)
    {
        if((1-N*N) > arr[i]){
            return TRUE;
        }
    }
    return FALSE;
}
/*Prints the matrix in a square pattern */
void printMatrix(int arr[]){
    int row,col;
    int currentCell = 0;
    printf("The matrix is\n");
    for(row = 0; row<N ; row++){
        for (col = 0; col<N;col++){
            printf("%d ",arr[currentCell]);
            currentCell++;
        }
        printf("\n");
    }
}


/*Checks if the matrix entered contains enough numbers, outputs an error if there are too many or too few. Exits out of function if the matrix isn't in the correct length. */
/*Afterwards it checks if the array is a magic square, does not contain a high number and does not contain duplicate numbers. */
/*Prints if the matrix is a magic square or not. */
int printResult(int arr[]){
    if(arr[N*N-1] == 0){
        printf("Not enough numbers have been entered");
        return FALSE;
    }
    else if(0 != arr[N*N]){
       printf("Too many numbers have been entered");
        return FALSE;
    }
    printMatrix(arr);
    if((!isMagicSquare(arr)) || lowNumber(arr) || duplicateNumbers(arr)){
       printf("The matrix is not a basic magic square");
   }
   else{
       printf("The matrix is a basic magic square");
   }
return 0;
}
/*Main function that accepts the input and checks if any character has been entered. Afterwards calls the printResult function. */
int main() {
    int i;
    int arr[N * N + 1] = {0};
    printf("N is %d\n", N);
    printf("Please enter the matrix with a maximum length of %d: \n", N*N);
    for(i = 0; i < (N*N+1); i++) {
        if (scanf("%d ", &arr[i]) == 0) {
            printf("Invalid input,non integer has been entered");
            return FALSE;
        }
        else{
            continue;
        }
    }
   printResult(arr);
    return 0;
}
