// Circular Queue using Array 
#include "bits/stdc++.h"
using namespace std;

#define front FF
#define back BB

int N = 10;
int a[10];
int front, back;
const int LMT = 1e7;

void queue_push(int x) {
    if (back + 1 != front) {
        a[back++] = x;
        back = (back % N);
    } else printf("Queue is full");
}

int queue_front() {
    return a[front];
}

void queue_pop() {
    if (a[front] != LMT) {
        a[front++] = LMT;
        front = (front % N);
    } else printf("Queue is empty");
}

int queue_size() {
    return abs(back - front);
}

int main () {
    queue_push(123);
    queue_push(527);
    queue_push(999);
    cout << queue_front() << endl;
    cout << queue_size() << endl;
    queue_pop();
    cout << queue_front() << endl;
    cout << queue_size() << endl;
    queue_push(234);
    queue_push(123);
    queue_push(527);
    queue_push(999);
    queue_push(123);
    queue_push(527);
    queue_push(999);
    cout << "Circular Queue" << endl;
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";
    return 0;
}
