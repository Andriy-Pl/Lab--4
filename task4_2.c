#include <stdio.h>
#include <windows.h>

void printArr(double *arr, int size){
    printf("Array: ");
    for(int i=0;i<size;i++) printf("%g ",arr[i]);
    printf("\n");
}
void createArr(double *arr, int size){
    float a;
    int isDublicate = 0;
    printf("Введіть значення масиву:\narr[0]: ");
    scanf("%f", &a);
    arr[0]=a;
    for(int i=1;i<size;){
        printf("arr[%d]: ",i);
        scanf("%f", &a);

        for(int j=0;j<i;j++){
            if(arr[j]==a){
                printf("Елементи повторюються!\n");
                isDublicate=1;
                break;
            }else{
                isDublicate=0;
            }
        }
        if(!isDublicate){
            arr[i]=a;
            i++;
        }
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
    printf("max index: %d, min index: %d\n", maxIndex, minIndex);
}
void changeKindex(double *arr, double *arr2, int size){
    int kIndex, minIndex=0;
    do{
        printf("Введіть k-ий елемент: ");
        scanf("%d", &kIndex);
    }while(kIndex>=size || kIndex<0);

    for(int i=0;i<size;i++){
        if (arr[minIndex]>arr[i]){
            minIndex = i;
        }
    }
    
    for(int i=0;i<size;i++){
        if(i==kIndex){
            arr2[i] = arr[minIndex];
        }else if (i==minIndex){
            arr2[i] = arr[kIndex];
        }else{
            arr2[i]=arr[i];
        }
    }
}

int main(){

    SetConsoleOutputCP(CP_UTF8);

    int n;
    do{
        printf("Введіть натуральне число n: ");
        scanf("%d", &n);
    }while (n<=0);

    double arr[n], arr2[n], arr3[n];
    createArr(arr, n);
    printArr(arr, n);
    changeMinMax(arr, arr2, n);
    printArr(arr2, n);

    changeKindex(arr, arr3, n);
    printArr(arr3, n);
    return 0;
}