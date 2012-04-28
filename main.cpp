#include <iostream>
#include "Queue.h"
#include "Stack.h"
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




int main()
{
    //StackExample();
    QueueExample();

    return 0;
}
