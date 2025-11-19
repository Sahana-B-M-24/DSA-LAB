#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Insert at end
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Delete a node by value
void deleteNode(Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;

    // If head node is to be deleted
    if (temp->data == key) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        printf("Node deleted.\n");
        return;
    }

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node not found.\n");
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    printf("Node deleted.\n");
}

// Display forward
void displayForward(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Display backward
void displayBackward(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;

    // Move to last node
    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Main program (user input)
int main() {
    Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete a node\n");
        printf("4. Display forward\n");
        printf("5. Display backward\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;

            case 4:
                displayForward(head);
                break;

            case 5:
                displayBackward(head);
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
