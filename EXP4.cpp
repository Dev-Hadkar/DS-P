#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void insertBegin(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
void insertEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertPosition(int value, int pos)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node *temp = head;
    int i;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid Position!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void DeleteBegin()
{
    if (head == NULL)
    {
        printf("Linked List is Empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Element deleted is %d\n", head->data);
    head = head->next;
    free(temp);
}

void DeleteEnd()
{
    if (head == NULL)
    {
        printf("Linked List is Empty.\n");
        return;
    }
    if (head->next == NULL)
    {
        printf("Element deleted is %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    printf("Element deleted is %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}
void DeletePosition(int pos)
{
    if (head == NULL)
    {
        printf("Linked List is Empty.\n");
        return;
    }
    if (pos == 1)
    {
        struct Node *temp = head;
        printf("Element deleted is %d\n", head->data);
        head = head->next;
        free(temp);
        return;
    }
    struct Node *temp = head;
    struct Node *ptr;
    int i;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid Position!\n");
        return;
    }
    ptr = temp->next;
    printf("Element deleted is %d\n", ptr->data);
    temp->next = ptr->next;
    free(ptr);
}
void display()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("Linked List is Empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int choice, value, pos;
    do
    {
        printf("\n----- Linked List Menu -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBegin(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertPosition(value, pos);
                break;

            case 4:
                DeleteBegin();
                break;

            case 5:
                DeleteEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                DeletePosition(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }
    } while (choice != 8);
}
