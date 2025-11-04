 #include <stdio.h>
#include <stdlib.h>

struct MyStruct {
    int arr[10];
};

int main() {
    struct MyStruct data[100];
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 10; j++) {
            int num;
            if (fscanf(fp, "%1d", &num) != 1) {  // read **one digit at a time**
                printf("Not enough data in file!\n");
                fclose(fp);
                return 1;
            }
            data[i].arr[j] = num;
        }
    }

    fclose(fp);

    // Print first structure
    printf("First structure values:\n");
    for (int j = 0; j < 10; j++) {
        printf("%d ", data[0].arr[j]);
    }
    printf("\n");

    return 0;
}
