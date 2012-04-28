/**

    Class: Queue with templated arguments
    Description: Derived class from base class DataStruct. Queuss work as FIFO (First In First Out) algorithms
                 where elements are inserted into one end of the container and extracted from the other.
*/



#ifndef QUEUE_H
#define QUEUE_H

#include "DataStruct.h"


template <class ElemType>
class Queue : public DataStruct<ElemType>
{
    public:
        Queue(int maxSize): DataStruct<ElemType>(maxSize), m_begin(0), m_end(0) {  que = new ElemType[DataStruct<ElemType>::m_maxSize];  }
        ~Queue() { delete [] que; }
        void push(const ElemType&);
        ElemType pop();
        ElemType peek();
        void display();

    protected:
    private:

        ElemType * que;    /// Container to hold the elements for the Queue
        int m_begin;       /// Numbered location of beginning of queue
        int m_end;         /// Numbered location of end of queue

};

#endif // QUEUE_H


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
