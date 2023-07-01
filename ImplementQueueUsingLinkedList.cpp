/*
Implement a Queue using Linked List.
A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop an element from the queue and print the poped element)

Example 1:
Input:
Q = 5
Queries = 1 2 1 3 2 1 4 2
Output: 2 3
Explanation: n the first testcase
1 2 the queue will be {2}
1 3 the queue will be {2 3}
2   poped element will be 2 the
    queue will be {3}
1 4 the queue will be {3 4}
2   poped element will be 3.

Example 2:
Input:
Q = 4
Queries = 1 2 2 2 1 3
Output: 2 -1
Explanation: In the second testcase
1 2 the queue will be {2}
2   poped element will be {2} then
    the queue will be empty.
2   the queue is empty and hence -1
1 3 the queue will be {3}.
Your Task:
Complete the function push() which takes an integer as input parameter and pop() which will remove and return an element(-1 if queue is empty).

Expected Time Complexity: O(1).
Expected Auxiliary Space: O(1).
*/

/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.
void MyQueue:: push(int x)
{
    QueueNode *temp=new QueueNode(x);
    if(!front){
        front=rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    if(!front) return -1;
    QueueNode *temp = front;
    front = front->next;
    int value=temp->data;
    delete temp;
    return value;
}

/// Complete Program

#include<bits/stdc++.h>
using namespace std;

class QueueNode
{
 public:
    int val;
    QueueNode *next;
    QueueNode(int data)
    {
       val = data;
       next = nullptr;
    }
};
QueueNode *Front = nullptr, *Rare = nullptr;

class Queue
{
public:
    int size = 0;
    bool Empty();
    void Enqueue(int value);
    void Dequeue();
    int Peek();
};
bool Queue ::  Empty()
{
    return Front == nullptr;
}
int Queue :: Peek()
{
    if(Empty())
     {  cout<<"Queue is Empty"<<endl;
        return -1;
     }
    else
      return Front->val;
}
void Queue :: Enqueue(int value)
{
    QueueNode *Temp;
    Temp = new QueueNode(value);
    if (Temp == nullptr)  //When heap exhausted
        cout << "Queue is Full" << endl;
    else
    {
        if (Front == nullptr)
        {
            Front = Temp;
            Rare = Temp;
        }
        else
        {
            Rare->next = Temp;
            Rare = Temp;
        }
        cout<<value <<" Inserted into Queue "<<endl;
        size++;
    }
}
void Queue :: Dequeue()
{
    if (Front == nullptr)
        cout << "Queue is Empty" << endl;
    else
    {
        cout<<Front->val <<" Removed From Queue"<<endl;
        QueueNode *Temp = Front;
        Front = Front->next;
        delete Temp;
        size--;
    }
}
int main()

{
    Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    Q.Dequeue();
    cout<<"The size of the Queue is "<<Q.size<<endl;
    cout<<"The Peek element of the Queue is "<<Q.Peek()<<endl;
    return 0;
}
