#include <stdio.h>

void printArr(int *arr, int size){
    printf("\nArr: ");
    for(int i=0;i<size;i++){
        printf("%d, ",arr[i]);
    }
}
void createArr(int *arr, int size){
    //int a;
    for(int i=0;i<size;i++){
        printf("input elem a[%d]: ",i);
        scanf("%d", &arr[i]);
        //arr[i]=a;
    }
}
void changeMinMax(int *arr, int size){

    for(int i=0;i<size;i++){
        
    }
}
int main(){
    int n;
    printf("Input n: ");
    scanf("%d", &n);

    int arr[n];
    createArr(arr, n);
    printArr(arr, n);
    return 0;
}