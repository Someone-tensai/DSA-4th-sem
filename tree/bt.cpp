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

    // Insertion in BST
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

    // In-order traversal in BST
    Node* traverse(Node* root, Node* &prev, int data=-1, int flag=1)
    {
        if(root == nullptr)
        {
            return nullptr;
        }

        Node* left = traverse(root->left_ptr,prev , data , flag);
        if(left)
        {
            return left;
        }

        if(prev && prev->data == data)
        {
            return root;
        }
        prev = root;
        if(flag == 1) cout << root->data << " ";

        Node* right =  traverse(root->right_ptr, prev,data, flag);
        return right;
    }

    // Searching in BST
    Node* search(int data, Node* &parent, int flag=1)
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
                if(flag == 1) cout << "Node "<< data << " Found\n";
                return ptr;
            }
            parent = ptr;
          
            if(data < ptr->data) ptr = ptr ->left_ptr;
            else if(data > ptr->data) ptr = ptr -> right_ptr;
        }
        if(ptr == nullptr)
        {
            cout << "Node " << data <<" Not Found\n";
        }
        return ptr;
    }
    
    Node* inorder_succesor(int data)
    {
        Node* prev = nullptr;
        Node* successor = traverse(root, prev, data, 0);
        return successor;
    }

    // Deleting in BST
    void delete_node(int data, int flag=1)
    {
        if(root == nullptr)
        {
            cout << "Empty Tree\n";
            return;
        }
        Node* parent = nullptr;
        Node* ptr = search(data, parent, 0);
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
            delete_node(in_order_data,0);
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
        if(flag == 1) cout << "Node " << data << " Deleted\n";
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
    bst.insert(2);
    bst.insert(15);
    bst.insert(11);
    cout << "Insertion Done\n";

    prev = nullptr;
    bst.traverse(bst.root, prev);
    cout << "\n";
    bst.search(3,parent);
    bst.search(7, parent);
  
    bst.delete_node(3);
    prev = nullptr;
    bst.traverse(bst.root, prev);
    cout << "\n";

    bst.delete_node(7);
    prev = nullptr;
    bst.traverse(bst.root, prev);
    cout << "\n";

    bst.delete_node(15);
    prev = nullptr;
    bst.traverse(bst.root, prev);
    cout << "\n";

    bst.search(3,parent);

}