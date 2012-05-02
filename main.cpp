#include <iostream>
#include "Queue.cpp"
#include "Stack.cpp"
#include "LinkedList.cpp"
#include "DataStruct.h"

using namespace std;



void StackExample(){

    Stack<int> stck(100);

    stck.push(1);
    stck.push(10);
    stck.push(34);

    stck.display();

    while(!stck.isEmpty()){

            cout << "stck peek beofore = " << stck.peek() << endl;
            cout << "stck pop = " << stck.pop() << endl;
            cout << "stck peek after= " << stck.peek() << endl;
            cout << endl;
    }

}


void QueueExample(){

    Queue<int> * que = new Queue<int>(5);

    cout << "MaxSize = " << que -> getMaxSize() << endl;
    cout << "Size = " << que -> size() << endl;

    que->push(2);
    que->push(21);
    que->push(3);
    que->display();

    while(!que->isEmpty()){

            cout << "que peek beofore = " << que->peek() << endl;
            cout << "que pop = " << que->pop() << endl;
            cout << "que peek after= " << que->peek() << endl;
            cout << endl;

    }
    delete que;

}


void LinkedListExample(){


    LinkedList<int> * ll = new LinkedList<int>;

    ll->push_front(8);
    ll->push_back(12);
    ll->push_back(33);
    ll->push_back(3);
    ll->push_before_nth_node(132, 2);
    ll->pop_front();
    ll->pop_back();
    ll->pop_nth_node(2);
    ll->print();

    std::cout << "Total nodes / average = " << ll->count_nodes() << " / " << ll->average() << std::endl;


    delete ll;

}





int main()
{
    //StackExample();
    //QueueExample();
    LinkedListExample();


    return 0;
}
