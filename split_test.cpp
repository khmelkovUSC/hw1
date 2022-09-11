#include "split.h"
#include "split_test.h"
#include <iostream>

int main() {
    using namespace std;
    Node* in = new Node(1, NULL);
    in->next = new Node(2, NULL);
    in->next->next = new Node(3, NULL);
    in->next->next->next = new Node(3, NULL);
    in->next->next->next->next = new Node(5, NULL);
    in->next->next->next->next->next = new Node(10, NULL);
    Node* odds = NULL;
    Node* evens = NULL;
    split(in, odds, evens);
    printNodes(in);
    cout << "Odds: " << endl;
    printNodes(odds);
    cout << "Evens: " << endl;
    printNodes(evens);
    deleteNodes(in);
    deleteNodes(odds);
    deleteNodes(evens);
}

void deleteNodes(Node*& list) {
    if (list == NULL) return;
    deleteNodes(list->next);
    delete list;
}

void printNodes(Node*& list) {
    using namespace std;
    if (list == NULL) return;
    cout << list->value << endl;
    printNodes(list->next);
}