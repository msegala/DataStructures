#include "Queue.h"



template <class ElemType>
void Queue<ElemType>::push( const ElemType& val )
{
    if ( DataStruct<ElemType>::isFull() ) { std::cout << "Queue is full" << std::endl; return;}

    que[m_end] = val;
    m_end++;
    DataStruct<ElemType>::m_size++;

    /// Check for wrap-around
    if ( m_end == DataStruct<ElemType>::m_maxSize - 1 )
        m_end -= DataStruct<ElemType>::m_maxSize-1;


}

template <class ElemType>
ElemType Queue<ElemType>::pop()
{

    if ( DataStruct<ElemType>::isEmpty() ) { std::cout << "Queue is empty" << std::endl; return -1;}

    ElemType tmp = que[m_begin];
    m_begin++;
    DataStruct<ElemType>::m_size--;

      /// Check for wrap-around
    if (m_begin == DataStruct<ElemType>::m_maxSize - 1)
        m_begin -= DataStruct<ElemType>::m_maxSize-1;

    return tmp;

}

template <class ElemType>
ElemType Queue<ElemType>::peek()
{
    return que[m_begin];
}


template <class ElemType>
void Queue<ElemType>::display()
{

    std::cout << "Queue contains [" ;
    for (int i = m_begin; i < m_end; ++i){
        std::cout << que[i] ;

        if (i < m_end - 1 ) std::cout << ", " ;

    }
    std::cout << "]" << std::endl;

}


