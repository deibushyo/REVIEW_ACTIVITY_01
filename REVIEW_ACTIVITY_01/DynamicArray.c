#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DynamicArray.h"

void initListD(List* list, int max){
	list->count = 0;
    list->max = max; // Assuming max is a separate variable specifying the maximum size
    list->elems = (DATA*)malloc(list->max * sizeof(DATA));

    if (list->elems == NULL) {
        printf("Failed to allocate memory for the list.\n");
        exit(1);
    }
}

List newListD(int max) {
	List list;
    list.count = 0;
    list.max = max;
    list.elems = (DATA*)malloc(max * sizeof(DATA));

    if (list.elems == NULL) {
        printf("Failed to allocate memory for the list.\n");
        exit(1);
    }

    return list;
}

void displayListD(List list) {
	printf("List: ");
	int i;
    for (i = 0; i < list.count; i++) {
        printf("%d ", list.elems[i]);
    }
    printf("\n");
}

bool insertFrontD(List *list, DATA item) {
	if (list->count == list->max) {
        printf("List is full. Cannot insert element.\n");
        return false;
    }
	int i;
    for (i = list->count; i > 0; i--) {
        list->elems[i] = list->elems[i - 1];
    }

    list->elems[0] = item;
    list->count++;

    return true;
}

bool insertRearD(List *list, DATA item) {
	if (list->count == list->max) {
        printf("List is full. Cannot insert element.\n");
        return false;
    }

    list->elems[list->count] = item;
    list->count++;

    return true;
}

bool insertSortedD(List *list, DATA item) {
	if (list->count == list->max) {
        printf("List is full. Cannot insert element.\n");
        return false;
    }

    int i;
    for (i = list->count - 1; i >= 0 && list->elems[i] > item; i--) {
        list->elems[i + 1] = list->elems[i];
    }

    list->elems[i + 1] = item;
    list->count++;

    return true;
}

bool insertAtD(List *list, DATA item, int loc) {
	if (list->count == list->max) {
        printf("List is full. Cannot insert element.\n");
        return false;
    }

    if (loc < 0 || loc > list->count) {
        printf("Invalid position. Cannot insert element.\n");
        return false;
    }

	int i;
    for (i = list->count - 1; i >= loc; i--) {
        list->elems[i + 1] = list->elems[i];
    }

    list->elems[loc] = item;
    list->count++;

    return true;
}

bool searchItemD(List list, DATA key) {
	int i;
	for (i = 0; i < list.count; i++) {
        if (list.elems[i] == key) {
            return true;
        }
    }
    return false;
}

int getItemD(List list, DATA key) {
	int i;
	for (i = 0; i < list.count; i++) {
        if (list.elems[i] == key) {
            return i;
        }
    }
    return -1;
}

bool deleteFrontD(List *list) {
	if (list->count == 0) {
        return false; // Cannot delete from an empty list
    }

    // Shift elements to the left to overwrite the front item
    int i;
    for (i = 0; i < list->count - 1; i++) {
        list->elems[i] = list->elems[i + 1];
    }

    list->count--; // Decrement the count

    return true;
}

bool deleteRearD(List *list) {
	if (list->count == 0) {
        return false; // Cannot delete from an empty list
    }

    list->count--; // Decrement the count

    return true;
}

int deleteAtD(List *list, int loc) {
	if (loc < 0 || loc >= list->count) {
        return -1; // Invalid location
    }

    int deletedItem = list->elems[loc];

    // Shift elements to the left to fill the gap created by the deleted item
    int i;
	for (i = loc; i < list->count - 1; i++) {
        list->elems[i] = list->elems[i + 1];
    }

    list->count--; // Decrement the count

    return deletedItem;
}

bool deleteItemD(List *list, DATA key) {
	int loc = -1; // Initialize the location to -1 (not found)

    // Find the location of the item to be deleted
    int i;
    for (i = 0; i < list->count; i++) {
        if (list->elems[i] == key) {
            loc = i;
            break;
        }
    }

    if (loc == -1) {
        return false; // Item not found
    }

    // Shift elements to the left to fill the gap created by the deleted item
	for (i = loc; i < list->count - 1; i++) {
        list->elems[i] = list->elems[i + 1];
    }

    list->count--; // Decrement the count

    return true;
}

int deleteAllItemD(List *list, DATA key) {
	int numDeleted = 0; // Initialize the counter for deleted occurrences

    // Find and delete all occurrences of the item
    int i;
    for (i = 0; i < list->count; i++) {
        if (list->elems[i] == key) {
            // Shift elements to the left to fill the gap created by the deleted item
            int j;
			for (j = i; j < list->count - 1; j++) {
                list->elems[j] = list->elems[j + 1];
            }

            list->count--; // Decrement the count
            numDeleted++;  // Increment the counter for deleted occurrences
            i--;           // Adjust the loop index to account for the shifted elements
        }
    }

    return numDeleted;
}
