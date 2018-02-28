#include "bits/stdc++.h"
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = new Node;;

void init(int x) {
    head->data = x;
    head->next = NULL;
}

void append(int x) {
    struct Node *newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    struct Node *cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
}

void print_list() {
    struct Node *cur = head;
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void delete_from_list(int q) {
    struct Node *cur = head;
    struct Node *prev = head;
    
    if (cur != NULL && cur->data == q) {
        head = cur->next;
        return ;
    }
    
    while (true) {
        if (cur == NULL) break;
        if (cur->data == q) break;
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) printf("No Number found");
    else prev->next = cur->next;
}

int main () {
    
    // INSERTION PART
    int x;
    for (int i = 0; i < 4; i++) {
        cin >> x;
        if (i == 0) init(x);
        else append(x);
    }
    
    print_list();
    
    // DELETION PART
    int q;
    scanf("%d", &q);
    delete_from_list(q);
    
    print_list();
    return 0;
}
