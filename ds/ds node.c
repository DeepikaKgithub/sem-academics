#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    int usn;
    char name[20];
    char branch[20];
    int semester;
    char phone[20];
}student;
struct node
{
    int usn;
    char name[20];
    char branch [20];
     int semester;
    char phone[20];
    struct node *link;
};
typedef struct node *Node;
Node getnode()
{
    Node X;
    X=(Node)malloc(size of (struct node));
    if(x==Null)
    {
        printf("out of memory\n");
        exit((0));
    }
    return X;
}
NODE insert_front(student item,NODE first)
{
    NODE temp;
    temp=getnode();
    temp->usn=item.usn;
    strcpy(temp->name,item.name);
    strcpy(temp->branch,item.branch);
   temp->semester=item.semester;
   strcpy(temp->phone,item.phone);
   item->link=NULL;
   if(first==NULL)
   return temp;
   temp->link=first;
return temp;
}
NODE insert_rear(STUDENT item,NODE first)
{
NODE temp,cur;
temp=getnode();
temp->usn=item.usn;
strcpy(temp->name,item.name);
strcpy(temp->branch,item.branch);
temp->semester=item.semester;
strcpy(temp->phone,item.phone);
temp->link=NULL;
if(first==NULL)
return temp;
   cur=first;
   while(cur->link!=NULL)
   {
    cur=cur->link;
   } 
   cur->link=temp;
   return first;
}
NODE delete_front(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("student list is empty \n");
        return NULL;
    }
    temp=first;
    temp=temp->link;
    printf("delete student record :USN=%d",first->usn);
    free(first);
    return temp;
}
NODE delete_rear(NODE first)
{
    NODE cur,prev;
    if(first==NULL)
}
printf("student list is empty cannot delete\n");
