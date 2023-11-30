#include <stdio.h>
#define length 10

int* nhap(){
	static int arr[length];
	int i;
	for(i =0;i<length;i++){
		scanf("%d", &arr[i]);
	}
	return arr;
}

void hienThi(const int arr[]){
	int i;
	for(i=0;i<length;i++){
		printf("%5d", arr[i]);
	}
	printf("\n");
}

int linearSearch(int arr[],int x){
	int i;
	for(i= 0; i<length;i++){
		if(arr[i] == x)
		    return 1;
	}
	return 0;
}

int main(){
	int *arr;
	arr = nhap();
	hienThi(arr);
	
	int x;
	printf("\nNhap x= ");
	scanf("%d", &x); 
	
	if(linearSearch(arr, x)){
		printf("\nTon tai x trong mang.");
	}
	else{
	 printf("\nKhong ton tai x trong mang.");
	}
	
	return 0;
}

