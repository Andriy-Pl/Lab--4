#include <stdio.h>
#include <windows.h>
void createArr(double *arr, int size){
    float a;
    
    printf("Введіть значення масиву в зростанні:\narr[0]: ");
    scanf("%f", &a);
    arr[0]=a;
    for(int i=1;i<size;){
        printf("arr[%d]: ",i);
        scanf("%f", &a);
        if(arr[i-1]<=a){
            arr[i]=a;
            i++;
        }else{
            printf("Наступний член повинен бути більшим за попередній\n");
        }
    }
}
void findIndexs(double *arr, int size, float x){
    if(x<arr[0]){
        printf("\nЧисло x є меншим за будь яке число послідовності");
    }
    else if(x>=arr[0] && x<=arr[size-1]){
        for(int i=0;i<size;i++){
            if(arr[i]<=x && x<=arr[i+1]){
                printf("\nЧисло x знаходиться між index: %d та index: %d \n %g <= %g <= %g", i, i+1, arr[i], x, arr[i+1]);
            }
        }
    }else{
        printf("\nЧисло x є більши за будь яке число послідовності");
    }
    
}
void createNewArr(double *arr, double *arr2, int size, float x){

    if(x<arr[0]){
        arr2[0]=x;
        for (int i=0; i<=size; i++){
            arr2[i+1]=arr[i];
        }
    }else if(x>=arr[0] && x<=arr[size-1])
    {
        int swich = 1;
        int j=0;
        for (int i=0; i<size; i++){
            arr2[j]=arr[i];
            
            if(arr[i]<=x && x<=arr[i+1] && swich){
                j++;
                arr2[j]=x;
                swich = 0;
            }
            j++;
        }
    }else{
        for (int i=0; i<size; i++){
            arr2[i]=arr[i];
        }
        arr2[size]=x;
    }
}
void printArr(double *arr, int size){
    printf("\nArr: ");
    for(int i=0;i<size;i++){
        printf("%g ",arr[i]);
    }
}

int main(){

    SetConsoleOutputCP(CP_UTF8);

    int n;
    float x;
    do{
        printf("Введіть натуральне число n: ");
        scanf("%d", &n);
    }while (n<=0);
    double arr[n];
    double arr2[n+1];
    printf("Введіть x: ");
    scanf("%f", &x);

    createArr(arr, n);
    printArr(arr, n);
    findIndexs(arr, n, x);
    createNewArr(arr, arr2, n, x);
    printArr(arr2,n+1);
    return 0;
}