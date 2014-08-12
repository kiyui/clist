/* CLIST_H: A simple C linked list library.
 * Copyright (C) 2010-2014 Timur Lavrenti Kiyivinski
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * */

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

/* Allocates memory for Node
 *
 * Parameters:
 * *data:       Node data
 * *next_node:  Pointer to next node or NULL 
 *
 * Returns:
 * Memory allocated to new Node
 * */
Node *mkNode(void *data, Node *next_node);

/* Removes memory allocated to Node
 *
 * Parameters:
 * *node:       Node to free
 * */
void rmNode(Node *node);

/* Sets node data
 *
 * Parameters:
 * *node:   Target Node
 * *data:   Data to set to node
 * */
void node_SetData(Node *node, void *data);

/* Gets node data
 *
 * Parameters:
 * *node:   Target Node
 * */
void *node_GetData(Node *node);

/* Sets a Node's pointed Node
 *
 * Parameters:
 * *node:       Target Node
 * *next_node:  Pointed Node
 * */
void node_SetNext(Node *node, Node *next_node);


/* Gets a Node's pointed Node
 *
 * Parameters:
 * *node:   Target Node
 * */
Node *node_GetNext(Node *node);

/* Allocates memory for a List
 * */
List *mkList();

/* Removes memory allocated to List
 *
 * Parameters:
 * *list:   Target List
 * */
void rmList(List *list);

/* Checks if List is empty
 *
 * Parameters:
 * *list:   Target List
 *
 * Returns:
 * true or false
 * */
bool list_isEmpty(List *list);

/* Checks if a Node is the head Node in a List
 *
 * Parameters:
 * *list:   Target List
 * *node:   Target Node
 *
 * Returns:
 * true or false
 * */
bool listNode_isHead(List *list, Node *node);

/* Checks if a Node is the tail Node in a List
 *
 * Parameters:
 * *list:   Target List
 * *node:   Target Node
 *
 * Returns:
 * true or false
 * */
bool listNode_isTail(List *list, Node *node);

/* Gets number of items in a List
 *
 * Parameters:
 * *list:   Target List
 *
 * Returns:
 * Node count
 * */
int list_Count(List *list);

/* Appends a Node to the List
 *
 * Parameters:
 * *list:   Target List
 * *data:   Target data
 * */
void list_Append(List *list, void *data);

/* Prepends a Node to the List
 *
 * Parameters:
 * *list:   Target List
 * *data:   Target data
 * */
void list_Prepend(List *list, void *data);

/* Adds a Node at a certain index to the List
 *
 * Parameters:
 * *list:   Target List
 * *data:   Target data
 * index:   Index to add Node
 * */
void list_AddAt(List *list, void *data, int index);

/* Gets data at a certain index in the List
 *
 * Parameters:
 * *list:   Target List
 * index:   Index to get Node data
 * */
void *list_GetAt(List *list, int index);

/* Deletes a node at a certain index in the List
 *
 * Parameters:
 * *list:   Target list
 * index:   Index to delete target Node
 * */
void list_PopAt(List *list, int index);
#endif
