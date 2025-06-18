//Implementation of Linked List
#pragma once
#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    int exp;
    Node* next;  
} Node;

class linked_list
{
public:
    Node* head, *ptr;
linked_list()
{
    head = NULL;
    ptr = NULL;
}

Node* get_node()
{
    Node* new_node = new Node();
    new_node -> next = NULL;
    return new_node;
}

Node* get_head()
{
    return head;
}
void create_linked_list(int x, int exp = 0)
{
    Node* new_node = get_node();
    new_node -> data = x;
    new_node -> exp = exp;
    new_node -> next = NULL;
    head = new_node;
}
void insert_first(int x, int exp = 0)
{
    if(head == NULL)
    {
        create_linked_list(x, exp);
        return;
    }

    Node* new_node = get_node();
    new_node -> data = x;
    new_node -> exp = exp;
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

    Node* new_node = get_node();
    new_node -> data = x;

    ptr = head;
   
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = new_node;
}
// Function Used also for Polynomial
void insert_poly(int x, int exp = 1000)
{
    if(head == NULL)
    {
        create_linked_list(x, exp);
        return;
    }
    // If exponent is greater than the head exponent
     if(exp > (head->exp))
    {
        insert_first(x, exp);
        return;
    }

    Node* new_node = get_node();
    new_node -> exp = exp;
    new_node -> data = x;

    ptr = head;
   
    while(ptr->next != NULL)
    {
        //Loop only till the current exponent is smaller than that already in the list
        if(ptr -> next -> exp > exp)   
            ptr = ptr->next;
        else break;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;
    
}

void insert_anywhere(int x, int key, int exp = 0)
{
    if(head == NULL)
    {
        cout << "No linked List\n";
        return;
    }
    ptr = head;
    while(ptr != NULL && ptr->data != key)
    {
        ptr = ptr->next;
    }  

    if(ptr == NULL)
    {
        cout << "Value Not \n";
        return;
    }

    Node* new_node = get_node();
    new_node -> data = x;
    new_node -> exp = exp;
    new_node -> next = ptr -> next;
    ptr -> next = new_node;

}

void delete_node(int x)
{
    if(head == NULL)
    {
        cout << "Empty Linked List\n";
        return;
    }
    Node* prev = NULL;
    ptr = head;
    while(ptr != NULL && ptr->data != x)
    {
        prev = ptr;
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
        delete ptr;
        return;
    }

    prev->next = ptr->next;
    delete ptr;

}

void display()
{
    if(head == NULL)
    {
        cout << "Empty\n";
        return;
    }
    ptr = head;
    while(ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "Null\n";
}

void display_poly();


};
