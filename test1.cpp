#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int h = 0; //高度
    

    cout<<"輸入圖形高度：";
    cin>>h;
    /*
     ____*
    ___***
    __*****
    
    */
    for(int i=1;i<=h;i++){
        for(int j=0;j<h-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=1+(i-1)*2;j++){
            cout<<"*";
        }
        cout<<endl;
    }

    //i = h-1從上面到下面所以會是i--
   for(int i=h-1;i>=1;i--){
       for(int j=1;j<=h-i;j++){
           cout<<" ";
       }
       for(int j=1;j<=1+(i-1)*2;j++){
           cout<<"*";
       }
       cout<<endl;
   }
  
}