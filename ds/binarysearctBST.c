 #include<stdio.h>
 #include<stdlib.h> 
struct node 
{ 
  int info; 
  struct node *llink; 
  struct node *rlink; 
}; 
typedef struct node *NODE; 
NODE insert(NODE root,int item) 
{ 
  NODE temp,cur,prev; 
  temp=(NODE)malloc(sizeof(NODE)); 
  temp->info=item; 
  temp->llink=temp->rlink=NULL; 
  if(root==NULL) 
    return temp; 
  cur=root; 
   while(cur!=NULL) 
   { 
    prev=cur; 
     if(cur->info==item) 
     { 
       printf("insertion not possible"); 
       free(temp); 
       return; 
     } 
    if(cur->info > item) 
    cur=cur->llink; 
    else 
     cur=cur->rlink; 
   } 
  if(prev->info>item) 
   prev->llink=temp; 
  else  
   prev->rlink=temp; 
  return root; 
} 
void search(NODE root,int key) 
{ 
  NODE cur; 
  cur=root; 
     if(root==NULL) 
   { 
   printf("tree is empty"); 
     return; 
   } 
   while(cur!=NULL) 
   { 
     if(cur->info==key) 
     { 
       printf("key element is found"); 
      return; 
     } 
    if((cur->info)>key) 
     cur=cur->llink; 
    else  
     cur=cur->rlink; 
   } 
  printf("key not found"); 
}  
void preorder(NODE root) 
{ 
 if(root==NULL) return; 
 printf("%d\t",root->info); 
 preorder(root->llink); 
 preorder(root->rlink); 
} 
void postorder(NODE root) 
{ 
  if(root==NULL)return; 
  postorder(root->llink); 
  postorder(root->rlink); 
  printf("%d\t",root->info); 
} 
void inorder(NODE root) 
{ 
  if(root==NULL)return; 
  inorder(root->llink); 
  printf("%d\t",root->info); 
  inorder(root->rlink); 
} 
void main() 
{ 
    int ch,x,item,key; 
    NODE root=NULL; 
     while(1) 
     { 
      printf("\n1.create a BST\n2.traverse inpreorder\n3.traverse in postorder\n4.inorder"); 
      printf("\n5.search in a BST\n6.exit"); 
      printf("\nenter choice:"); 
     scanf("%d",&ch); 
       switch(ch) 
       { 
        case 1 :  do 
                  { 
                  printf("enter the element to be inserted:"); 
                  scanf("%d",&item); 
                  root=insert(root,item); 
                  printf("enter 1 to continue 0 to exit"); 
                  scanf("%d",&x); 
                  }while(x!=0); 
                 break; 
        case 2 : preorder(root);  
                 break; 
        case 3 : postorder(root); 
                 break; 
        case 4 : inorder(root); 
                 break; 
        case 5 : printf("enter the element to search:"); 
                 scanf("%d",&key); 
                 search(root,key); 
                 break; 
        case 6 : exit(0); 
      } 
   } 
}            