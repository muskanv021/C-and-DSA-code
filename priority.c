#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int a[SIZE], f = -1, r = -1, i;

void enqueue(int x)
{
    if (r < SIZE - 1) 
    {
        if (r == -1) 
        {
            f++;
            r++;
            a[r] = x;
        }
        else {
         for(i=r;i>=f;i--)
         {
             if(a[i]>x)
             {
                 a[i+1]=a[i];
             }
             else
               break;
         }
         a[i+1]=x;
         r++;
        }  
    } 
    else
    {
        
        printf("\nQueue is Full");
    }
}

void dequeue() {
    if (f > -1) 
    {
        if (f == r)
        {
            a[f] = '\0';
            f = r = -1;
        } 
        else 
        {
            for(i=f;i<r;i++)
            {
                a[i]=a[i+1];
            }
            a[r]='\0';
            r--;
        }
    } 
    else {
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
        printf("\n press 4 for count");
        printf("\nPress 5 for High priority");
        printf("\nPress 6 for low priority");
        printf("\nPress 7 to exit");
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
                printf("\n Total element : %d",a[f]);
                break;
            case 5:
                printf("\n High Priority element : %d",a[f]);
                break;
            case 6:
                printf("\n Low Priority element : %d",a[f]);
                break;

            case 7:
                exit(0);

            default:
                printf("\nInvalid choice!!");
        }
    } while (1);

    return 0;
}
