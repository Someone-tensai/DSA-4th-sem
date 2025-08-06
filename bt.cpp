#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* left_ptr;
    Node* right_ptr;
}Node;

class BST
{
public:
    Node* root;

    BST():root{nullptr}{}

    Node* get_node(int x)
    {
        Node* new_node = new Node();
        new_node -> data = x;
        new_node -> left_ptr = nullptr;
        new_node -> right_ptr = nullptr;
        return new_node;
    }

    void insert(int data)
    {
        if(root == nullptr)
        {
            root = get_node(data);
        }
        Node* ptr = root;
        Node* parent = nullptr;
        while(ptr != nullptr)
        {
            parent = ptr;
            if(data < ptr->data) ptr = ptr ->left_ptr;
            else if(data > ptr->data) ptr = ptr -> right_ptr;
            else return;
        }
       
        if(data < parent->data) parent->left_ptr = get_node(data);
        else parent->right_ptr = get_node(data);
            
        
    }
    Node* traverse(Node* root, Node* &prev, int data=-1)
    {
        if(root == nullptr)
        {
            return nullptr;
        }

        Node* left = traverse(root->left_ptr,prev , data);
        if(left)
        {
            return left;
        }

        if(prev && prev->data == data)
        {
            return root;
        }
        prev = root;
        cout << root->data << "\n";
        Node* right =  traverse(root->right_ptr, prev,data);
        return right;
    }

    Node* search(int data, Node* &parent)
    {
        if(root ==  nullptr) 
        {
            cout << "Empty Tree(s)\n";
            return root;
        }        
        Node* ptr = root;
        while(ptr != nullptr)
        {
            if(data == ptr->data) 
            {
                cout << "Node Found\n";
                return ptr;
            }
            parent = ptr;
          
            if(data < ptr->data) ptr = ptr ->left_ptr;
            else if(data > ptr->data) ptr = ptr -> right_ptr;
        }
        if(ptr == nullptr)
        {
            cout << "Node Not Found\n";
        }
        return ptr;
    }

    Node* inorder_succesor(int data)
    {
        Node* prev = nullptr;
        Node* successor = traverse(root, prev, data);
        return successor;
    }
    void delete_node(int data)
    {
        if(root == nullptr)
        {
            cout << "Empty Tree\n";
            return;
        }
        Node* parent = nullptr;
        Node* ptr = search(data, parent);
        if(ptr == nullptr)
        {
            return;
        }
        if(ptr->left_ptr == nullptr && ptr->right_ptr == nullptr)
        {
            if(parent == nullptr)
            {
                delete root;
                root = nullptr;
                return;
            }
        
            if(parent->right_ptr == ptr) parent->right_ptr = nullptr;
            else parent->left_ptr = nullptr;
            delete ptr;
        }
        else if(ptr->left_ptr != nullptr && ptr->right_ptr != nullptr)
        {
            // Find Inorder Successor
            Node* in_order = inorder_succesor(data);
            if(in_order == nullptr) return;
            int in_order_data = in_order -> data;
            // Replace Node with Inorder Succesor

            // Delete the Inorder Succesor
            delete_node(in_order_data);
            ptr -> data = in_order_data;

        }
        else if(ptr->left_ptr != nullptr || ptr->right_ptr != nullptr)
        {
            if(parent == nullptr)
            {
                root = (ptr->left_ptr != nullptr) ?ptr->left_ptr: ptr->right_ptr;
                delete ptr;
                return;
            }
            if(ptr->left_ptr != nullptr)
            {
                if(parent->right_ptr == ptr) parent->right_ptr = ptr->left_ptr;
                else parent->left_ptr = ptr->left_ptr;

                delete ptr;
            }

            else if(ptr->right_ptr != nullptr)
            {
               if(parent->right_ptr == ptr) parent->right_ptr = ptr->right_ptr;
                else parent->left_ptr = ptr->right_ptr;

                delete ptr;
            }
        }
    }
};

int main()
{
    Node* parent = nullptr;
    Node* prev = nullptr;
    BST bst;
    bst.insert(3);
    bst.insert(4);
    bst.insert(5);
    bst.insert(7);
    bst.insert(2);
    bst.insert(1);
    bst.insert(0);
    bst.insert(8);
    bst.insert(9);
    bst.insert(15);
    bst.insert(13);
    bst.insert(12);
    bst.insert(11);
    cout << "Insertion Done\n";

    bst.traverse(bst.root, prev);
    // bst.search(3,parent);
    // bst.search(7, parent);
    // bst.search(4,parent);
  
    bst.delete_node(5);
    cout << "Deleted 5\n";
    bst.delete_node(3);
    cout << "Deleted 3\n";
    bst.delete_node(7);
    cout << "Deleted 7\n";
    bst.delete_node(15);
    cout << "Deleted 15\n";
    bst.delete_node(5);
    cout << "Deleted 5\n";
    prev = nullptr;
    bst.traverse(bst.root, prev);
    bst.search(3,parent);

}