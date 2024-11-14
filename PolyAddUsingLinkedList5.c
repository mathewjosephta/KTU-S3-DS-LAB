/*Exp 5: Write a Program to add Two Polynomials Using Linked List */

#include <stdio.h>
#include<stdlib.h>

struct node{
    int coef,expo;
    struct node *link;
};
struct node *Phead,*Qhead,*Rhead;

//read poly input
struct node * ReadPoly(){
    struct node *new,*ptr,*head=NULL;
    int n,i;
    
    printf("Enter the total number of terms in the polynomial : ");
    scanf("%d",&n);
    printf("Enter the COEFFICIENTS and EXPONENTS of the polynomial in DESCENDING ORDER \n");
    for(int i=1;i<=n;i++){
        printf("Enter(coef%d,expo%d) : ",i,i);
        new=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&new->coef);
        scanf("%d",&new->expo);
        new->link=NULL;
        if(head==NULL){
            head=new;
            ptr=head;
        }else{
            ptr->link=new;
            ptr=new;
        }
    }
    return(head);
}

//display polynomial
void DisplayPoly(struct node *head){
    struct node *ptr;
    if(head==NULL){
        printf("Polynomail is Empty");
    }else{
        ptr=head;
        while(ptr->link!=NULL){
            printf("%dx^%d + ",ptr->coef,ptr->expo);
            ptr=ptr->link;
        }
        printf("%dX%d\t",ptr->coef,ptr->expo);
    }
}

//Add Polynomail
struct node * AddPoly(){
    struct node *new,*P,*Q,*R,*head=NULL;
    P=Phead;
    Q=Qhead;
    while(P!=NULL && Q!=NULL){
        if(P->expo==Q->expo){
            new=(struct node *)malloc(sizeof(struct node));
            new->coef=P->coef+Q->coef;
            new->expo=P->expo;
            new->link=NULL;
            P=P->link;
            Q=Q->link;
        }else if(P->expo>Q->expo){
             new=(struct node *)malloc(sizeof(struct node));
             new->coef=P->coef;
             new->expo=P->expo;
             new->link=NULL;
             P=P->link;
        }else{
             new=(struct node *)malloc(sizeof(struct node));
             new->coef=Q->coef;
             new->expo=Q->expo;
             new->link=NULL;
             Q=Q->link;
        }if(head==NULL){
            head=new;
            R=head;
        }else{
            R->link=new;
            R=new;
        }
    }
    while(P!=NULL){
        new=(struct node *)malloc(sizeof(struct node));
        new->coef=P->coef;
        new->expo=P->expo;
        new->link=NULL;
        if(head==NULL){
            head=new;
            R=head;
        }else{
            R->link=new;
            R=new;
        }
        P=P->link;
    }
    while(Q!=NULL){
        new=(struct node *)malloc(sizeof(struct node));
        new->coef=Q->coef;
        new->expo=Q->expo;
        new->link=NULL;
        if(head==NULL){
            head=new;
            R=head;
        }else{
            R->link=new;
            R=new;
        }
        Q=Q->link;
    }
    return(head);
}
void main(){
    printf("Enter the details of First Polynomial\n");
    Phead=ReadPoly();
    printf("\nEnter the details of Second Polynomial\n");
    Qhead=ReadPoly();
    
    printf("\nFirst Polynomial : ");
    DisplayPoly(Phead);
    printf("\nSecond Polynomial : ");
    DisplayPoly(Qhead);
    
    Rhead=AddPoly();
    printf("\nResultant polynomail(SUM) : ");
    DisplayPoly(Rhead);
}

//SAMPLE OUTPUT
/*
Enter the details of First Polynomial
Enter the total number of terms in the polynomial : 3
Enter the COEFFICIENTS and EXPONENTS of the polynomial in DESCENDING ORDER 
Enter(coef1,expo1) : 5 4
Enter(coef2,expo2) : 4 3
Enter(coef3,expo3) : 2 1

Enter the details of Second Polynomial
Enter the total number of terms in the polynomial : 3
Enter the COEFFICIENTS and EXPONENTS of the polynomial in DESCENDING ORDER 
Enter(coef1,expo1) : 5 3
Enter(coef2,expo2) : 4 2
Enter(coef3,expo3) : 3 1

First Polynomial : 5X^4 + 4X^3 + 2X1	
Second Polynomial : 5X^3 + 4X^2 + 3X1	
Resultant polynomail(SUM) : 5X^4 + 9X^3 + 4X^2 + 5X1	

=== Code Exited With Errors ===
*/
