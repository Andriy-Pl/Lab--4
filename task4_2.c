#include <stdio.h>
#include <windows.h>

void printArr(double *arr, int size){
    printf("\nArray: ");
    for(int i=0;i<size;i++){
        printf("%g, ",arr[i]);
    }
}
void createArr(double *arr, int size){
    printf("Введіть значення масиву:\n");

    for(int i=0;i<size;i++){
        printf("arr[%d]: ",i);
        scanf("%lf", &arr[i]);
    }
}
void changeMinMax(double *arr, double *arr2, int size){
    int maxIndex=0, minIndex=0;
    for(int i=0;i<size;i++){
        if(arr[maxIndex]<arr[i]){
            maxIndex = i;
        }else if (arr[minIndex]>arr[i]){
            minIndex = i;
        }
    }
    for(int i=0;i<size;i++){
        arr2[i]=arr[i];
        if(i==maxIndex){
            arr2[i]=arr[minIndex];
        }else if (i==minIndex){
            arr2[i]=arr[maxIndex];
        }  
    }
    printf("\nmax index: %d, min index: %d", maxIndex, minIndex);
}
int main(){

    SetConsoleOutputCP(CP_UTF8);

    int n;
    do{
        printf("Введіть натуральне число n: ");
        scanf("%d", &n);
    }while (n<=0);

    double arr[n], arr2[n];
    createArr(arr, n);
    printArr(arr, n);
    changeMinMax(arr, arr2, n);
    printArr(arr2, n);
    return 0;
}