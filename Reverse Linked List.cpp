#include "bits/stdc++.h"
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = new Node;

void init (int x) {
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

// iterative
void reverse_list() {
    struct Node *cur = head->next;
    struct Node *prev = head;
    struct Node *temp = cur;
    head->next = NULL;
    while (temp) {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    head = prev;
}

void print_list () {
    struct Node *cur = head;
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main () {
    for (int i = 0; i < 10; i++) {
        if (i == 0) init(i+1);
        else append(i+1);
    }
    print_list();
    reverse_list();
    print_list();
    return 0;
}
