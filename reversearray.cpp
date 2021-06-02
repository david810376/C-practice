
#include<iostream>
#include <string>
using namespace std;

void reversearray(int array[],int first, int end)
{
    
    while (first < end)
    {
        int newnumber = array[first]; //set a new number to put the first number
        array[first] = array[end]; //that the first number become the last one and
        array[end] = newnumber; //put the first number that memory in the newnumber and become the last number
        first++;//next numebr
        end--;//next number that count by the last one
    }
}

void printarray(int array[],int n)
{
    for(int i=0;i<n;i++)
        cout<<array[i]<<" ";
    cout<<endl;
}


int main()
{
    int size;
    int i=0;
    int array[100];
    cout<<"Enter the size of the array: ";
    cin>>size;
    cout<<"Enter the "<<size<<" number in to the array: ";
    for(int i=0;i<size;i++)
        cin>>array[i];
    cout<<"Before the reverse: ";
    printarray(array,size);
    reversearray(array,i-1,size); 
    cout<<"After the reverse: ";
    printarray(array,size);
    system("PAUSE");
}

/*
 Enter the size of the array: 4
 Enter the 4 number in to the array: 1
 2
 3
 4
 Before the reverse: 1 2 3 4
 After the reverse: 4 3 2 1
 */
