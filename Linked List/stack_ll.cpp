//Stack implementation of Linked List
#include<iostream>
#include "linked_list.h"

class stack
{
public:
    linked_list list;

    void push(int x)
    {
        list.insert_first(x);
    }

    void pop()
    {
        if(is_empty())
        {
            cout << "Stack Underflow\n";
            return;
        }

        Node* top = list.get_head();
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
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);

    st.display();
    
    st.pop();
    st.display();

    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.display();
}