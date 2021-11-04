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
int partition(int *arr,int start,int end){
   
   int pivot = arr[end]; //pivot為最右邊的數字
   int i = (start-1); //因為所有數列中可能所有數字都比pivot大

   for(int j = start;j<=end-1;j++){ //跑整個array
       /*
       9 4 1 6 7 3 5
       pivot為5
       j=1
       arr[j]>pivot不變
       j++;
       j=1
       i=-1
       arr[1]=4<pivot
       進入if i++
       i=0
       arr[0]->9跟arr[1]->4對調
       */
       if(arr[j]<pivot){ 
           i++;
           swap(&arr[i],&arr[j]);
       }
   }
   /*
   4137695
   i = 3
   4135697
   */
   i++;
   swap(&arr[i],&arr[end]);
   return i;
}

void quick_sort(int *arr,int start,int end){
    if(start<end){
        int pivot = partition(arr,start,end);
        quick_sort(arr,start,pivot-1);
        quick_sort(arr,pivot+1,end);
    }
}

void printarray(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int size =9;
    int arr[] = {9,4,1,6,7,3,8,2,5};
    cout<<"After Quick store: ";
    printarray(arr,size);
    cout<<endl;
    cout<<"Before Quick store: ";
    quick_sort(arr,0,size-1);
    printarray(arr,size);
}