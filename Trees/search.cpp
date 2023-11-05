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
//-----------------------INSERTION------------------------------------//
BST_Node *insert_At_BST(BST_Node *node, int val) // repeated value not allowed
{
    int new_val = val;
    if (node == NULL)
    {
        BST_Node *new_node = new BST_Node; // contruct a pointer which point on new node user want to insert
        new_node->val = new_val;           // storing value of input in new node k val me
        // cout<< "value has been inserted!"<<endl;
        return new_node;
    }
    if (node->val > new_val)
    {
        node->left = insert_At_BST(node->left, val);
    }
    else if (node->val < new_val)
    {
        node->right = insert_At_BST(node->right, val);
    }
    // cout << "value has been inserted!" << endl;
    return node;
}

//-----------------------TRAVERSALS------------------------------------//
void preorder(BST_Node *node)
{
    if (node == NULL)
    {
        return;
    }

    cout << node->val << ", ";
    preorder(node->left);
    preorder(node->right);
}
void inorder(BST_Node *node)
{
    if (node == NULL)
    {
        return;
    }

    inorder(node->left);
    cout << node->val << ", ";
    inorder(node->right);
}
void postorder(BST_Node *node)
{
    if (node == NULL)
    {
        return;
    }

    postorder(node->left);
    postorder(node->right);
    cout << node->val << ", ";
}
//-----------------------SEARCHING------------------------------------//

BST_Node *Search_In_BST(BST_Node *node, int val)
{
    int new_val= val;
    if (node == NULL)
    {
        return NULL;
    }
    if(new_val == node->val){
        return node;
    }
    else if (new_val > node->val)
    {
        return Search_In_BST(node->right, val);
    }
    else { // new_val < node->val
        return Search_In_BST (node->left , val);
    }
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
        root = insert_At_BST(root, new_val);
        // cout<<"okay";
        insert_At_BST(root, new_val);
        insert_At_BST(root, new_val);
    }
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;

    // BST_Node *searched = Search_In_BST(root, 4);
    if(Search_In_BST(root, 4) == NULL){
        cout<< "Value doesnot exist! "<<endl;
    }else{
        cout<<"Value Exist! "<<endl;
        cout<<"Value is: "<<Search_In_BST(root, 4)->val<<endl;
    }
    return 0;
}