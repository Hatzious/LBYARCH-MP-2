#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    uint8_t input;
    float output;
} six_seven;

six_seven **create_array (int rows, int cols) {
    six_seven **arr = malloc(rows * sizeof(six_seven *));
    for (int i = 0; i < rows; i++) {
        arr[i] = malloc(cols * sizeof(six_seven));
    }
    return arr;
}


void free_array (int rows, six_seven **arr) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

void encode_float (int rows, int cols, six_seven **arr) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter value for [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j].input);
        }
    }
}

void imgCvtGrayInttoFloat (int rows, int cols, six_seven **arr) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j].output = arr[i][j].input / 255.0f;
        }
    }
}

void output_ints (int rows, int cols, six_seven **arr) {
    printf("Ints of array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j].input);
        }
        printf("\n");
    }
}

void output_floats (int rows, int cols, six_seven **arr) {
    printf("Floats of array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", arr[i][j].output);
        }
        printf("\n");
    }
}

int main () {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    six_seven **arr = create_array(rows, cols);

    encode_float(rows, cols, arr);

    imgCvtGrayInttoFloat(rows, cols, arr);

    output_ints(rows, cols, arr);
    printf("\n");
    output_floats(rows, cols, arr);

    free_array(rows, arr);
    return 0;
}