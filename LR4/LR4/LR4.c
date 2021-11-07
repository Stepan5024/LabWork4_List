
#include <stdio.h>
#include <iostream>

typedef int Data;
typedef struct Node Node;
struct Node {
    Data data;
    Node* next;
};
int main()
{

    Node a = { 3 }, b = { 17 }, c = { 21 }, t = { 10 };
    Node* list = &a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;

    for (Node* p = list; p != NULL; p->next) {
        printf("%d", p->data);
    }
    
    printf("\n");

    return 0;

}
