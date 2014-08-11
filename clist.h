#ifndef CLIST_H
    #define CLIST_H

#include <stdbool.h>

typedef struct Node
{
    void *data;
    struct Node *next_node;
}Node;

typedef struct
{
    Node *head_node;
    Node *tail_node;
    int size;
}List;

Node *mkNode(void *data, Node *next_node);

void rmNode(Node *node);

void node_SetData(Node *node, void *data);

void *node_GetData(Node *node);

void node_SetNext(Node *node, Node *next_node);

Node *node_GetNext(Node *node);

List *mkList();

void rmList(List *list);

bool list_isEmpty(List *list);

bool listNode_isHead(List *list, Node *node);

bool listNode_isTail(List *list, Node *node);

int list_Count(List *list);

void list_Append(List *list, void *data);

void list_Prepend(List *list, void *data);

void list_AddAt(List *list, void *data, int index);

void *list_GetAt(List *list, int index);

void list_PopAt(List *list, int index);
#endif
