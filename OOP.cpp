/*
複習OOP的特性
OOP又或者叫做物件導向
物件導向有著三大特性:
1.封裝：就是header
public：可以被繼承
private：不能被繼承
class{
public //可以用來繼承
private // 用來宣告class內的成員
}

2.繼承：
3.多型：
*/


#include <iostream>
#include <string>

using namespace std;

class demo{
    public:
    demo(int a,int b){
        pa=a;
        pb=b;
    }
    int do_somthing(){
        return pa+pb;
    }
    private:
    int pa;
    int pb;
};


int main(){
    demo d(10,12); //繼承
    cout<<d.do_somthing()<<endl; // 10+12 = 22 繼承了do somthing內的pa+pb
    //cout<<d.pa<<endl; //error 不能繼承private內的元素
}