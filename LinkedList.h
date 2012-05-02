/**

    Class: LinkedList with templated arguments
    Description: Derived class from base class DataStruct. Linked List.....

*/


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "DataStruct.h"

template<class ElemType>
struct node{
    ElemType data;
    node<ElemType> *next;
};


template <class ElemType>
class LinkedList: public DataStruct<ElemType>
{
    public:
        LinkedList(){ head = NULL; };
        ~LinkedList();

        void push_back(ElemType data);                             ///Add node to end of the list
        void push_front(ElemType data);                            ///Add node to front of the list
        int push_before_nth_node(ElemType data, int location);     ///Add node before nth node in the list
        void pop_front();                                          ///Remove node from front of the list
        void pop_back();                                           ///Remove node from end of the list
        int pop_nth_node(int location);                            ///Remove nth node from the list
        void print();                                              ///Print the contents of the list
        int count_nodes();                                         ///Count number of nodes in the list
        double average();                                          ///Find the average value in the list

        void push(const ElemType&){};
        ElemType pop(){return 0;};
        ElemType peek(){return 0;};
        void display(){};

    protected:
    private:

        node<ElemType> * head;

};

#endif // LINKEDLIST_H
