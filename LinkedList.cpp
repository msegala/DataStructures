#include <iostream>
#include "LinkedList.h"


template <class ElemType>
LinkedList<ElemType>::~LinkedList(){

    node<ElemType> * temp = new node<ElemType>;

    while ( head != NULL ){

        temp = head;
        head = head -> next;
        delete temp;

    }

}


template <class ElemType>
void LinkedList<ElemType>::push_back(ElemType data){

    /**
        Insert a node into the last position of the list
    */

    if (head == NULL){

        head = new node<ElemType>;
        head -> data = data;
        head -> next = 0;

    }
    else{

        ///Insert from back
        node<ElemType> * back = new node<ElemType>;
        back = head;                     ///point to head

        while ( back->next != NULL ){
            back = back -> next;         ///find the last node<ElemType>
        }

        node<ElemType> * temp = new node<ElemType>;
        temp -> data = data;
        temp -> next = 0;               ///Have the temp point to a null address

        back -> next = temp;            ///assign the new node in the next free spot
    }

}



template <class ElemType>
void LinkedList<ElemType>::push_front(ElemType data){

    /**
        Insert a node into the first position of the list
    */

    node<ElemType> * temp = new node<ElemType>;
    temp -> data = data;
    temp -> next = head;     ///Have the next node of temp point to the current head
    head = temp;             ///Have address of head now be temp, head always must be the first node


}


template <class ElemType>
int LinkedList<ElemType>::push_before_nth_node(ElemType data, int location){

    /**
        Insert a new node in a predetermined location
    */

    if (location > count_nodes())
        {std::cout << "Only have " << count_nodes() << " nodes, cannot insert in list position " << location << std::endl; return 0;}

    node<ElemType> * temp = new node<ElemType>;
    temp = head;

    int count = 0;
    while ( count < location - 1){

        count ++ ;
        temp = temp -> next;       ///Will hold the address of the node before doing the insertion

    }

    node<ElemType> * tmp = new node<ElemType>;         ///Create new node
    tmp -> data = data;            ///
    tmp -> next = temp -> next;    ///Transfer address of temp -> next to tmp -> next
    temp -> next = tmp;            ///Transfer the address of temp->next to tmp

}


template <class ElemType>
void LinkedList<ElemType>::pop_front(){

    /**
        Remove the first node in the list
    */

    node<ElemType> * temp = new node<ElemType>;

    if (head -> next != NULL){

        temp = head;
        head = temp -> next;     ///Make the head point to the second node
        delete temp;             ///Free the memory used for the old HEAD
    }

}


template <class ElemType>
void LinkedList<ElemType>::pop_back(){

    /**
        Remove the last node in the list
    */

    node<ElemType> * temp = new node<ElemType>;
    temp = head;
    node<ElemType> * old_temp = new node<ElemType>;

    while ( temp -> next != NULL ){

        old_temp = temp;                  ///Save the second to last node
        temp = temp -> next;

    }

    old_temp -> next = 0;                ///When at the last node, make the second to last point to an empty memory location
    delete temp;                         ///Free the memory of the last node

}



template <class ElemType>
int LinkedList<ElemType>::pop_nth_node(int location){

    /**
        Delete a node from a predetermined location
    */

    if (location < 1)
        {std::cout << "Cannot remove the node" << std::endl; return 0;}

    if (location > count_nodes())
        {std::cout << "Only have " << count_nodes() << " nodes, cannot delete in list position " << location << std::endl; return 0;}

    /// Protect against removing the head
    if (location == 1) {
        pop_front();
        return 0;
    }

    node<ElemType> * temp = new node<ElemType>;
    temp = head;
    node<ElemType> * old_temp = new node<ElemType>;


    int count = 0;
    while ( count < location - 1){

        count ++ ;
        old_temp = temp;                  ///Save the second to last node
        temp = temp -> next;

    }

    old_temp -> next = temp -> next;      ///Make the (node - 1) point to the (node + 1)
    delete temp;

    return 0;

}




template <class ElemType>
void LinkedList<ElemType>::print(){

    /**
        Print all the data values in the nodes
    */

    node<ElemType> * temp = new node<ElemType>;
    temp = head;               ///Point the temp address to head
    while (temp != NULL){      ///Loop over all nodes until find the empt one

        std::cout << temp -> data << std::endl;
        temp = temp -> next;                       ///Point to the net node

    }

    delete temp;
}



template <class ElemType>
int LinkedList<ElemType>::count_nodes(){

    /**
        Count number of nodes in the list
    */

    node<ElemType> * temp = new node<ElemType>;
    temp = head;

    int count = 0;
    while ( temp != NULL){
        count ++ ;
        temp = temp -> next;
    }

    delete  temp;
    return count;

}



template <class ElemType>
double LinkedList<ElemType>::average(){

    /**
        Return the average value of the nodes
    */

    node<ElemType> * temp = new node<ElemType>;
    temp = head;

    double avg = 0;
    int count = 0;

    while( temp != NULL ){

        count ++ ;
        avg += temp -> data;
        temp = temp -> next;

    }

    avg /= count;

    delete temp;
    return avg;

}


//void sort(node *& head){}
