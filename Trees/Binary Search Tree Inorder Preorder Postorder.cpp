#include "bits/stdc++.h"
using namespace std;

int N;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

void preorder (struct Node *cur) {
    if (cur) {
        cout << cur->data << " ";
        preorder(cur->left);
        preorder(cur->right);
    }
}

void inorder (struct Node *cur) {
    if (cur) {
        inorder(cur->left);
        cout << cur->data << " ";
        inorder(cur->right);
    }
}

void postorder (struct Node *cur) {
    if (cur) {
        postorder(cur->left);
        postorder(cur->right);
        cout << cur->data << " ";
    }
}

void insert_into_tree (struct Node *root, int x) {
    if (x <= root->data) {
        if (root->left == NULL) {
            struct Node *newNode = new Node;
            newNode->data = x;
            newNode->left = newNode->right = NULL;
            root->left = newNode;
        } else insert_into_tree (root->left, x);
    } else if (x > root->data) {
        if (root->right == NULL) {
            struct Node *newNode = new Node;
            newNode->data = x;
            newNode->left = newNode->right = NULL;
            root->right = newNode;
        } else insert_into_tree (root->right, x);
    }
}

int main () {
    struct Node *root = new Node;
    cin >> N;
    // BST
    for (int temp = 0; temp < N; temp++) {
        int x;
        cin >> x;
        if (temp == 0) {
            root->data = x;
            root->right = NULL;
            root->left = NULL;
        } else insert_into_tree(root, x);
    }
    
    printf("Preorder : ");
    preorder(root); printf("\n");
    printf("Inorder : ");
    inorder(root); printf("\n");
    printf("Postorder : ");
    postorder(root); printf("\n");
    return 0;
}
