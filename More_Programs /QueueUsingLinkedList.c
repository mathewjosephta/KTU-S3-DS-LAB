//Implemetation of Queue using Linked List
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *front, *rear;

//Display method
void Display(){
    struct node *ptr;
    if(front==NULL){
        printf("Queue is Empty...");
    }else{
        ptr=front;
        printf("\nQueue elements are :");
        while(ptr!=NULL){
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }
    }
}

//ENQUEUE method
void ENQUEUE(int item){
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    new->data=item;
    new->link =NULL;
    if(front==NULL){
        front=rear=new;
    }else{
        rear->link=new;
        rear=new;
    }
    Display();
}

//DEQUEUE method
void DEQUEUE(){
    struct node *temp;
    if(front==NULL){
        printf("\nQueue is Empty ");
    }else if(front==rear){
        temp=front;
        front=rear=NULL;
        free(temp);
        Display();
    }else{
        temp=front;
        front=front->link;
        free(temp);
        Display();
    }
}
//Main method
void main(){
    int choice , item;
    do{
        printf("\n\n***Enter the option***\n1.ENQUEUE\n2.DEQUEUE\n3.Display\n4.Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the new data : ");
                    scanf("%d",&item);
                    ENQUEUE(item);
                    break;
            case 2: DEQUEUE();
                    break;
            case 3: Display();
        }
    }while(choice!=4);
}

//SAMPLE OUTPUT
/*


***Enter the option***
1.ENQUEUE
2.DEQUEUE
3.Display
4.Exit
Enter Your Choice : 1
Enter the new data : 10

Queue elements are :10	

***Enter the option***
1.ENQUEUE
2.DEQUEUE
3.Display
4.Exit
Enter Your Choice : 1
Enter the new data : 20

Queue elements are :10	20	

***Enter the option***
1.ENQUEUE
2.DEQUEUE
3.Display
4.Exit
Enter Your Choice : 2

Queue elements are :20	

***Enter the option***
1.ENQUEUE
2.DEQUEUE
3.Display
4.Exit
Enter Your Choice : 3

Queue elements are :20	

***Enter the option***
1.ENQUEUE
2.DEQUEUE
3.Display
4.Exit
Enter Your Choice : 4


=== Code Exited With Errors ===
*/
