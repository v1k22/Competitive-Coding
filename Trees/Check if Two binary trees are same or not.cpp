#include "bits/stdc++.h"
using namespace std;

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

int n;
int m;
struct Node *root = new Node;
struct Node *root2 = new Node;

void print_Tree(struct Node *cur);

void insert(struct Node *cur, int X) {
  if (X > cur->data) {
    if (cur->right != NULL) insert(cur->right, X);
    else {
      struct Node *newNode = new Node;
      newNode->data = X;
      newNode->right = newNode->left = NULL;
      cur->right = newNode;
    }
  } else {
    if (cur->left != NULL) insert(cur->left, X);
    else {
      struct Node *newNode = new Node;
      newNode->data = X;
      newNode->right = newNode->left = NULL;
      cur->left = newNode;
    }
  }
}

bool Compare_Trees(struct Node *cur1, struct Node *cur2) {
  if (cur1 == NULL && cur2 == NULL)
    return true;
  if ((cur1 == NULL && cur2 != NULL) || (cur1 != NULL && cur2 == NULL))
    return false;
  if (cur1->data == cur2->data) {
    return Compare_Trees(cur1->left, cur2->left) &&
           Compare_Trees(cur1->right, cur2->right);
  } else return false;
}

int main () {
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (i == 0) {
      root->data = x;
      root->left = NULL;
      root->right = NULL;
    }
    else insert(root, x);
  }
  
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    if (i == 0) {
      root2->data = x;
      root2->left = root2->right = NULL;
    }
    else insert(root2, x);
  }
  
  printf( (Compare_Trees(root, root2))? "Equal\n" : "Not Equal\n" );
  return 0;
}

void print_Tree(struct Node *cur) {
  if (cur != NULL) {
    print_Tree(cur->left);
    printf("%d ", cur->data);
    print_Tree(cur->right);
  }
}
