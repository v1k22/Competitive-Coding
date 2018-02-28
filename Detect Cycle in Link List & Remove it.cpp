// https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
#include "bits/stdc++.h"
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = new Node;

void Making_manual_cycle_Trash();
void print_list();

void delete_it (struct Node *temp) {
    struct Node *cur = head;
    if (cur == temp) {
        printf("whole list is deleted");
    } else {
        while (true) {
            if (cur->next == temp) {
                cur->next = NULL;
                return;
            }
            cur = cur->next;
        }
    }
}

void detect_cycle_and_delete_it () {
    struct Node *A = head;
    struct Node *B = head;
    
    while (A && B && B->next) {
        A = A->next;
        B = B->next->next;
        if (A == B) {
            printf("Cycle Found");
            delete_it(A);
            return ;
        }
    }
}

int main () {
    Making_manual_cycle_Trash(); // LOL
    
    detect_cycle_and_delete_it();
    print_list();
    return 0;
}

void Making_manual_cycle_Trash() {
    head->data = 1;
    
    struct Node *A = new Node;
    A->data = 2;
    head->next = A;
    
    struct Node *B = new Node;
    B->data = 3;
    A->next = B;
    
    struct Node *C = new Node;
    C->data = 4;
    B->next = C;
    
    C->next = A;
}

void print_list() {
    struct Node *cur = head;
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
}
