#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// H�m t?i uu d�ng phuong ph�p tuy?n t�nh
double linearOptimization(double* values, int n) {
    double max_value = values[0];
    for (int i = 1; i < n; i++) {
        if (values[i] > max_value) {
            max_value = values[i];
        }
    }
    return max_value;
}

// H�m t?i uu d�ng phuong ph�p nh? ph�n
double binaryOptimization(double* values, int n) {
    double left = 0.0;
    double right = 1.0;
    double epsilon = 1e-9;

    while (right - left > epsilon) {
        double mid = (left + right) / 2.0;
        // Th?c hi?n t�nh to�n t?i gi� tr? mid v� c?p nh?t left v� right
        // d?a tr�n k?t qu? c?a t�nh to�n
    }

    return (left + right) / 2.0;
}

int main() {
    int n = 1000; // S? chi?u c?a b�i to�n
    double* values = (double*)malloc(n * sizeof(double));

    // Kh?i t?o gi� tr? ng?u nhi�n cho c�c chi?u c?a b�i to�n
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        values[i] = (double)rand() / RAND_MAX;
    }

    // �o th?i gian th?c hi?n phuong ph�p tuy?n t�nh
    clock_t linearStart = clock();
    double linearResult = linearOptimization(values, n);
    clock_t linearEnd = clock();
    double linearTime = (double)(linearEnd - linearStart) / CLOCKS_PER_SEC;

    // �o th?i gian th?c hi?n phuong ph�p nh? ph�n
    clock_t binaryStart = clock();
    double binaryResult = binaryOptimization(values, n);
    clock_t binaryEnd = clock();
    double binaryTime = (double)(binaryEnd - binaryStart) / CLOCKS_PER_SEC;

    // In k?t qu?
    printf("Phuong phap tuyen tinh:\n");
    printf("Gia tri toi uu: %f\n", linearResult);
    printf("Thoi gian thuc hien: %f giay\n\n", linearTime);

    printf("Phuong phap nhi phan:\n");
    printf("Gia tri toi uu: %f\n", binaryResult);
    printf("Thoi gian thuc hien: %f giay\n", binaryTime);

    free(values);
    return 0;
}
