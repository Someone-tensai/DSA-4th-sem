#include "linked_list.h"
int main()
{
    linked_list list;
    list.create_linked_list(6);
    list.display();
    list.insert_first(5);
    list.display();
    list.insert_last(8);
    list.display();
    list.insert_last(4);
    list.display();
    list.insert_anywhere(7, 6);
    list.display();
    list.delete_node(7);
    list.display();
    list.delete_node(5);
    list.display();
    list.delete_node(6);
    list.display();
    list.delete_node(8);
    list.display();
}