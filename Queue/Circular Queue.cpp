// Implementation of Circular Queue
#include<iostream>
using namespace std;
#define MAX_SIZE 3

template <typename T>
class circ_queue{
    public:
        T data[MAX_SIZE];
        int front = -1;
        int rear = -1;

        void enqueue(T x)
        {
            if(((rear+1) % MAX_SIZE) == front)
            {
                cout << "Queue is Full\n";
                return;
            }
            if(front == -1)
            {
                front = 0;
                rear = 0;
            }
            else
            {
                rear = (rear+1) % MAX_SIZE;
            }
            data[rear] = x;
        }

        T dequeue()
        {
            if(front == -1)
            {
                cout << "Queue is Empty(de)\n";
                return T();
            }
            T temp = data[front];
            if(front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % MAX_SIZE;
            }
            return temp;
        }

        void display()
        {
            if(rear == -1)
            {
                cout << "Queue is Empty(di)\n";
                return;
            }
            int r = rear % MAX_SIZE;
            
            for(int i = front ; i != rear; i=(i+1) % MAX_SIZE)
            {
                
                cout << data[i] << "\n";

            }
        }

};
int main()
{
    circ_queue<int> q;
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    q.dequeue();
    q.dequeue();
    q.enqueue(7);
    q.enqueue(8);
    q.display();

}