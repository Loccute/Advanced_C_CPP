#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR_GET -999

typedef struct Node
{
    int data;
    struct Node *pNext;
}Node;

typedef struct 
{
    Node *pHead;
    Node *pTail;
}List;

Node * CreateNode(int data){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->pNext = NULL;
    return p;
}

void Create_list(List *L){
    L->pHead = NULL;
    L->pTail = NULL;
}

bool isempty(List L)
{
    return L.pHead == NULL;
}

void pushback(List *L, int data){
    Node *p = CreateNode(data);
    if (isempty(*L)) {
        L->pHead = p;
        L->pTail = p;
        return;
    }
    Node *q = L->pHead;
    while(q->pNext != NULL) q = q->pNext;
    q->pNext = p;
    L->pTail = p;
}

void pushfront(List *L, int data){
    Node *p = CreateNode(data);
    if (isempty(*L)) {
        L->pHead = p;
        L->pTail = p;
        return;
    }
    p->pNext = L->pHead;
    L->pHead = p;
}

void insert(List *L, int data, int pos){
    Node *p = CreateNode(data);
    int k = 0;
    Node *q = L->pHead;
    while((q->pNext != NULL) && (k != pos - 1)){
        k++;
        q = q->pNext;
    }
    if (q->pNext != NULL) p->pNext = q->pNext;
    else L->pTail = p;
    q->pNext = p;
}

void popback(List *L){
    if (isempty(*L)) {
        printf("List is empty!\n");
        return;
    }
    if (L->pHead == L->pTail){
        L->pTail = NULL;
        free(L->pHead);
        L->pHead = NULL;
        return;
    }
    Node *p = L->pHead;
    Node *q = NULL;
    while(p->pNext != NULL)
    {
        q = p;
        p = p->pNext;
    }
    q->pNext = NULL;
    L->pTail = q;
    free(p);
    p = NULL;
}

void popfront(List *L){
    if (isempty(*L)) {
        printf("List is empty!\n");
        return;
    }
    Node *p = L->pHead;
    if (p == L->pTail) L->pTail = NULL;
    L->pHead = p->pNext;
    p->pNext = NULL;
    free(p);
    p = NULL;
}

void delete_Node(List *L, int pos){
    if (isempty(*L)) {
        printf("List is empty!\n");
        return;
    }
    int k = 0;
    Node *p = L->pHead;
    while((p->pNext != NULL) && (k != pos - 1)) {
        p = p->pNext;
        k++;
    }
    if (k != pos - 1) {
        printf("Don't find the position need to delete!\n");
        return;
    }

    Node *q = p->pNext;
    p->pNext = q->pNext;
    if (L->pTail == q) L->pTail = p;
    q->pNext = NULL;
    free(q);
    q = NULL;
}

int front(List L){
    return L.pHead->data;
}

int back(List L){
    return L.pTail->data;
}

int size(List L){
    Node *p = L.pHead;
    int size = 1;
    while(p->pNext != NULL){
        size++;
        p = p->pNext;
    }
    return size;
}

int get(List L, int pos){
    int k = 0;
    Node *p = L.pHead;
    while ((p->pNext != NULL) && (k != pos)){
        k++;
        p = p->pNext;
    }
    if (k != pos) return ERROR_GET;
    return p->data;
}

void display(List L){
    Node *p = L.pHead;
    int i = 0;
    while(p != NULL){
        printf("Value of Node %d: %d\n", i, p->data);
        p = p->pNext;
        i++;
    }
}

void free_list(List *L){
    if (isempty(*L)) return;
    Node *p = L->pHead;
    L->pTail = NULL;
    L->pHead = NULL;
    while(p != NULL){
        Node *q = p;
        p = q->pNext;
        // free(q)
        q->pNext = NULL;
        free(q);
        q = NULL;
    }
}


int main()
{
    List L;
    Create_list(&L);
    pushfront(&L, 2);
    pushfront(&L, 7);
    pushfront(&L, 4);
    pushfront(&L, 5);
    pushfront(&L, 3);
    pushfront(&L, 10);

    insert(&L, 16, 19);
    printf("Value test: %d\n", get(L, 2));
    printf("Value test: %d\n", get(L, 0));
    printf("Value test: %d\n", get(L, 5));
    display(L);
    printf("----------------------\n");
    printf("Size of list is: %d\n", size(L));
    printf("Front of the list is: %d\n", front(L));
    printf("Back of the list is: %d\n", back(L));
    popback(&L);
    display(L);
    printf("----------------------\n");
    popfront(&L);
    display(L);
    printf("----------------------\n");
    delete_Node(&L, 3);
    display(L);

    free_list(&L);
	return 0;

}
