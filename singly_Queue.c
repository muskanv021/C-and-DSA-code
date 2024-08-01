#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int a[SIZE], f = -1, r = -1, i;

void enqueue(int x) {
    if (r < SIZE - 1) {
        if (r == -1) {
            f++;
        }
        r++;
        a[r] = x;
    } else {
        printf("\nQueue is Full");
    }
}

void dequeue() {
    if (f > -1) {
        a[f] = '\0';
        if (f == r) {
            f = r = -1;
        } else {
            f++;
        }
    } else {
        printf("\nQueue is Empty");
    }
}

void traverse() {
    if (f > -1) {
        printf("\nElements: ");
        for (i = f; i <= r; i++) {
            printf("%d ", a[i]);
        }
    } else {
        printf("\nQueue is Empty");
    }
}

int main() {
    int ch, x;
    do {
        printf("\nPress 1 for enqueue");
        printf("\nPress 2 for dequeue");
        printf("\nPress 3 for traversing");
        printf("\nPress 4 to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter a value: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                traverse();
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice!!");
        }
    } while (1);

    return 0;
}
