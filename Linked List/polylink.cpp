//Addition of two polynomial equations using Linked List
#include "linked_list.h"
#include<iostream>
using namespace std;

//Function to add two lists and return the added list
linked_list add_lists(linked_list list1 , linked_list list2)
{
    Node* head1 = list1.get_head();
    Node* head2 = list2.get_head();
    if(head1 == NULL) return list2;
    if(head2 == NULL) return list1;

    linked_list added;
    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1 != NULL && temp2 != NULL)
    {
        //If the exponent of the term in both the lists is equal, merge and add
        if (temp1->exp == temp2->exp)
        {
            added.insert_poly(temp1->data + temp2->data , temp2->exp);
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }

        //If the exponent of one of them is higher, add only that and contine

        else if(temp1->exp > temp2->exp)
        {
            added.insert_poly(temp1->data , temp1->exp);
            temp1 = temp1 -> next;
        }
        else
        {
            added.insert_poly(temp2->data, temp2->exp);
            temp2 = temp2 -> next;
        }        
    }
    
    // Edge Case If There's lower exponent in one but not another as it will be missed(We are only adding greater cases)
    while(temp1 != NULL)
    {
        added.insert_poly(temp1->data , temp1->exp);
        temp1 = temp1 -> next;
    }
    while(temp2 != NULL)
    {
        added.insert_poly(temp2->data, temp2->exp);
        temp2 = temp2 -> next;
    }

    return added;
}

void linked_list::display_poly()
{
    if(head == NULL) 
    {
        cout << "Empty Polynomial\n"; 
        return;
    }
    cout << "Polynomial: ";
    Node* ptr = head;
    while(ptr != NULL)
    {
    
        if(ptr->exp == 1)
        {
            cout << ptr->data << "x";
            ptr = ptr->next;
            continue;
        }
        cout << ptr->data << "x^" << ptr->exp;
        if(ptr->next != NULL)
            cout << " + ";
        ptr = ptr->next;
    }
    cout << "\n";
}

int main()
{
    linked_list list1;
    list1.insert_poly(2,4);
    list1.insert_poly(3,2);
    list1.insert_poly(0,1);
    list1.insert_poly(2, 3);

    list1.display_poly();

    linked_list list2;
    list2.insert_poly(3,3);
    list2.insert_poly(5,2);
    list2.insert_poly(1,1);
    list2.display_poly();

    linked_list added_list = add_lists(list1 , list2);
    added_list.display_poly();

}