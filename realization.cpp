#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
 
using namespace std;

template<typename T>
struct Node {
    T data;
    Node *next;
 
    Node(T x) {
        data = x;
        next = nullptr;
    }
};

template<typename T>
class List {
public:
    Node<T> *head;
    List() { head = nullptr; };
    void push_front(T x);
    void pop_front();
    void push_back(T x);
    void pop_back();
    Node<T> *insert(Node<T> *elem, T x);
    void erase(Node<T> *elem);
    Node<T> *find(T x);
    void erase(T x);
    void sort();
    bool emptycheck();
    template<typename T2>
    friend ostream &operator<<(ostream &out, List<T2> list);
    List<T> operator+(List other);
};
 
template<typename T>
void List<T>::erase(Node<T> *elem) {
    if (elem == head) {
        pop_front();
        return;
    }
    if (elem->next == nullptr) {
        pop_back();
        return;
    }
    Node<T> *ptr = head;
    while (ptr->next != elem) {
        if (ptr->next == nullptr) {
            cerr << "No such element";
            return;
        }
        ptr = ptr->next;
    }
    Node<T> *nxt = elem->next;
    ptr->next = nxt;
    delete elem;
}
 
template<typename T>
void List<T>::push_front(T x) {
    if (head == nullptr) {
        head = new Node<T>(x);
        return;
    }
    Node<T> *new_elem = new Node<T>(x);
    new_elem->next = head;
    head = new_elem;
}
 
template<typename T>
bool List<T>::emptycheck() {
    return head == nullptr;
}
 
template<typename T>
void List<T>::push_back(T x) {
    if (head == nullptr) {
        head = new Node<T>(x);
        return;
    }
    Node<T> *new_elem = new Node<T>(x);
    Node<T> *ptr = head;
    while (ptr->next) {
        ptr = ptr->next;
    }
    ptr->next = new_elem;
}
 
template<typename T>
void List<T>::pop_front() {
    if (head == nullptr) {
        cerr << "LIST IS EMPTY";
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
 
    Node<T> *deletion_elem = head;
    head = head->next;
    delete deletion_elem;
}
 
template<typename T>
void List<T>::pop_back() {
    if (head == nullptr) {
        cerr << "LIST IS EMPTY";
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
 
    Node<T> *ptr = head;
    while (ptr->next->next) {
        ptr = ptr->next;
    }
    delete ptr->next;
    ptr->next = nullptr;
}
 
template<typename T>
ostream &operator<<(ostream &out, List<T> list) {
    Node<T> *ptr = list.head;
    while (ptr) {
        out << ptr->data << " ";
        ptr = ptr->next;
    }
    return out;
}
 
template<typename T>
List<T> List<T>::operator+(List other) {
    List<T> new_list;
    Node<T> *T1 = head;
    while (T1 != nullptr) {
        new_list.push_back(T1->data);
        T1 = T1->next;
    }
 
    Node<T> *T2 = other.head;
    while (T2 != nullptr) {
        new_list.push_back(T2->data);
        T2 = T2->next;
    }
    return new_list;
}
 
template<typename T>
Node<T> *List<T>::insert(Node<T> *elem, T x) {
    Node<T> *new_elem = new Node<T>(x);
    if (elem->next) {
        Node<T> *nxt = elem->next;
        elem->next = new_elem;
        new_elem->next = nxt;
    } else {
        elem->next = new_elem;
    }
    return new_elem;
}
 
template<typename T>
Node<T> *List<T>::find(T x) {
    Node<T> *ptr = head;
    while (ptr) {
        if (ptr->data == x) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return nullptr;
}
 
template<typename T>
void List<T>::erase(T x) {
    Node<T> *ptr = find(x);
    if (!ptr) {
        cerr << "No such element";
        return;
    }
    erase(ptr);
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
