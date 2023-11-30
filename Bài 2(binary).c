#include <stdio.h>
#define N 10

int nhap(int arr[]) {
    int i;
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
}

void hienThi(const int arr[]) {
    int i;
    for (i = 0; i < N; i++) {
        printf("%5d", arr[i]);
    }
}

void sapXep(int arr[]) {
    int i, j;
    for (i = 0; i < N-1; i++) {
        for (j = N-1; j > i; j--) {
            if (arr[j] < arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int x) {
    int left = 0, right = N - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
            return 1;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}

int main() {
    int arr[N];
    nhap(arr);
    sapXep(arr);
    hienThi(arr);

    int x;
    while (1) {
        printf("\nNhap x = ");
        scanf("%d", &x);
        if (x == -1) break;
        if (binarySearch(arr, x))
            printf("Tim thay x.\n");
        else
            printf("Khong tim thay x.\n");
    }

    return 0;
}
