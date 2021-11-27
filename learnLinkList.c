#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
    int num;
    struct _listnode *next;
} ListNode;


void printList(ListNode *head)
{
    ListNode *cache = head;
    while (cache != NULL)
    {
        printf("%d\t", cache->num);
        cache = cache->next;
    }
}

ListNode *findNode(ListNode *head, int i)
{
    ListNode *cur = head;
    if ((head == NULL) || (i < 0))
    {
        printf("\nDanh sach lien ket rong hoac phan tu tim kiem khong ton tai");
        return NULL;
    }
    while (i > 0)
    {
        cur = cur->next;
        i = i - 1;
        if (cur == NULL)
        {
            printf("\nPhan tu tim kiem khong ton tai");
            return NULL;
        }
    }
    return cur;
}

void insertNode(ListNode **pHead, int index, int value)
{
    ListNode *cur, *newNode;

    if (*pHead == NULL || index == 0) //start by index 0 && list none node
    {
        newNode = (ListNode *)malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = *pHead;
        *pHead = newNode;
    }
    else if ((cur = findNode(*pHead, index - 1)) != NULL)
    {
        newNode = (ListNode *)malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = cur->next;
        cur->next = newNode;
    }
    else
        printf("\ncan not insert the new item at index %d!\n", index);
}

void removeNode(ListNode **ptrHead, int index)
{   
    ListNode *cur, *pre;
    if(index == 0) {
        cur = *ptrHead;
        *ptrHead = cur->next;
        free(cur);
    }
    else {
        pre = findNode(*ptrHead, index - 1);
        cur = pre->next;
        pre->next = cur->next;
        free(cur);
    }
}

int main()
{
    int n;
    ListNode *newNode, *head = NULL;
    scanf("%d", &n);
    if(n > 0) {
        newNode = malloc(sizeof(ListNode));
        head = newNode;
        for (int i = 1; i < n; i++) {
            scanf("%d", &newNode->num);
            newNode->next = malloc(sizeof(ListNode));
            newNode = newNode->next;
        }
        scanf("%d", &newNode->num);
        newNode->next = NULL;
    }
    

    printList(head);

    insertNode(&head, 3, 40);
    printList(head);

    removeNode(&head, 1);
    printList(head);
}
