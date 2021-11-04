#include<string>
#include<iostream>

using namespace std;

//swap function
void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

/*
partation function區分左右數列
設一個pivot然後一個一個比較比pivot大的放右邊比pivot小的放左邊
*/
int partition(int arr[],int left,int right){
   
   int pivot = arr[right]; //pivot 為最右邊的
   int i = (left-1);

   for(int j = left;j<=right-1;j++){
       if(arr[j]<pivot){
           i++;
           swap(&arr[i],&arr[j]);
       }
       swap(&arr[i+1],&arr[right]);
   }
   return i;
}
