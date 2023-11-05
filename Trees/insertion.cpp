#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BST_Node
{
    int val;
    BST_Node *left = NULL;
    BST_Node *right = NULL;
};

BST_Node *insert_At_BST(BST_Node *node, int val) // repeated value not allowed
{
    int new_val = val;
    if (node == NULL)
    {
        BST_Node *new_node = new BST_Node; // contruct a pointer which point on new node user want to insert
        new_node->val = new_val;           // storing value of input in new node k val me
        // cout<< "value has been inserted!"<<endl;
        return 0;
    }
    if (node->val > new_val)
    {
        node->left = insert_At_BST(node->left, val);
    }
    else if (node->val < new_val)
    {
        node->right = insert_At_BST(node->right, val);
    }
    cout << "value has been inserted!" << endl;
    return 0;
}

int main()
{
    BST_Node *root = NULL;

    int n;
    cout << "enter how many node you want to enter: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int new_val; // initialize var for input
        cout << "\t 1.enter the value: ";
        cin >> new_val; // taking input
        insert_At_BST(root, new_val);
        // cout<<"okay";
        insert_At_BST(root, new_val);
        insert_At_BST(root, new_val);
    }
    return 0;
}