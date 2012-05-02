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

