// Takes two binary trees T1 and T2 as input, and perform the following tasks:
// * Check T1 and T2 are mirror image of each other.


#include<iostream>
using namespace std;
struct Trees
{
    int data;
    Trees *left;
    Trees *right;
};

struct Trees *start = NULL;

Trees *insert(Trees *node,int data)
{
    if (node == NULL)
    {
        struct Trees *temp = new Trees();
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    else if(data < node->data)
    {
        node->left = insert(node->left,data);
    }
    else
    {
        node->right = insert(node->right,data);
    }
    return node;
}

// bool mirror(Trees *T1, Trees *T2)
// {
//     if(T1 == NULL && T2 == NULL)
//     {
//         return true;
//     }
//     if(T1 == NULL || T2 == NULL)
//     {
//         return false;
//     }
//     if(T1->data == T2->data)
//     {
//         return mirror(T1->right,T2->right) && mirror(T1->left,T2->left);
//     }
//     return false;
// }

void mirror(Trees* node ){
    if(node == NULL){
        return;
    }
    else{

        // Trees* temp;
        mirror(node->left);
        mirror(node->right);


        swap (node->left, node->right);
        // temp = node->left;
        // node->left = node->right;
        // node->right = temp;
    }
}

void preorder(Trees *node)
{
    if(node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

int main()
{
    struct Trees *root1 = NULL;
    root1 = insert(root1,3);
    insert(root1,1);
    insert(root1,5);
    insert(root1,7);
    insert(root1,8);
    insert(root1,3);
    insert(root1,4);

    // struct Trees *root2 = NULL;
    // root2 = insert(root2,3);
    // insert(root2,5);
    // insert(root2,1);

    cout << "Tree T1: ";
    preorder(root1);
    cout << endl;

    // cout << "Tree T2: ";
    // preorder(root2);
    // cout << endl;

    // if(mirror(root1,root2))
    // {
    //     cout <<"Trees are mirror image. ";
    // }
    // else
    // {
    //     cout <<"Trees are not mirror image. ";
    // }

    mirror(root1);
    cout << "mirror of T1: ";
    preorder(root1);
    cout << endl;
    return 0;
}