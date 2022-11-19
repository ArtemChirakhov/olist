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
    List<T> operator+(List a);
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
template <typename T>
List<T> List<T>::operator+(List l)
{
    List<T> new_list;
    Node<T>* T1 = head;
    while (T1 != nullptr && T1 -> next != nullptr)
    {
        new_list.push_back(T1 -> data);
        T1 = T1 -> next;
    }
    if (T1 != nullptr){
        new_list.push_back(T1 -> data);
    }
    Node<T>* T2 = l.head;
    while (T2 != nullptr)
    {
        new_list.push_back(T2 -> data);
        T2 = T2 -> next;
    }

    //List<T> copy_2 = l;
    /*Node<T>* T1 = copy_1.head;
    while(T1 != nullptr){
        T1 = copy_1.head;
        new_list.push_back(T1 -> data);
        copy_1.pop_front();
    }
    
    Node<T>* T2 = copy_2.head;
    while(T2 != nullptr){
        T2 = copy_2.head;
        new_list.push_back(T2 -> data);
        copy_2.pop_front();
    }*/
    return new_list;
}

int main(){
    List<int> mylist;
    List<int> mylist1;
    mylist.push_front(42);
    mylist.push_front(21);
    mylist.push_front(415);
    mylist.push_front(324);
    mylist.push_front(945);
    mylist.push_front(124);
    mylist1.push_front(213);
    mylist1.push_front(41);
    mylist1.push_front(75);
    mylist1.push_front(123);
    mylist.pop_front();
    mylist.pop_back();
    cout << mylist;
    cout << mylist1;
    List<int> new_list;
    new_list = mylist1 + mylist;
    cout << new_list;
}