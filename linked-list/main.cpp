#include <iostream>
using std::cout;
using std::endl;
using namespace std;



class LinkedList;    // 為了將class LinkedList設成class ListNode的friend,
// 需要先宣告
class ListNode{
private:
    int data;
    ListNode *next;
public:
    ListNode():data(0),next(0){};
    ListNode(int a):data(a),next(0){};
    
    friend class LinkedList;
};

class LinkedList{
private:
    // int size;                // size是用來記錄Linked list的長度, 非必要
    ListNode *first;            // list的第一個node
public:
    LinkedList():first(0){};
    void PrintList();           // 印出list的所有資料
    void Push_front(int x);     // 在list的開頭新增node
    void Push_back(int x);      // 在list的尾巴新增node
    void Delete(int x);         // 刪除list中的 int x
    void Clear();               // 把整串list刪除
    void Reverse();             // 將list反轉: 7->3->14 => 14->3->7
    void Search(int x);
    void largest();

};

/*
void LinkedList::srort()//排序
{
    ListNode *tail=first;
    ListNode *tmp=first;
    ListNode *curr=first;
    ListNode *prev=first;
    
    int size=0;
    while(tail)
    {
        tail=tail->next;
        size++;
    }
    for(int i=size;i>0;i++)
    {
        curr=first;
        prev=first;
        for(int j=0;j<i-1&&curr->next;j++)
        {
            if(curr->data>curr->next->data)
            {
                tmp=curr->next;
                curr->next=tmp->next;
                tmp->next=curr;
                
                if(curr==first)
                {
                    first=tmp;
                    prev=tmp;
                }
                else{
                    prev->next=tmp;
                    prev=prev->next;
                }
            }
            else{
                curr=curr->next;
                if(j!=0)prev=prev->next;
            }
        }
    }
}
*/

void LinkedList::PrintList(){
    if (first == 0) {                      // 如果first node是0則代表沒有data
        cout << "List is empty.\n";
        return;
    }
    
    //把*current的pointer設定為first
    ListNode *current = first;             // 用pointer *current在list中移動
    while (current != 0) {                 // Traversal
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::Push_front(int x){
    
    ListNode *newNode = new ListNode(x);   // 配置新的記憶體
    newNode->next = first;                 // 先把first接在newNode後面
    first = newNode;                       // 再把first指向newNode所指向的記憶體位置
}

void LinkedList::Push_back(int x){
    
    ListNode *newNode = new ListNode(x);   // 配置新的記憶體
    
    if (first == 0) {                      // 若list沒有node, 令newNode為first
        first = newNode;
        return;
    }
    
    ListNode *current = first;
    while (current->next != 0) {           // Traversal
        current = current->next;
    }
    current->next = newNode;               // 將newNode接在list的尾巴
}

void LinkedList::Delete(int x){
    
    ListNode *current = first,
    *previous = 0;
    while (current != 0 && current->data != x) {  // Traversal
        previous = current;                       // 如果current指向NULL
        current = current->next;                  // 或是current->data == x
    }                                             // 即結束while loop
    
    if (current == 0) {                 // list沒有要刪的node, 或是list為empty
        std::cout << "There is no " << x << " in list.\n";
        // return;
    }
    else if (current == first) {        // 要刪除的node剛好在list的開頭
        first = current->next;          // 把first移到下一個node
        delete current;                 // 如果list只有一個node, 那麼first就會指向NULL
        current = 0;                    // 當指標被delete後, 將其指向NULL, 可以避免不必要bug
        // return;
    }
    else {                              // 其餘情況, list中有欲刪除的node,
        previous->next = current->next; // 而且node不為first, 此時previous不為NULL
        delete current;
        current = 0;
        // return;
    }
}

void LinkedList::Search(int x)
{
    ListNode *current = first;
    
    //當current還有數字就繼續執行
    while(current != 0){ //travels
      
        if(current->data==x) //找到要的數字時
        {
            cout<<"Find the number: "<<x<<endl;
            current=current->next; //繼續進入下一個node不然會一直在當前的node
            return ;
        }
        else
        {
            current = current->next; //進入下一個node
        }
        
    }
    cout<<"Can't find the number."<<endl;
    
    return ;
}

void LinkedList::Clear(){
    
    while (first != 0) {            // Traversal
        ListNode *current = first;
        first = first->next;
        delete current;
        current = 0;
    }
}

void LinkedList::Reverse(){
    
    if (first == 0 || first->next == 0) {
        // list is empty or list has only one node
        return;
    }
    
    ListNode *previous = 0,
    *current = first,
    *preceding = first->next;
    
    while (preceding != 0) {
        current->next = previous;      // 把current->next轉向
        previous = current;            // previous往後挪
        current = preceding;           // current往後挪
        preceding = preceding->next;   // preceding往後挪
    }                                  // preceding更新成NULL即跳出while loop
    
    current->next = previous;          // 此時current位於最後一個node, 將current->next轉向
    first = current;                   // 更新first為current
}

void LinkedList::largest()
{
    if (first == 0 || first->next == 0) {
        // list is empty or list has only one node
        //cout<<"hello";
        return;
    }
    ListNode *current = first;
    //cout<<"head: "<<current<<endl;
    int max=INT8_MIN;
    //cout<<"Max: "<<max<<endl;
    while(current != NULL)
    {
        //cout<<"Hello:"<<endl;
        //cout<<"in while data: "<<current->data<<endl;
        if(max<current->data)
        {
            //cout<<"Hello"<<endl;
            max=current->data;
        }
        
        current=current->next;
    }
    cout<<"The largest number : "<<max<<endl;
    return ;
}

int main() {
    
   
    
    LinkedList list;
    
    list.PrintList();    // 目前list是空的
    int n;
    cout<<"Enter the number you want delete: ";
    cin>>n;
    list.Delete(n);      // list是空的, 沒有4
    int a;
    cout<<"Enter the number you want enter: ";
    cin>>a;
     
    list.Push_front(a);
     
    list.Push_back(1);   // list: 5
    list.Push_back(3);   // list: 5 3
    list.Push_front(2);  // list: 1 10 3
    list.PrintList();    // 印出:  9 5 3
    int c;
    cout<<"Enter the number you want delete: ";
    cin>>c;
    list.Delete(c);
    list.PrintList();
    
    
    //cout<<"after sort: ";
    //list.srort();
    //list.PrintList();    //印出：3 5 9 12
    list.Push_back(4);   // list: 9 5 3 4
    //list.Delete(9);      // list: 5 3 4
    list.PrintList();    // 印出:  5 3 4
    list.Push_front(8);  // list: 8 5 3 4
    list.PrintList();    // 印出:  8 5 3 4
    int s;
    cout<<"Enter the number you want search: ";
    cin>>s;
    list.Search(s);
    list.Reverse();      // list: 4 3 5 8
    list.PrintList();    // 印出:  4 3 5 8
    
  
  list.largest();
    
    list.Clear();        // 清空list
    list.PrintList();    // 印出: List is empty.
    
    return 0;
}
