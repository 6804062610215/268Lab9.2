#include <stdio.h>

void swapValue(int *a, int *b, int *c);
void swapArray(int a[], int b[], int size); 


int main() {
	int arr1[] = {1,2,3};
	int arr2[] = {4,5,6};
	int a = 1, b = 2, c = 3, size = 3, i;
	
	printf("Before swap function: a=%d, b=%d, c=%d\n", a, b, c);
	swapValue(&a, &b, &c);
	printf("After swap function: a=%d, b=%d, c=%d\n", a, b, c);
	printf("--------------------------------\n");
	printf("Before swap function:\n");
	for (i = 0; i < size; i++) {
		printf("arry1[%d]=%d %s", i, arr1[i], i < size -1 ? "," : "\n");
	}
	for (i = 0; i < size; i++) {
		printf("arry2[%d]=%d %s", i, arr2[i], i < size -1 ? "," : "\n");
	}
	swapArray(arr1, arr2, size);
	printf("After swap function:\n");
	for (i = 0; i < size; i++) {
		printf("arry1[%d]=%d %s", i, arr1[i], i < size -1 ? "," : "\n");
	}
	for (i = 0; i < size; i++) {
		printf("arry2[%d]=%d %s", i, arr2[i], i < size -1 ? "," : "\n");
	}
}

void swapValue(int *a, int *b, int *c){
	int temp;
    temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}
void swapArray(int a[], int b[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}
