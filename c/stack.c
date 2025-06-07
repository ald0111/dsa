#include <stdio.h>
#include <stdlib.h>

struct node
{
    char val;
    struct node *pre;
};

typedef struct node Node;

Node *newNode(char val)
{
    Node *myNode = (Node *)malloc(sizeof(Node));
    myNode->val = val;
    myNode->pre = NULL;
    return myNode;
}

Node *popFromStack(Node *top)
{
    Node *temp = top->pre;
    free(top);
    return temp;
}

Node *pushToStack(Node *top, Node *new)
{
    new->pre = top;
    return new;
}

int main()
{
    Node *top = newNode('0');
    int hasPopOccured = 0;
    int globalStart = 0;
    int globalEnd = 0;
    char str[] = "abeebabeeeeeeeeeeeeb";
    for (int i = 0; i < 20; i++)
    {
        char localVal = top->val;
        char secondLocalVal = '0';
        if (top->pre != NULL)
        {
            secondLocalVal = top->pre->val;
        }

        if (hasPopOccured == 0 && str[i] != localVal)
        {
            if (hasPopOccured == 0 && str[i] == secondLocalVal)
            {
                top = popFromStack(top);
                top = popFromStack(top);
                hasPopOccured = 1;
                continue;
            }
            top = pushToStack(top, newNode(str[i]));
            continue;
        }
        if (hasPopOccured == 0 && str[i] == localVal)
        {
            // pushToStack(top, newNode(str[i]));
            continue;
        }
        if (hasPopOccured == 1 && str[i] == localVal)
        {
            top = popFromStack(top);
        }
        if (hasPopOccured == 1 && str[i] != localVal)
        {
            // pushToStack(top, newNode(str[i]));
            // printf("%d\n", i);
            int myLen = 0;
            while (top->val != '0')
            {
                top = popFromStack(top);
                myLen++;
            }
            if (i - globalEnd + myLen > (globalEnd - globalStart))
            {
                globalStart = globalEnd + myLen;
                globalEnd = i - 1;
            }
            top = pushToStack(top, newNode(str[i]));
            hasPopOccured = 0;
        }
    }

    printf("%d %d \n", globalStart, globalEnd);
    for (size_t i = globalStart; i < (globalEnd + 1); i++)
    {
        printf("%c", str[i]);
    }

    return 0;
}