#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StaticArray.h"

void initList(List *list) {
	list->count = 10; // Initialize the count to 10

    // Initialize the first 10 elements of the list
    int i;
    for (i = 0; i < list->count; i++) {
        list->elems[i] = i + 1;
    }
}

List newList() {
	List list;
    list.count = 0;
    
    return list;
}

void displayList(List list) {
	printf("Count: %d\n", list.count);
	int i;
    for (i = 0; i < list.count; i++) {
        printf("Element %d: %d\n", i, list.elems[i]);
    }
}

bool insertFront(List *list, DATA item) {
	if (list->count >= MAX) {
        return false; // List is full, insertion failed
    }
    
    // Shift existing elements to the right
    int i;
    for (i = list->count; i > 0; i--) {
        list->elems[i] = list->elems[i - 1];
    }
    
    // Insert the new item at the front
    list->elems[0] = item;
    list->count++;
    
    return true; // Insertion successful
}

bool insertRear(List *list, DATA item) {
	if (list->count >= MAX) {
        return false; // List is full, insertion failed
    }
    
    list->elems[list->count] = item;
    list->count++;
    
    return true; // Insertion successful
}

bool insertSorted(List *list, DATA item) {
	if (list->count >= MAX) {
        return false; // List is full, insertion failed
    }

    int index = 0;
    while (index < list->count && list->elems[index] < item) {
        index++;
    }

    // Shift elements to the right to make space for the new item
    int i;
    for (i = list->count - 1; i >= index; i--) {
        list->elems[i + 1] = list->elems[i];
    }

    // Insert the new item at the correct position
    list->elems[index] = item;
    list->count++;

    return true; // Insertion successful
}

bool insertAt(List *list, DATA item, int loc) {
	if (list->count >= MAX || loc < 0 || loc > list->count) {
        return false; // Insertion failed due to list full or invalid location
    }

    // Shift elements to the right to make space for the new item
    int i;
    for (i = list->count - 1; i >= loc; i--) {
        list->elems[i + 1] = list->elems[i];
    }

    // Insert the new item at the specified location
    list->elems[loc] = item;
    list->count++;

    return true; // Insertion successful
}

bool searchItem(List list, DATA key) {
	int i;
	for (i = 0; i < list.count; i++) {
        if (list.elems[i] == key) {
            return true; // Item found
        }
    }

    return false; // Item not found
}

int getItem(List list, DATA key) {
	int i;
	for (i = 0; i < list.count; i++) {
        if (list.elems[i] == key) {
            return i; // Item found, return the index
        }
    }

    return -1; // Item not found
}

bool deleteFront(List *list) {
	if (list->count == 0) {
        return false; // List is empty, deletion failed
    }

    // Shift elements to the left
    int i;
    for (i = 1; i < list->count; i++) {
        list->elems[i - 1] = list->elems[i];
    }

    list->count--;
    return true; // Deletion successful
}

bool deleteRear(List *list) {
	if (list->count == 0) {
        return false; // List is empty, deletion failed
    }

    list->count--;
    return true; // Deletion successful
}

int deleteAt(List *list, int loc) {
	if (loc < 0 || loc >= list->count) {
        return -1; // Invalid index, deletion failed
    }

    int deletedItem = list->elems[loc];

    // Shift elements to the left
    int i;
    for (i = loc; i < list->count - 1; i++) {
        list->elems[i] = list->elems[i + 1];
    }

    list->count--;
    return deletedItem; // Deletion successful
}

bool deleteItem(List *list, DATA key) {
	int loc = -1;

    // Find the index of the key
    int i;
    for (i = 0; i < list->count; i++) {
        if (list->elems[i] == key) {
            loc = i;
            break;
        }
    }

    if (loc == -1) {
        return false; // Key not found, deletion failed
    }

    // Shift elements to the left
    for (i = loc; i < list->count - 1; i++) {
        list->elems[i] = list->elems[i + 1];
    }

    list->count--;
    return true; // Deletion successful
}

int deleteAllItem(List *list, DATA key) {
	int count = 0;

    // Shift elements to the left, skipping the ones with the key
    int i;
    for (i = 0; i < list->count; i++) {
        if (list->elems[i] == key) {
            count++;
        } else {
            list->elems[i - count] = list->elems[i];
        }
    }

    list->count -= count;
    return count; // Number of occurrences deleted
}
