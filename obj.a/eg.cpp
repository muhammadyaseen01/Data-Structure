#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;
    
    Node(int key) : key(key), left(nullptr), right(nullptr) {}
};

Node* insertMaxHeap(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    
    if (key > root->key) {
        std::swap(key, root->key);
    }
    
    if (key < root->key) {
        if (root->left == nullptr) {
            root->left = new Node(key);
        } else {
            insertMaxHeap(root->left, key);
        }
    }
    
    return root;
}
void mirror(Node* node) {
    if (node == nullptr) {
        return;
    } else {
        mirror(node->left);
        mirror(node->right);

        std::swap(node->left, node->right);
    }
}

// void mirror(Node* node ){
//     if(node == NULL){
//         return;
//     }
//     else{

//         // Trees* temp;
//         mirror(node->left);
//         mirror(node->right);


//         std::swap (node->left, node->right);
//         // temp = node->left;
//         // node->left = node->right;
//         // node->right = temp;
//     }
// }

void printHeap(Node* root) {
    if (root) {
        std::cout << root->key << " ";
        printHeap(root->left);
        printHeap(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int elements[] = {4, 10, 7, 9, 2, 8};
    int numElements = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < numElements; i++) {
        root = insertMaxHeap(root, elements[i]);
    }

    std::cout << "Max Heap: ";
    printHeap(root);
    std::cout<<std::endl;
    mirror(root);
    printHeap(root);


    return 0;
}
