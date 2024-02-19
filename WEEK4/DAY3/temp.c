// /* create a array 3 *3 10,20,30...90 numbers using malloc*/

// #include <stdio.h>
// #include <stdlib.h>
// int main() {

//   int **ptr2 = malloc(3 * sizeof(int *));
//   int *ptr3 = malloc(3 * sizeof(int));
//   int arr[**ptr2][*ptr3];
  
 
//     for (int j = 0; j < sizeof(ptr2); j++) {
//       for (int k = 0; k < sizeof(ptr3); k++) {
//         scanf("%d", &arr[j][k]);
//       }
//     }

//     for (int j = 0; j< sizeof(ptr2); j++) {
//       for (int k = 0; k < sizeof(ptr3); k++) {
//         printf("%d\t", &arr[j][k]);
//       }
//       printf("\n");
//     }
//     printf("\n");
//   }

#include <stdio.h>
#include <stdlib.h>

int main() {
    // For accessing 3 rows
    int **arr = (int **)malloc(3 * sizeof(int *));
    
    // For 3 rows
    for (int i = 0; i < 3; i++) {
        arr[i] = (int *)malloc(3 * sizeof(int));
    }

    int count = 10;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = count;
            count += 10;
        }
    }

    printf("Array elements:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < 3; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
