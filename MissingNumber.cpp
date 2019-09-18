
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

void swap(int* a, int* b){
    int t=*a;
    *a = *b;
    *b =t;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i =(low -1);
    
    for(int j=low;j<=high-1;j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return(i+1);
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quickSort(arr, low,pi-1);
        quickSort(arr, pi+1,high);
    }
}

void MissingNumber(int array[], int size){
    int i;
    int siguiente=0;
    for(i=0;i<size;i++){
       siguiente=array[i];
    }
    
    siguiente++;
    
    if(siguiente %2 != 0 ||siguiente < 0)
        siguiente ++;
    
    cout<<siguiente;
}

void printArray(int arr[], int size){
    int i;
    for(i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

int main(int argc, char** argv) {
    
    int arr[]={12,7,8,9,1,5,13,22};
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<"El arreglo es: ";
    printArray(arr,n);
    quickSort(arr,0,n-1);
    cout<<"El arreglo resultante es: ";
    printArray(arr,n);
    cout<<"El siguiente numero positivo es: ";
    MissingNumber(arr, n);

    return 0;
}
