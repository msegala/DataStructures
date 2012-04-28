/**

    Class: DataStruct with templated arguments
    Description: Base class which holds generic functions for different data structures such as stack, queue, amd linked list

*/


#ifndef DATASTRUCT_H
#define DATASTRUCT_H

template <class ElemType>
class DataStruct
{
    public:
        DataStruct(int maxSize):m_maxSize(maxSize), m_size(0){std::cout << "Calling base constructor" << std::endl;};
        ~DataStruct(){std::cout << "Calling base destructor" << std::endl;};

        int size(){return m_size;}                     /// Get the current size of the data structure
        bool isEmpty(){return m_size == 0;}            /// Is the data structure empty
        bool isFull(){return m_size == m_maxSize;}     /// Is the data structure full
        int getMaxSize(){return m_maxSize;}            /// Get the maximum size of the data structure
        virtual void push(const ElemType&) = 0;        /// Add an element into the data structure
        virtual ElemType pop() = 0;                    /// Remove an element from the data structure
        virtual ElemType peek() = 0;                   /// Look at the current element in the data structure
        virtual void display() = 0;                    /// Display all the elements in the data structure

    protected:

        int m_size;
        int m_maxSize;

    private:
};

#endif // DATASTRUCT_H
