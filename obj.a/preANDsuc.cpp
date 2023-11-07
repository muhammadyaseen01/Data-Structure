

Node* inpre(Node* root){
    Node* p = root->left;
    while(p->right){
        p = p->right;
    }
    return p;
}
Node* inSuc(Node* root){
    Node* p = root->right;
    while(p->left){
        p = p->left;
    }
    return p;
}

void find(){
    if(!root){
        return;
    }
    if(root->key == key){
        if(root->left) 
            pre = inpre(root);
        if(root->right)
            suc = inSuc(root);
        return;
    }if(key > root->key){
        pre = root;
        find(root->right,pre,suc,key;)
    }
    else if(key < root->key){
        suc = root;
        find(root->left,pre,suc,key;)
    }
}