#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Dynamic Array
typedef struct {
    int *array;
    int size;
    int capacity;
} DynamicArray;

DynamicArray* createDynamicArray(int capacity) {
    DynamicArray* dynArr = (DynamicArray*)malloc(sizeof(DynamicArray));
    dynArr->array = (int*)malloc(capacity * sizeof(int));
    dynArr->size = 0;
    dynArr->capacity = capacity;
    return dynArr;
}

void resizeDynamicArray(DynamicArray* dynArr, int newCapacity) {
    int* newArray = (int*)malloc(newCapacity * sizeof(int));
    for (int i = 0; i < dynArr->size; i++) {
        newArray[i] = dynArr->array[i];
    }
    free(dynArr->array);
    dynArr->array = newArray;
    dynArr->capacity = newCapacity;
}

void insertFrontDynamicArray(DynamicArray* dynArr, int element) {
    if (dynArr->size == dynArr->capacity) {
        resizeDynamicArray(dynArr, 2 * dynArr->capacity);
    }
    for (int i = dynArr->size; i > 0; i--) {
        dynArr->array[i] = dynArr->array[i - 1];
    }
    dynArr->array[0] = element;
    dynArr->size++;
}

void insertBackDynamicArray(DynamicArray* dynArr, int element) {
    if (dynArr->size == dynArr->capacity) {
        resizeDynamicArray(dynArr, 2 * dynArr->capacity);
    }
    dynArr->array[dynArr->size] = element;
    dynArr->size++;
}

void insertAtIndexDynamicArray(DynamicArray* dynArr, int index, int element) {
    if (index < 0 || index > dynArr->size) {
        // printf("Index out of bounds\n");
        return;
    }
    if (dynArr->size == dynArr->capacity) {
        resizeDynamicArray(dynArr, 2 * dynArr->capacity);
    }
    for (int i = dynArr->size; i > index; i--) {
        dynArr->array[i] = dynArr->array[i - 1];
    }
    dynArr->array[index] = element;
    dynArr->size++;
}

void deleteFrontDynamicArray(DynamicArray* dynArr) {
    if (dynArr->size == 0) {
        // printf("Array is empty\n");
        return;
    }
    for (int i = 1; i < dynArr->size; i++) {
        dynArr->array[i - 1] = dynArr->array[i];
    }
    dynArr->size--;
}

void deleteBackDynamicArray(DynamicArray* dynArr) {
    if (dynArr->size == 0) {
        // printf("Array is empty\n");
        return;
    }
    dynArr->size--;
}

void deleteAtIndexDynamicArray(DynamicArray* dynArr, int index) {
    if (index < 0 || index >= dynArr->size) {
        // printf("Index out of bounds\n");
        return;
    }
    for (int i = index; i < dynArr->size - 1; i++) {
        dynArr->array[i] = dynArr->array[i + 1];
    }
    dynArr->size--;
}

int accessAtIndexDynamicArray(DynamicArray* dynArr, int index) {
    if (index < 0 || index >= dynArr->size) {
        // printf("Index out of bounds\n");
        return -1; // Return a default value or handle error appropriately
    }
    return dynArr->array[index];
}

void freeDynamicArray(DynamicArray* dynArr) {
    free(dynArr->array);
    free(dynArr);
}


// Singly Linked List
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} SinglyLinkedList;

SinglyLinkedList* createSinglyLinkedList() {
    SinglyLinkedList* list = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void insertFrontSinglyLinkedList(SinglyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void insertBackSinglyLinkedList(SinglyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
}

void insertAtIndexSinglyLinkedList(SinglyLinkedList* list, int index, int data) {
    if (index < 0 || index > list->size) {
        // printf("Index out of bounds\n");
        return;
    }
    if (index == 0) {
        insertFrontSinglyLinkedList(list, data);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    Node* current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    list->size++;
}

void deleteFrontSinglyLinkedList(SinglyLinkedList* list) {
    if (list->head == NULL) {
        // printf("List is empty\n");
        return;
    }
    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
}

void deleteBackSinglyLinkedList(SinglyLinkedList* list) {
    if (list->head == NULL) {
        // printf("List is empty\n");
        return;
    }
    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        list->size--;
        return;
    }
    Node* current = list->head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    list->size--;
}

void deleteAtIndexSinglyLinkedList(SinglyLinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        // printf("Index out of bounds\n");
        return;
    }
    if (index == 0) {
        deleteFrontSinglyLinkedList(list);
        return;
    }
    Node* current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    list->size--;
}

int accessAtIndexSinglyLinkedList(SinglyLinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        // printf("Index out of bounds\n");
        return -1; // Return a default value or handle error appropriately
    }
    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

void freeSinglyLinkedList(SinglyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

int main() {
    // Measure execution time for dynamic array
    printf("Dynamic Array:\n");
    printf("Size\tInsertion(ms)\tDeletion(ms)\tAccess(ms)\n");
    for (int size = 10; size <= 10000; size *= 10) {
        DynamicArray* dynArr = createDynamicArray(size);

        // Insertion
        clock_t start = clock();
        for (int i = 0; i < size; i++) {
            insertBackDynamicArray(dynArr, i);
        }
        clock_t end = clock();
        double insertionTime = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        // Deletion
        start = clock();
        for (int i = 0; i < size; i++) {
            deleteBackDynamicArray(dynArr);
        }
        end = clock();
        double deletionTime = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        // Access
        start = clock();
        for (int i = 0; i < size; i++) {
            accessAtIndexDynamicArray(dynArr, i);
        }
        end = clock();
        double accessTime = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        printf("%d\t%.6f\t%.6f\t%.6f\n", size, insertionTime, deletionTime, accessTime);

        freeDynamicArray(dynArr);
    }

    // Measure execution time for singly linked list
    printf("\nSingly Linked List:\n");
    printf("Size\tInsertion(ms)\tDeletion(ms)\tAccess(ms)\n");
    for (int size = 10; size <= 10000; size *= 10) {
        SinglyLinkedList* list = createSinglyLinkedList();

        // Insertion
        clock_t start = clock();
        for (int i = 0; i < size; i++) {
            insertBackSinglyLinkedList(list, i);
        }
        clock_t end = clock();
        double insertionTime = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        // Deletion
        start = clock();
        for (int i = 0; i < size; i++) {
            deleteBackSinglyLinkedList(list);
        }
        end = clock();
        double deletionTime = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        // Access
        start = clock();
        for (int i = 0; i < size; i++) {
            accessAtIndexSinglyLinkedList(list, i);
        }
        end = clock();
        double accessTime = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        printf("%d\t%.6f\t%.6f\t%.6f\n", size, insertionTime, deletionTime, accessTime);

        freeSinglyLinkedList(list);
    }

    return 0;
}