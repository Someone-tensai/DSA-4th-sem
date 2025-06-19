//Queue implementation of Linked List
#include<iostream>
#include "linked_list.h"
using namespace std;

class queue
{
public:
    linked_list list;

    void enqueue(int x)
    {
        list.insert_first(x);
    }

    void dequeue()
    {
        if(is_empty())
        {
            cout << "Queue Underflow\n";
            return;
        }

        Node* top = list.get_head();
        while(top->next != NULL)
        {
            top = top->next;
        }
        list.delete_node(top->data);

    }

    bool is_empty()
    {
        return list.get_head() == NULL;
    }

    void display()
    {
        list.display();
    }
};
int main()
{
    int choice;
    queue qu;
    cout << "Queue \n";
    
    int exit = 0;
    while(!exit)
    {
        cout << "1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n\n";
        cin >> choice;
        switch(choice)
        {
            case 1: 
                int x;
                cout << "Enter the Data to Enqueue: ";
                cin >> x;
                qu.enqueue(x);
                break;
            
            case 2: 
                qu.dequeue();
                break;
            
            case 3: 
                qu.display();
                break;
            
            case 4:
                exit = 1;
                break;

            default:
                cout << "Enter Valid Number(1-4)\n";
                break;

        }
    }
}