/*
practice queue by linked list

queue:
1. first in first out
2. two step:
push: 兩個node一個紀錄全部的node的address，一個維持在top
pop：直接把維持在top的delete掉然後top往下一個走
*/

#include<iostream>

using namespace std;

//設定data跟pointer
struct queuenode{
    int data;
    queuenode *next;
    queuenode():data(0),next(0){};
    queuenode(int x):data(x),next(0){};

};

class queuelist{
    private:
    queuenode *front;
    queuenode *back;
    int size;

    public:
    queuelist():front(0),back(0),size(0){};
    bool isempty();
    int getsize();
    int getfront();
    int getback();
    void push(int x);
    void pop();

};

bool queuelist::isempty(){
    return ((front&&back) == 0);
}

int queuelist::getsize(){
    return size;
}

int queuelist::getfront(){
    if(isempty()){
        cout<<"The queue is empty. "<<endl;
        return -1;
    }
    return front->data;
}

int queuelist::getback(){
    if(isempty()){
        cout<<"The queue is empty. "<<endl;
        return -1;
    }

    return back->data;
}



void queuelist::push(int x){
    if(isempty()){
        front = new queuenode(x);
        back = front;
        size++;
        return ;

    }
    /*
    用back往後走，這樣刪除時就直接刪除front就可以了
    因此是back->next
    */
    queuenode *newnode = new queuenode(x);
    back->next = back;
    back = newnode;
    size++;
}

void queuelist::pop(){
    if(isempty()){
        cout<<"The queue is empty. "<<endl;
    }
    
    queuenode *deletenode = front;
    front = front->next;
    delete deletenode;
    deletenode=0;
    size--;
}

