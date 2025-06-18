//Implementation of Doubly Linked List

#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* prev;
    Node* next;
}Node;
Node* head, *ptr;

void create_linked_list(int x)
{
    Node* new_node = new Node();
    new_node -> data = x;
    head = new_node;
}

void insert_first(int x)
{
    if(head == NULL)
    {
        create_linked_list(x);
        return;
    }
    Node* new_node = new Node();
    new_node -> data = x;
    head->prev = new_node;
    new_node -> next = head;
    head = new_node;
}

void insert_last(int x)
{
    if(head == NULL)
    {
        create_linked_list(x);
        return;
    }
    Node* new_node = new Node();
    new_node -> data = x;
    ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node -> prev = ptr;

}

void insert_anywhere(int x , int key)
{
    if(head == NULL)
    {
        cout << "Empty Linked List\n";
        return;
    }
    ptr = head;
    Node* new_node = new Node();
    while(ptr != NULL && ptr->data != key)
    {
        ptr = ptr -> next;
    }
    if(ptr == NULL)
    {
        cout << "Key Not Found\n";
        return;
    }
    new_node -> data = x;
    new_node -> next = ptr -> next;
    ptr -> next -> prev = new_node;
    ptr -> next = new_node;
    new_node -> prev = ptr;
}

void delete_node(int x)
{
    if(head == NULL)
    {
        cout << "Empty Linked List";
        return;
    }
    ptr = head;
    while(ptr != NULL && ptr->data != x)
    {
        ptr = ptr->next;
    }
    if(ptr == NULL)
    {
        cout << "Node Not Found\n";
        return;
    }
    if(ptr == head)
    {
        head = head->next;
        if(head != NULL)
        {
            head->prev = NULL;
        }
        delete ptr;
        return;
    }

    if(ptr -> next == NULL)
    {
        ptr->prev->next = NULL;
        delete ptr;
        return;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    delete ptr;
}

void display()
{
    if(head == NULL)
    {
        cout << "Empty\n";
        return;
    }
    cout << "Null <-> "; 
    ptr = head;
    while(ptr != NULL)
    {
        cout << ptr->data << " <-> ";
        ptr = ptr->next;
    }
    cout << "Null\n";
}

int main()
{
    create_linked_list(6);
    display();
    insert_first(5);
    display();
    insert_last(8);
    display();
    insert_anywhere(7, 6);
    display();
    delete_node(7);
    display();
    delete_node(5);
    display();
    delete_node(6);
    display();
    delete_node(8);
    display();
}