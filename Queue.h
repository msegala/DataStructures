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

