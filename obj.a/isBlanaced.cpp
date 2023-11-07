#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (isBalanced(root->left == false))
    {
        return false;
    }
    if (isBalanced(root->right == false))
    {
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs((lh - rh) <= 1))
    {
        return true;
    }
    else{
        return false;
    }
}

int main()
{


    if(isBalanced(root)){
        cout<<"Balanced tree"<<endl;
    }else{
        cout<<"Unbalanced tree"<<endl;

    }
    return 0;
}