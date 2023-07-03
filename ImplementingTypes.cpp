/// Implementing Stacks Using Array

void MyStack :: push(int x)
{
    top++;
    arr[top]=x;
}

int MyStack :: pop()
{
    if(top==-1) return -1;
    int temp=arr[top--];
return temp;
}

/// Implementing Stacks Using Single queue

/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using one queue.
void QueueStack :: push(int x)
{
    q1.push(x);
    for(int i=0;i<q1.size()-1;i++){
        q1.push(q1.front());
        q1.pop();
    }
}

//Function to pop an element from stack using one queue.
int QueueStack :: pop()
{
    if(q1.empty()) return -1;
    int element=q1.front();
    q1.pop();
    return element;
}


/// Implementing Stacks Using Two Queues

/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
    q2.push(x);
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
}

//Function to pop an element from stack using two queues.
int QueueStack :: pop()
{
    if(q1.empty()) return -1;
    int element=q1.front();
    q1.pop();
return element;
}

/// Implementing Stacks using Linked Lists

// Head of linked list would act as the top of the stack

//Function to push an integer into the stack.
void MyStack ::push(int x)
{
    StackNode *element=new StackNode(x);
    element->next=top;
    top=element;
}

//Function to remove an item from top of the stack.
int MyStack ::pop()
{
    if(!top) return -1;
    int topData=top->data;
    StackNode *temp=top;
    top=top->next;
    return topData;
}


/// Implementing Queue using Arrays

void MyQueue :: push(int x)
{
    arr[rear++]=x;
}

int MyQueue :: pop()
{
    if(front==rear) return -1;
    int temp=arr[front];
    front++;
return temp;
}

/// Implementing Queue using Two Stacks

// (2 Stacks, O(n) push)

//User function Template for C++

class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) {
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }

    input.push(x);

        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
    }

    int dequeue() {
        if(input.empty()) return -1;
        int val=input.top();
        input.pop();
    return val;
    }
};

// 2 Stacks , O(1) push

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) {
        input.push(x);
    }

    int dequeue() {
        if(output.empty()){
            while(input.size()){
                output.push(input.top());
                input.pop();
            }
        }
        int val=output.top();
        output.pop();
    return val;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";

        }
        }
    cout<<endl;
    }
}

/// Implementing Queue using 1 stack

class MyQueue {
public:
    stack<int> s1;

    void push(int x) {
        if(s1.empty()){
            s1.push(x);
            return;
        }

        int top=s1.top();
        s1.pop();
        push(x);
        s1.push(top);

        return;
    }

    int pop() {
        int top=s1.top();
        s1.pop();
        return top;
    }

    int peek() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

/// Implementing Queue using Linked Lists

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

