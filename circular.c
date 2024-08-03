// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#define size 10

int a[size],f=-1,r=-1,i;
void enqueue(int x)
{
    if(((r+1)%size)!=f)
    {
        r=(r+1)%size;
        if(f==-1)
        {
            f++;
        }
        a[r]=x;
    }
    else
    {
        printf("\n Queue is Full");
    }
}
void dequeue()
{
    if(f>-1)
    {
        a[f]='\0';
        if(f==r)
        {
            f=r=-1;
        }
        else
        {
            f=(f+1)%size;
        }
    }
    else
    {
        printf("\n queue is EMpty");
    }
}
void traverse()
{
    if(f>-1)
    {
        printf("Elements is:");
        for(i=f;i!=r;i=(i+1)%size)
        {
            printf("%d \t",a[i]);
        }
        printf("%d",a[i]);
    }
    else
    {
        printf("\n Queue is Empty!!1");
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
