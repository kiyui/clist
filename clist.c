#include "clist.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* List & Node structure definitions. 
 *
 *typedef struct
 *{
 *    void *data;
 *    Node *next_node;
 *} Node;
 *
 *typedef struct
 *{
 *    Node *head_node;
 *    Node *tail_node;
 *    int size;
 *} List;
 *
 **/

/*Node specific functions*/
Node *mkNode(void *data, Node *next_node)
{
    Node *node = (Node *) malloc(sizeof(Node));
    if (node != NULL)
    {
        node->data = data;
        node->next_node = next_node;
    }
    return node;
}

void rmNode(Node *node)
{
    if (node != NULL)
    {
        free(node);
    }
}

void node_SetData(Node *node, void *data)
{
    node->data = data;
}

void *node_GetData(Node *node)
{
    return node->data;
}

void node_SetNext(Node *node, Node *next_node)
{
    node->next_node = next_node;
}

Node *node_GetNext(Node *node)
{
    return node->next_node;
}

/*List specific functions*/
List *mkList()
{
    List *list = (List *) malloc(sizeof(List));
    list->head_node = NULL;
    list->tail_node = NULL;
    list->size = 0;
    return list;
}

void rmList(List *list)
{
    Node *node = list->head_node, *cur_node;
    if (list != NULL && list->size > 0)
    {
        while (node != NULL)
        {
            cur_node = node;
            node = node_GetNext(cur_node);
            if (cur_node != NULL)
                free(cur_node);
            
        }
        free(list);
    }
}

bool list_isEmpty(List *list)
{
    return list->head_node == NULL && list->tail_node == NULL;
}

bool listNode_isHead(List *list, Node *node)
{
    return list->head_node == node;
}

bool listNode_isTail(List *list, Node *node)
{
    return list->tail_node == node;
}

int list_Count(List *list)
{
    Node *node = list->head_node;
    int count = 0;
    if (list != NULL)
    {
        while (node != NULL)
        {
            node = node_GetNext(node);
            count++;
        }
    }
    return count;
}

void list_Append(List *list, void *data)
{
    Node *node = mkNode(data, NULL);
    if (list_isEmpty(list))
    {
        list->head_node = node;
        list->tail_node = node;
    }
    else
    {
        list->tail_node->next_node = node;
        list->tail_node = node;
    }
    list->size++;
}

void list_Prepend(List *list, void *data)
{
    Node *node = mkNode(data, list->head_node);
    if (list_isEmpty(list))
    {
        list->tail_node = node;
    }
    list->head_node = node;
    list->size++;
}

void list_AddAt(List *list, void *data, int index)
{
    Node *node, *prevNode, *nextNode;
    int loopVar;
    if (list_isEmpty(list))
    {
        node = mkNode(data, NULL);
        list->head_node = node;
        list->tail_node = node;
    }
    else
    {
        if (index == 0)
        {
            list_Prepend(list, data);
        }
        else if (index == list_Count(list))
        {
            list_Append(list, data);
        }
        else if (index < list->size)
        {
            nextNode = list->head_node;
            for (loopVar = 0; loopVar < index; loopVar++)
            {
                prevNode = nextNode;
                nextNode = node_GetNext(prevNode);
            }
            node =  mkNode(data, nextNode);
            prevNode->next_node = node;
            if (nextNode == NULL)
            {
                list->tail_node = node;
            }
            list->size++;
        }
    }
}

void *list_GetAt(List *list, int index)
{
    int loopVar = 0;
    Node *node = list->head_node;
    if (index <= list->size)
    {
        if (list != NULL)
        {
            if (index == 0)
            {
                return list->head_node->data;
            }
            else if (index == list->size - 1)
            {
                return list->tail_node->data;
            }
            for (loopVar = 0; loopVar < index; loopVar++)
            {
                node = node_GetNext(node);
            }
            return node->data;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

void list_PopAt(List *list, int index)
{
    Node *popNode, *prevNode, *nextNode;
    int loopVar;
    if (!list_isEmpty(list))
    {
        if (index == 0)
        {
            popNode = list->head_node;
            list->head_node = node_GetNext(list->head_node);
        }
        else
        {
            nextNode = list->head_node;
            for (loopVar = 0; loopVar < index; loopVar++)
            {
                prevNode = nextNode;
                nextNode = node_GetNext(prevNode);
            }
            popNode = prevNode->next_node;
            prevNode->next_node = node_GetNext(nextNode);
            if (prevNode->next_node == NULL)
            {
                list->tail_node = prevNode;
            }
        }
        rmNode(popNode);
        list->size--;
    }
}

