#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>

typedef int DATA;

typedef struct {
	DATA* elems;
	int count;
	int max;
} List;

void initListD(List* list, int max);
List newListD(int max);
void displayListD(List list);
bool insertFrontD(List *list, DATA item);
bool insertRearD(List *list, DATA item);
bool insertSortedD(List *list, DATA item);
bool insertAtD(List *list, DATA item, int loc);
bool searchItemD(List list, DATA key);
int getItemD(List list, DATA key);
bool deleteFrontD(List *list);
bool deleteRearD(List *list);
int deleteAtD(List *list, int loc);
bool deleteItemD(List *list, DATA key);
int deleteAllItemD(List *list, DATA key);

#endif
