#include <iostream>

struct Node {
    int value;
    Node* next;
};

Node* kthToLast(Node* head, int k) {
    Node* n1 = head;
    Node* n2 = head;

    //  n2 moves k nodes ahead
    for (int s = 0; s < k; ++s) {
        if (n2 == nullptr) {
            // if k is greater than or equal to the list's length
            return nullptr;
        }
        n2 = n2->next;
    }
   while (n2 != nullptr) {
        n1 = n1->next;
        n2 = n2->next;
    }

    return p1;  // p1 points to the kth to last element
}
