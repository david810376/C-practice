/*
Stack
1. first in last out
2. 有兩個動作需要 pop push
*/

#include <iostream>
//#include <stack>

using namespace std;

/*
class stackarray{
    
private:
    int top; //index of the top
    int size; // stack array size
    int *stack;
    void doublesize(); // double the size if the array full
    
public:
    stackarray():top(0),size(1){
        stack = new int[size];
    }
    
    void push(int x); // push the number to the top
    void pop(); // pop the top number out of the stack
    int Top(); // print out the top number
    bool isEmpty(); // check is the stack empty will return true and false
    int getsize(); // get the array size
    
};

void stackarray::doublesize(){
    size = size *2; //double the size
    int *newstack = new int[size]; // make the new stack size
    
    
    for(int i=0; i <size/2;i++)
    {
        newstack[i] = stack[i]; // move the old data to the new stack
        
    }
    
    delete [] stack;
    stack = newstack;
}

void stackarray::push(int x){
    if(top == size-1)
    {
        doublesize();
    }
    
    stack[++top] = x; //top+1 and input the number
    
    init         push(6)
    |   |        |   |
    |   |        |   |
    |   |        |6  |
    |___|        |___|
    top : 0      top + 1 =top 1 = 6
            
     
}

void stackarray::pop()
{
    if(isEmpty()){
        cout<<"The stack is Empty."<<endl;
        return ;
    }
    top--;
}

int stackarray::Top()
{
    if(isEmpty())
    {
        cout<<"The stack is empty."<<endl;
        
    }
    
    return stack[top];
}

bool stackarray::isEmpty(){
    return top==0; //return true when top is 0
}

int stackarray::getsize()
{
    return top;
    
    init         push(6)
    |   |        |   |
    |   |        |   |
    |   |        |6  |
    |___|        |___|
    size: 0      size: 1
     
}

int main(){
    
    
    //using the stack function
    stack<int> stacknumber;
    
    stacknumber.push(5); //5
    stacknumber.push(6); //6 5
    stacknumber.push(1); //1 6 5
    while(!stacknumber.empty())
    {
        cout<<"The number in stack: "<<stacknumber.top()<<endl;
        stacknumber.pop();
    }
    
    stackarray arr;
    arr.push(6);
    arr.push(12);
    //arr.pop();
    cout<<arr.Top()<<endl;
    cout<<"get size: "<<arr.getsize()<<endl;
    
}
*/


class stacklist; // friend class

class stacknode{
private:
    int data; // data for the list
    stacknode *next; // next
public:
    stacknode():data(0),next(0){}; //set the data = 0 and next = 0
    stacknode(int x):data(x),next(0){}; // if input x than data = x
    stacknode(int x,stacknode *nextnode):data(x),next(nextnode){}; // 因為只有用push front所以可以直接設一個nextnode
    
    friend class stacklist;
    
};

class stacklist{
private:
    stacknode *top; //記錄第一個的address
    int size; //size
public:
    stacklist():top(0),size(0){}; //宣告top = 0 和 size =0
    void push(int x);
    void pop();
    bool isEmpty();
    int getsize();
    int Top();
};


void stacklist::push(int x)
{
    if(isEmpty()){
        top = new stacknode(x);
        size++;
        return;
    }
    
    stacknode *newnode = new stacknode(x); // make the new node became the number (x)
    newnode->next = top; // 把top push到目前的
    top = newnode; // top = new node
    size++; //size +1
    /*
     
        init            push(6)
     ___________        _____________
     |                 |6
     -----------        --------------
     
        size:0             *newnode的address = 6
        top:0               newnode->next 把原本newnode指向的NULL連接到現在第一個node也就是top
                            把newnode的地方改成top
                            size +1 用來記錄現在的大小
     */
}

/*因為stack是用first in last out的概念
 所以會發現最後新增的都會在第一個node
 所以pop就直接移掉第一個node把top->next到下一個*/
void stacklist::pop(){
    if(isEmpty()){
        cout<<"The stack list is empty."<<endl;
        return;
    }
    
    stacknode *deletenode = top; //把要刪除的pointer變成top，因為stack是刪除最上面的
    top = top->next; //把現在的top移到下一個
    delete deletenode; //刪除目前的
    deletenode = 0;
    size --; //減少現在的size
}

bool stacklist::isEmpty(){
    return (size==0);
}

int stacklist::Top(){
    if(isEmpty()){
        cout<<"The stack list is empty."<<endl;
        return 0;
    }
    
    return top->data;
}

int stacklist::getsize(){
    return size;
}

int main(){
    stacklist list;
    //list.pop();
    cout<<"The size is: "<<list.getsize()<<endl;
    cout<<"The top is: "<<list.Top()<<endl;
}
