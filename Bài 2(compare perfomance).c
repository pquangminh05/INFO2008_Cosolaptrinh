#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hàm t?i uu dùng phuong pháp tuy?n tính
double linearOptimization(double* values, int n) {
    double max_value = values[0];
    for (int i = 1; i < n; i++) {
        if (values[i] > max_value) {
            max_value = values[i];
        }
    }
    return max_value;
}

// Hàm t?i uu dùng phuong pháp nh? phân
double binaryOptimization(double* values, int n) {
    double left = 0.0;
    double right = 1.0;
    double epsilon = 1e-9;

    while (right - left > epsilon) {
        double mid = (left + right) / 2.0;
        // Th?c hi?n tính toán t?i giá tr? mid và c?p nh?t left và right
        // d?a trên k?t qu? c?a tính toán
    }

    return (left + right) / 2.0;
}

int main() {
    int n = 1000; // S? chi?u c?a bài toán
    double* values = (double*)malloc(n * sizeof(double));

    // Kh?i t?o giá tr? ng?u nhiên cho các chi?u c?a bài toán
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        values[i] = (double)rand() / RAND_MAX;
    }

    // Ðo th?i gian th?c hi?n phuong pháp tuy?n tính
    clock_t linearStart = clock();
    double linearResult = linearOptimization(values, n);
    clock_t linearEnd = clock();
    double linearTime = (double)(linearEnd - linearStart) / CLOCKS_PER_SEC;

    // Ðo th?i gian th?c hi?n phuong pháp nh? phân
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
