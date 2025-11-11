#include<stdio.h>
#define MAX 10
int deque[MAX];
int left = -1, right = -1;
void insert_right();
void insert_left();
void delete_right();
void delete_left();
void display();
int main() {
    int choice;

    do {
        printf("\n----- DOUBLE ENDED QUEUE (DEQUE) -----");
        printf("\n1. Insert at right");
        printf("\n2. Insert at left");
        printf("\n3. Delete from right");
        printf("\n4. Delete from left");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\n--------------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_right(); break;
            case 2: insert_left(); break;
            case 3: delete_right(); break;
            case 4: delete_left(); break;
            case 5: display(); break;
            case 6: printf("\nExiting program...\n"); break;
            default: printf("\nInvalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void insert_right() {
    int val;
    if ((left == 0 && right == MAX - 1) || (left == right + 1)) {
        printf("\nOVERFLOW");
        return;
    }

    printf("\nEnter the value to be added: ");
    scanf("%d", &val);

    if (left == -1) {
        left = 0;
        right = 0;
    } else if (right == MAX - 1) {
        right = 0;
    } else {
        right++;
    }

    deque[right] = val;
    printf("\nInserted %d at right.", val);
}

void insert_left() {
    int val;
    if ((left == 0 && right == MAX - 1) || (left == right + 1)) {
        printf("\nOVERFLOW");
        return;
    }

    printf("\nEnter the value to be added: ");
    scanf("%d", &val);

    if (left == -1) {
        left = 0;
        right = 0;
    } else if (left == 0) {
        left = MAX - 1;
    } else {
        left--;
    }

    deque[left] = val;
    printf("\nInserted %d at left.", val);
}

void delete_right() {
    if (left == -1) {
        printf("\nUNDERFLOW");
        return;
    }

    printf("\nDeleted element from right: %d", deque[right]);

    if (left == right) {
        left = -1;
        right = -1;
    } else if (right == 0) {
        right = MAX - 1;
    } else {
        right--;
    }
}

void delete_left() {
    if (left == -1) {
        printf("\nUNDERFLOW");
        return;
    }

    printf("\nDeleted element from left: %d", deque[left]);

    if (left == right) {
        left = -1;
        right = -1;
    } else if (left == MAX - 1) {
        left = 0;
    } else {
        left++;
    }
}

void display() {
    int i;
    if (left == -1) {
        printf("\nDEQUE is empty.");
        return;
    }

    printf("\nDEQUE elements: ");
    i = left;
    while (i != right) {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", deque[right]);
}
