/**

    Class: Stack with templated arguments
    Description: Derived class from base class DataStruct. Stacks work as LIFO (Last In First Out) algorithms
                 where elements are inserted and extracted only from the end of the container.
*/



#ifndef STACK_H
#define STACK_H

#include "DataStruct.h"


template <class ElemType>
class Stack : public DataStruct<ElemType>
{
    public:
        Stack(int maxSize):DataStruct<ElemType>(maxSize){ stck = new ElemType[DataStruct<ElemType>::m_maxSize]; };
        ~Stack(){ delete [] stck; }
        void push(const ElemType&);
        ElemType pop();
        ElemType peek();
        void display();

    protected:
    private:

        ElemType* stck;    /// Container to hold the elements for the Stack
};

#endif // STACK_H


template <class ElemType>
void Stack<ElemType>::push( const ElemType & val )
{
    if ( DataStruct<ElemType>::isFull() ) { std::cout << "Stack is full" << std::endl; return;}

    stck[DataStruct<ElemType>::m_size] = val;
    DataStruct<ElemType>::m_size++;
}


template <class ElemType>
ElemType Stack<ElemType>::pop()
{
    if ( DataStruct<ElemType>::isEmpty() ) { std::cout << "Stack is empty" << std::endl; return -1;}

    DataStruct<ElemType>::m_size--;
    return stck[DataStruct<ElemType>::m_size];
}


template <class ElemType>
ElemType Stack<ElemType>::peek()
{
    return stck[DataStruct<ElemType>::m_size];
}


template <class ElemType>
void Stack<ElemType>::display()
{

    std::cout << "Stack contains [" ;
    for (int i = 0; i < DataStruct<ElemType>::m_size; ++i){
        std::cout << stck[i] ;

        if (i < DataStruct<ElemType>::m_size - 1 ) std::cout << ", " ;

    }
    std::cout << "]" << std::endl;

}
