//Implementation of Stack Operations using Linked List

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *top;

//Display method
void Display(){
    struct node *ptr;
    if(top==NULL){
        printf("Stack is Empty...");
    }else{
        ptr=top;
        printf("\nStack elements are :");
        while(ptr!=NULL){
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }
    }
}

//PUSH method
void PUSH(int item){
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    new->data=item;
    new->link =top;
    top=new;
    Display();
}

//POP method
void POP(){
    struct node *temp;
    if(top==NULL){
        printf("\nStack is Empty ");
    }else{
        temp=top;
        printf("Popped item is %d",top->data);
        top=top->link;
        free(temp);
        Display();
    }
}
//Main method
void main(){
    int choice , item;
    do{
        printf("\n\n***Enter the option***\n1.PUSH\n2.POP\n3.Display\n4.Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the new data : ");
                    scanf("%d",&item);
                    PUSH(item);
                    break;
            case 2: POP();
                    break;
            case 3: Display();
        }
    }while(choice!=4);
}

//SAMPLE OUTPUT
/*


***Enter the option***
1.PUSH
2.POP
3.Display
4.Exit
Enter Your Choice : 1
Enter the new data : 10

Stack elements are :10	

***Enter the option***
1.PUSH
2.POP
3.Display
4.Exit
Enter Your Choice : 1
Enter the new data : 20

Stack elements are :20	10	

***Enter the option***
1.PUSH
2.POP
3.Display
4.Exit
Enter Your Choice : 2
Popped item is 20
Stack elements are :10	

***Enter the option***
1.PUSH
2.POP
3.Display
4.Exit
Enter Your Choice : 3

Stack elements are :10	

***Enter the option***
1.PUSH
2.POP
3.Display
4.Exit
Enter Your Choice : 4


=== Code Exited With Errors ===
*/
