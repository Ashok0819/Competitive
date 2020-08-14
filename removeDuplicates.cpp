/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
using namespace std;

/*
void shift_zeroes(int *arr, int size)
{
    int left = 0, right = size - 1;
    while(left < right)
    {
        if(arr[right] == 0)
        {
            right--;
            continue;
        }
        
        if(arr[left] == 0)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
        left++;
    }
}

int main()
{
    int arr[] = {0, 0, 0, 0, 0, 77, 0};
    shift_zeroes(arr, sizeof(arr) / sizeof(arr[0]));
    for(int i = 0; i < 9; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
*/

struct Node
{
    int data;
    struct Node *next;
};

struct LinkedList
{
    int size;
    struct Node *head;
    struct Node *tail;
};

int initialize(LinkedList *l1)
{
    int status = -1;
    l1 -> size = 0;
    l1 -> head = NULL;
    l1 -> tail = NULL;
    status = 0;
    return status;
}

struct Node* allocateMemory()
{
    return (struct Node*)(malloc(sizeof(Node)));    
}

int addToHead(LinkedList *l1, int dataToAdd)
{
    int status = -1;
    Node *temp = allocateMemory();
    if(temp != NULL)
    {
        temp -> data = dataToAdd;
        temp -> next = l1 -> head;
        l1 -> head = temp;
        
        if(l1 -> tail == NULL)
        {
            l1 -> tail = temp;
        }
        l1 -> size++;
        status = 0;
    }
    return status;
}

int addToTail(LinkedList *l1, int dataToAdd)
{
    int status = -1;
    Node *temp = allocateMemory();
    if(temp != NULL)
    {
        temp -> next = NULL;
        temp -> data = dataToAdd;
        if(l1 -> tail == NULL)
        {
            l1 -> head = temp;
        }
        
        else
        {
            l1 -> tail -> next = temp;
        }
        l1 -> tail = temp;
        l1 -> size++;
        status = 0;
    }
    return status;
}

void printList(Node *head)
{
    if(head == NULL)
    {
        return;
    }
    
    else
    {
        printf("%d ", head -> data);
        printList(head -> next);
    }
}

void removeDuplicates(LinkedList *l1)
{
    stack<Node*> inProcess;
    Node *temp = l1 -> head;
    Node *nodeToRemove = NULL;
        
    while(temp != NULL && temp -> next != NULL)
    {
        if(temp -> data == temp -> next -> data)
        {
            nodeToRemove = temp;
            if(!inProcess.empty())
            {
                inProcess.top() -> next = temp -> next -> next;
                temp = inProcess.top();
                inProcess.pop();
            }
                
            else
            {
                l1 -> head = temp -> next -> next;
                temp = l1 -> head;
            }
            delete nodeToRemove -> next;
            delete nodeToRemove;
        }
            
        else
        {
            inProcess.push(temp);
            temp = temp -> next;
        }
    }
}

int main()
{
    LinkedList l1;
    initialize(&l1);
    addToTail(&l1, 5);
    addToTail(&l1, 4);
    addToTail(&l1, 3);
    addToTail(&l1, 3);
    addToTail(&l1, 4);
    addToTail(&l1, 5);
    addToTail(&l1, 7);
    //addToTail(&l1, 5);
    printList(l1.head);
    printf("\nAfter removing duplicates\n");
    removeDuplicates(&l1);
    printList(l1.head);
}
