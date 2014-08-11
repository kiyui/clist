/* File: main.c
 * Simple example program to demonstrate the clist.h library.
 * */

#include "clist.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double obj1;
    double obj2;
    int count;
}MyData;

/* Print List Information */
void printList(List *list);

int main()
{
    /* Declaration */
    MyData *data1;
    MyData *data2;
    MyData *data3;
    MyData *data4;
    MyData *data_example;
    List *list;
    /* Memory allocation */
    data1 = malloc(sizeof(MyData));
    data2 = malloc(sizeof(MyData));
    data3 = malloc(sizeof(MyData));
    data4 = malloc(sizeof(MyData));
    data_example = malloc(sizeof(MyData));
    list = mkList();
    /* Value Assignment */
    data1->obj1 = 9;
    data1->obj2 = 5;
    data1->count = 1;
    data2->obj1 = 8;
    data2->obj2 = 4;
    data2->count = 2;
    data3->obj1 = 2;
    data3->obj2 = 1;
    data3->count = 3;
    data4->obj1 = 0;
    data4->obj2 = 3;
    data4->count = 4;
    /* List library example use */
    list_Append(list, data1);
    list_Prepend(list, data2);
    list_AddAt(list, data3, 1);
    list_Append(list, data4);
    printList(list);
    list_PopAt(list, 0);
    printList(list);
    /* Data values */
    printf("\nData1: obj1 = %lf, obj2 = %lf", data1->obj1, data1->obj2);
    printf("\nData2: obj1 = %lf, obj2 = %lf", data2->obj1, data2->obj2);
    printf("\nData3: obj1 = %lf, obj2 = %lf", data3->obj1, data3->obj2);
    printf("\nData4: obj1 = %lf, obj2 = %lf", data4->obj1, data4->obj2);
    /* Extra Information */
    data_example = list_GetAt(list, 1);
    printf("\ndatademo: obj1 = %lf, obj2 = %lf", data_example->obj1, data_example->obj2);
    printf("\n");
    /* Free memory */
    rmList(list);
    free(data1);
    free(data2);
    free(data3);
    free(data4);
    return 0;
}

void printList(List *list)
{
    int loopVar = 0;
    Node *node;
    Node *node_now;
    MyData *data_example;
    node = list->head_node;
    data_example = malloc(sizeof(MyData));
    if (list != NULL && list->size > 0)
    {
        while (node != NULL)
        {
            node_now = node;
            node = node_GetNext(node);
            data_example = node_now->data;
            printf("\nList index %i: obj1 = %lf, obj2 = %lf, count = %i", loopVar, data_example->obj1, data_example->obj2, data_example->count);
            loopVar++;
        }
    }
    printf("\nlist item count = %i", list_Count(list));
    printf("\nList size = %i", list->size);
}
