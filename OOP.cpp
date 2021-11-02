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

好處：
-減少coupling
-自由修改類別內的實現
-類別具有清晰的對外介面

2.繼承：
子類別可以繼承父類別除了private以外所有的屬性和方法，子類別也可以有著屬於自己的屬性和方法
子類別可以使用自己的方法實現父類別的功能：方法重載

3.多型：
多形優點：
-組織結構清晰
-可讀性強
-對於前期和後期的擴充套件以及維護性高
*/


#include <iostream>
#include <string>

using namespace std;
/*
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
*/
// polymorphism code example

class program{
    public: 
    string writeSchart(){

    }

    string writeSQL(){

    }
    
    string writeC_plus_plus(){

    }



};