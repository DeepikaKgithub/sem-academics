#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>  
struct poly 
{ 
int cf,px,py,pz; int flag; 
struct poly *link; 
}; 
typedef struct poly *NODE; 
NODE insertrear(NODE h,int cf,int px,int py,int pz) 
{ 
NODE temp,cur;  
temp=(NODE)malloc(sizeof(struct poly));  
temp->cf=cf; 
temp->px=px; 
temp->py=py;  
temp->pz=pz; 
if(h->link==h) 
{ 
h->link=temp;   
temp->link=h; 
return  temp;  
} 
cur=h->link; 
while(cur->link!=h) 
cur=cur->link; 
cur->link=temp;  
temp->link=h;  
return temp; 
} 
void readpoly(NODE h) 
{ 
int cf,px,py,pz,ch; 
do 
{ 
printf("enter co-eff,px,py,pz:"); 
scanf("%d%d%d%d",&cf,&px,&py,&pz); 
h=insertrear(h,cf,px,py,pz); 
printf("\n1 to continue 0 to exit:");  
scanf("%d",&ch); 
} while(ch!=0);  
return ; 
} 
void evalpoly(NODE h1) 
{ 
   int x,y,z; 
   float result=0.0; NODE temp=h1->link; 
   printf("\nenter the value of x,y,z:"); 
   scanf("%d%d%d",&x,&y,&z); 
   while(temp!=h1) 
     { 
       result=result+temp->cf*pow(x,temp->px)*pow(x,temp->py)*pow(z,temp->pz); 
       temp=temp->link; 
     } 
   printf("\nthe result=%f\n",result); 
} 
 
void display(NODE h1) 
{ 
   NODE temp; 
   if(h1->link==h1) 
    { 
      printf("\npolynomial is empty");  
      return; 
    } 
   temp=h1->link; 
   while(temp!=h1) 
     { 
       if(temp->cf>0) 
            printf("+%dx%dy%dz%d",temp->cf,temp->px,temp->py,temp->pz);  
       else 
            printf("%dx%dy%dz%d",temp->cf,temp->px,temp->py,temp->pz); 
       temp=temp->link; 
      } 
} 
 
void addpoly(NODE h1,NODE h2,NODE h3) 
 { 
   NODE p1,p2; 
   int cf1,px1,py1,pz1,cf2,px2,py2,pz2,cf;  
   p1=h1->link; 
   while(p1!=h1) 
     { 
       cf1=p1->cf; px1=p1->px; py1=p1->py; pz1=p1->pz;  
       p2=h2->link; 
       while(p2!=h2) 
          { 
            cf2=p2->cf; px2=p2->px; py2=p2->py; pz2=p2->pz; 
            if(px1==px2&&py1==py2&&pz1==pz2) 
                  break; 
            p2=p2->link; 
          } 
       if(p2!=h2) 
         { 
           cf=cf1+cf2;  
           p2->flag=1;  
           if(cf!=0) 
               h3=insertrear(h3,cf,px1,py1,pz1); 
           p1=p1->link; 
           p2=p2->link; 
         } 
       else 
         { 
           h3=insertrear(h3,cf1,px1,py1,pz1); 
           p1=p1->link; 
          } 
    } 
  p2=h2->link; 
  while(p2!=h2) 
     { 
       if(p2->flag==0) 
          h3=insertrear(h3,p2->cf,p2->px,p2->py,p2->pz);  
       p2=p2->link; 
     } 
   return ; 
} 
 
void main() 
{ 
  int ch; 
  NODE h1,h2,h3; 
  h1=(NODE)malloc(sizeof(struct poly)); 
  h2=(NODE)malloc(sizeof(struct poly));  
  h3=(NODE)malloc(sizeof(struct poly)); 
  h1->link=h1; h2->link=h2; h3->link=h3; 
  while(1) 
    { 
       printf("\n1.evaluate a polynomial\n2.add polynomial\n3.exit\n");  
       printf("enter choice:"); 
       scanf("%d",&ch); 
       switch(ch) 
         { 
           case 1 : printf("enter polynomial:");  
                        readpoly(h1);  
                        evalpoly(h1); 
                        display(h1); 
                        h1->link=h1;  
                        break; 
           case 2 : printf("enter 1st polynomial:");  
                        readpoly(h1); 
                        printf("enter 2nd polynomial:");  
                        readpoly(h2);  
                        addpoly(h1,h2,h3); 
                        printf("\n1st polynomial is\n"); 
                        display(h1);printf("\n");  
                        printf("\n2nd polynomial is\n"); 
                        display(h2);printf("\n");  
                         printf("\nresultant polynomial is \n");  
                         display(h3);printf("\n"); 
                         break;  
           case 3 : exit(0); 
          } 
      } 
}