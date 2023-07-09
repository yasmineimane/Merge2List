#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}Node;
Node *head,*head1,*head2,*tmp,*current;

int read_nbr();
Node *creatList(int);
void DisplayList(Node *);
Node *MergeLinkedList(Node *, Node *);
Node *ReorderList(Node *);

int main(int argc, char const *argv[])
{
    int Input1 = read_nbr();
    int Input2 = read_nbr();
    DisplayList(ReorderList(MergeLinkedList(creatList(Input1),creatList(Input2))));
    return 0;
}

int read_nbr(){
    int n;
    printf("Input the size of the linked list : ");
    scanf("%d",&n);
    return n;
}

Node *creatList(int n)
{
    int data;
    printf("Input the data for n : 1 : ");
    scanf("%d",&data);
    head = (Node *)malloc(sizeof(Node));
    head -> data = data;
    head -> next = NULL;
    tmp = head;
    for (int i = 2; i <= n; i++)
    {
        printf("Input the data for n : %d : ",i);
        scanf("%d",&data);
        current = (Node *)malloc(sizeof(Node));
        current -> data = data;
        current -> next = NULL;
        tmp -> next = current;
        tmp = current ;
    }
    return head;
}

void DisplayList(Node *head){
    tmp = head;
    while (tmp != NULL)
    {
        printf("%d\t",tmp -> data);
        tmp = tmp -> next;
    }
}

Node *MergeLinkedList(Node *head1, Node *head2){
    if (head1 == NULL)
    {
        head1 = head2;
    }
    if (head1 -> next == NULL)
    {
        head1 -> next = head2;
    }
    else {
        tmp = head1;
        while (tmp -> next != NULL)
        {
            tmp = tmp -> next;
        }
        tmp -> next = head2;
    }
    return head1;
    
}

Node *ReorderList(Node *head){
    int data;
    tmp = head;
    while (tmp != NULL)
    {
        current = tmp -> next;
        while (current != NULL)
        {
            if (current -> data < tmp -> data)
            {
                data = current -> data;
                current -> data = tmp -> data;
                tmp -> data = data;
            }
            current = current -> next;
        }
        tmp = tmp -> next;
    }
    return head;
}