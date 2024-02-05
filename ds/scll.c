#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int coeff;
    int expo;
    struct node *ptr;
};

struct node *head1, *head2, *head3, *temp, *temp1, *temp2, *temp3, *list1, *list2, *list3;
struct node *dummy1, *dummy2;

void create_poly1(int c, int e);
void create_poly2(int c, int e);
void display();
void add_poly();
void eval_poly(int x);

int n, ch, c, e, i;

int main()
{
    int x;
    list1 = list2 = NULL;

    while (1)
    {
        printf("1. Create first polynomial\n2. Create Second Polynomial\n3. Display both the polynomials\n");
        printf("4. Add Polynomials\n5. Evaluate a Polynomial\n6. Exit\n");

        printf("Enter choice\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the number of terms\n");
            scanf("%d", &n);
            printf("Enter coefficient & power of each term\n");
            for (i = 0; i < n; i++)
            {
                scanf("%d%d", &c, &e);
                create_poly1(c, e);
            }
            break;
        case 2:
            printf("Enter the number of terms\n");
            scanf("%d", &n);
            printf("Enter coefficient & power of each term\n");
            for (i = 0; i < n; i++)
            {
                scanf("%d%d", &c, &e);
                create_poly2(c, e);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            add_poly();
            break;
        case 5:
            printf("Enter the value for x\n");
            scanf("%d", &x);
            eval_poly(x);
            break;
        case 6:
            exit(0);
        }
    }

    return 0;
}

void create_poly1(int c, int e)
{
    dummy1 = (struct node *)malloc(1 * sizeof(struct node));
    dummy1->coeff = 0;
    dummy1->expo = 0;
    dummy1->ptr = list1;

    if (list1 == NULL)
    {
        list1 = (struct node *)malloc(1 * sizeof(struct node));
        list1->coeff = c;
        list1->expo = e;
        list1->ptr = list1;
        head1 = list1;
        head1->ptr = dummy1;
    }
    else
    {
        temp = (struct node *)malloc(1 * sizeof(struct node));
        temp->coeff = c;
        temp->expo = e;
        head1->ptr = temp;
        temp->ptr = dummy1;
        head1 = temp;
    }
}

void create_poly2(int c, int e)
{
    dummy2 = (struct node *)malloc(1 * sizeof(struct node));
    dummy2->coeff = 0;
    dummy2->expo = 0;
    dummy2->ptr = list2;

    if (list2 == NULL)
    {
        list2 = (struct node *)malloc(1 * sizeof(struct node));
        list2->coeff = c;
        list2->expo = e;
        list2->ptr = list2;
        head2 = list2;
        head2->ptr = dummy2;
    }
    else
    {
        temp = (struct node *)malloc(1 * sizeof(struct node));
        temp->coeff = c;
        temp->expo = e;
        head2->ptr = temp;
        temp->ptr = dummy2;
        head2 = temp;
    }
}

void add_poly()
{
    temp1 = list1;
    temp2 = list2;

    while ((temp1 != dummy1) && (temp2 != dummy2))
    {
        temp = (struct node *)malloc(1 * sizeof(struct node));

        if (list3 == NULL)
        {
            list3 = temp;
            head3 = list3;
        }

        if (temp1->expo == temp2->expo)
        {
            temp->coeff = temp1->coeff + temp2->coeff;
            temp->expo = temp1->expo;
            temp->ptr = list3;
            head3->ptr = temp;
            head3 = temp;
            temp1 = temp1->ptr;
            temp2 = temp2->ptr;
        }
        else if (temp1->expo > temp2->expo)
        {
            temp->coeff = temp1->coeff;
            temp->expo = temp1->expo;
            temp->ptr = list3;
            head3->ptr = temp;
            head3 = temp;
            temp1 = temp1->ptr;
        }
        else
        {
            temp->coeff = temp2->coeff;
            temp->expo = temp2->expo;
            temp->ptr = list3;
            head3->ptr = temp;
            head3 = temp;
            temp2 = temp2->ptr;
        }
    }

    if (temp1 == dummy1)
    {
        while (temp2 != dummy2)
        {
            temp = (struct node *)malloc(1 * sizeof(struct node));
            temp->coeff = temp2->coeff;
            temp->expo = temp2->expo;
            temp->ptr = list3;
            head3->ptr = temp;
            head3 = temp;
            temp2 = temp2->ptr;
        }
    }

    if (temp2 == dummy2)
    {
        while (temp1 != dummy1)
        {
            temp = (struct node *)malloc(1 * sizeof(struct node));
            temp->coeff = temp1->coeff;
            temp->expo = temp1->expo;
            temp->ptr = list3;
            head3->ptr = temp;
            head3 = temp;
            temp1 = temp1->ptr;
        }
    }
}

void display()
{
    temp1 = list1;
    temp2 = list2;
    temp3 = list3;

    printf("\nPOLYNOMIAL 1:");

    while (temp1 != dummy1)
    {
        printf("%dX^%d+", temp1->coeff, temp1->expo);
        temp1 = temp1->ptr;
    }

    printf("\b ");

    printf("\nPOLYNOMIAL 2:");

    while (temp2 != dummy2)
    {
        printf("%dX^%d+", temp2->coeff, temp2->expo);
        temp2 = temp2->ptr;
    }

    printf("\b ");

    printf("\n\nSUM OF POLYNOMIALS:\n");

    while (temp3->ptr != list3)
    {
        printf("%dX^%d+", temp3->coeff, temp3->expo);
        temp3 = temp3->ptr;
    }

    printf("%dX^%d\n", temp3->coeff, temp3->expo);
}

void eval_poly(int x)
{
    int result = 0;
    temp1 = list1;
    temp2 = list2;

    while (temp1 != dummy1)
    {
        result += (temp1->coeff) * pow(x, temp1->expo);
        temp1 = temp1->ptr;
    }

    printf("Polynomial 1 Evaluation:%d\n", result);
    result = 0;

    while (temp2 != dummy2)
    {
        result += (temp2->coeff) * pow(x, temp2->expo);
        temp2 = temp2->ptr;
    }

    printf("Polynomial 2 Evaluation:%d\n", result);
}