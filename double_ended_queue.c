#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int a[SIZE], f = -1, r = -1, i;

void enqueue_rear(int x) {
    if (r < SIZE - 1) {
        if (r == -1) {
            f++;
        }
        r++;
        a[r] = x;
    } 
    else {
        printf("\nQueue is Full");
    }
}
void enqueue_front(int x) {
    if (f < SIZE - 1) {
        if (f == -1) 
        {
            r++;
            f++;
        }
        else if(f>0)
        {
           f--;
            a[f] = x;
        }
    }
    else {
        printf("\nQueue is Full");
    }
}

void dequeue_rear() {
    if (r > -1) {
        a[r] = '\0';
        if (f == r) {
            f = r = -1;
        } 
        else {
            r--;
        }
    } else {
        printf("\nQueue is Empty");
    }
}
void dequeue_front() {
    if (f > -1) {
        a[r] = '\0';
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
        printf("\nPress 1 for enqueue_front");
        printf("\nPress 2 for enqueue_rear");
        printf("\nPress 3 for dequeue from rear");
        printf("\nPress 4 for dequeue from front");
        printf("\nPress 5 for traversing");
        printf("\nPress 6 to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter a value: ");
                scanf("%d", &x);
                enqueue_front(x);
                break;
            case 2:
                printf("\nEnter a value: ");
                scanf("%d", &x);
                enqueue_rear(x);
                break;

            case 3:
                dequeue_rear();
                break;
            case 4:
                dequeue_front();
                break;

            case 5:
                traverse();
                break;

            case 6:
                exit(0);

            default:
                printf("\nInvalid choice!!");
        }
    } while (1);

    return 0;
}
