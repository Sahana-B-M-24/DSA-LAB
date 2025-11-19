#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

int main() {
    int choice = 0;

    while (choice != 9) {
        printf("\n********** Main Menu **********\n");
        printf("Choose one option from the list below:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at last\n");
        printf("3. Insert at any random location\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from last\n");
        printf("6. Delete node after specified location\n");
        printf("7. Search for an element\n");
        printf("8. Show list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: beginsert(); break;
            case 2: lastinsert(); break;
            case 3: randominsert(); break;
            case 4: begin_delete(); break;
            case 5: last_delete(); break;
            case 6: random_delete(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

void beginsert() {
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    int item;

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &item);

    ptr->data = item;
    ptr->next = head;
    head = ptr;

    printf("Node inserted at beginning!\n");
}

void lastinsert() {
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    int item;

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &item);

    ptr->data = item;
    ptr->next = NULL;

    if (head == NULL) {
        head = ptr;
    } else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }

    printf("Node inserted at end!\n");
}

void randominsert() {
    int loc, item;
    struct node *ptr, *temp;

    ptr = (struct node*)malloc(sizeof(struct node));

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &item);

    printf("Enter location to insert after: ");
    scanf("%d", &loc);

    temp = head;
    for (int i = 1; i < loc; i++) {
        if (temp == NULL) {
            printf("Location not found!\n");
            return;
        }
        temp = temp->next;
    }

    ptr->data = item;
    ptr->next = temp->next;
    temp->next = ptr;

    printf("Node inserted at location %d!\n", loc);
}

void begin_delete() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *ptr = head;
    head = ptr->next;
    free(ptr);

    printf("Node deleted from beginning!\n");
}

void last_delete() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *temp = head, *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        head = NULL;
    } else {
        prev->next = NULL;
    }

    free(temp);
    printf("Node deleted from end!\n");
}

void random_delete() {
    int loc;
    printf("Enter location after which node should be deleted: ");
    scanf("%d", &loc);

    struct node *temp = head, *ptr;

    for (int i = 1; i < loc; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Location not found!\n");
            return;
        }
        temp = temp->next;
    }

    ptr = temp->next;
    temp->next = ptr->next;
    free(ptr);

    printf("Node deleted!\n");
}

void search() {
    int item, pos = 1;
    struct node *temp = head;

    printf("Enter element to search: ");
    scanf("%d", &item);

    while (temp != NULL) {
        if (temp->data == item) {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Element not found!\n");
}

void display() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
