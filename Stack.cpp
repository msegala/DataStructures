#include "Stack.h"

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

