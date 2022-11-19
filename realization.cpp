#include <istream>
#include <ostream>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>

struct Node
{  
    T data;
    Node* next;
    Node(T x) {data = x; next = nullptr;}
};

template <typename T>
class List
{
    Node<T>* head;
public:
    List() {head = nullptr;};
    void push_front(T x);
    void pop_front();
    void push_back(T x);
    void pop_back();
    bool emptycheck();
    template <typename T2>
    friend ostream& operator<<(ostream& out, List<T2> list);
    template <typename T1>
    friend ostream& operator+(ostream& out, List<T1> list);
};

template <typename T>
void List<T>::push_front(T x)
{
    Node<T>* new_elem = new Node<T>(x);
    new_elem -> next = head;
    head = new_elem;
}
template <typename T>
bool List<T>::emptycheck()
{
    return head == nullptr;
}
template <typename T>
void List<T>::push_back(T x)
{
    Node<T>* new_elem = new Node<T>(x);
    new_elem -> next = head;
    Node<T>* ptr = head;
    while(ptr -> next){
        ptr = ptr -> next;
    }
    ptr -> next = new_elem;
}
template <typename T>
void List<T>::pop_front()
{
    Node<T>* deletion_elem = head;
    head =  head -> next ;
    delete deletion_elem;
}
template <typename T>
void List<T>::pop_back()
{
    if (head == nullptr)
    {
        return;
    }
    if (head -> next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    
    Node<T>* ptr = head;
    while(ptr -> next -> next){
        ptr = ptr -> next;
    }
    delete ptr -> next;
    ptr -> next = nullptr;
}
template <typename T>
ostream& operator<<(ostream& out, List<T> list)
{
    Node<T>* ptr = list.head;
    while (ptr){
        out << ptr -> data << " ";
        ptr = ptr-> next;
    }
    return out;
}
/*template <typename T>
ostream& operator+(ostream& out, List<T> list1, List<T> list2)
{
    Node<T>* ptr = list.head;
    while (ptr){
        out << ptr -> data << " ";
        ptr = ptr-> next;
   }
    return out;
}*/

int main(){
    List<int> mylist;
    mylist.push_front(42);
    mylist.push_front(21);
    mylist.pop_front();
    cout << mylist;
}