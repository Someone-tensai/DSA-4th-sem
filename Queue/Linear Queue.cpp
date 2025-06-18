//Implementation of Linear Queue
#include<iostream>
using namespace std;
#define MAX_SIZE 100

template <typename T>
class queue{
    public:
        T data[MAX_SIZE];
        int front = 0;
        int rear = -1;

        void enqueue(T x)
        {
            if(rear == MAX_SIZE-1)
            {
                cout << "Queue is Full\n";
                return;
            }
            data[++rear] = x;
        }

        T dequeue()
        {
            if(front > rear)
            {
                cout << "Queue is Empty(de)\n";
                return T();
            }

            return data[front++];
        }

        void display()
        {
            if(front > rear)
            {
                cout << "Queue is Empty(di)\n";
                return;
            }

            for(int i = front ; i <= rear ; i++)
            {
                cout << data[i] << "\n";
            }
        }
};
int main()
{
    queue<int> q;
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();

}