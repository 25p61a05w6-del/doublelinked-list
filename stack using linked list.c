
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
	int data;
	struct node *next;
};
 
struct node *top = NULL;
 
/* Function declarations */
void push();
void pop();
void peek();
void display();
 
int main()
{
	int choice;
 
	while(1)
	{
    	printf("\n--- Stack Using Linked List ---\n");
    	printf("1. Push\n");
    	printf("2. Pop\n");
    	printf("3. Peek\n");
    	printf("4. Display\n");
    	printf("5. Exit\n");
    	printf("Enter your choice: ");
    	scanf("%d", &choice);
 
    	switch(choice)
    	{
        	case 1: push(); break;
        	case 2: pop(); break;
        	case 3: peek(); break;
        	case 4: display(); break;
        	case 5: exit(0);
        	default: printf("Invalid choice\n");
    	}
	}
}
 
/* Push operation */
void push()
{
	struct node *ptr;
	int value;
 
	ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr == NULL)
	{
    	printf("Stack Overflow\n");
    	return;
	}
 
	printf("Enter element to push: ");
	scanf("%d", &value);
 
	ptr->data = value;
	ptr->next = top;
	top = ptr;
 
	printf("Element pushed successfully\n");
}
 
/* Pop operation */
void pop()
{
	struct node *temp;
 
	if(top == NULL)
	{
    	printf("Stack Underflow\n");
    	return;
	}
 
	temp = top;
	printf("Popped element: %d\n", temp->data);
	top = top->next;
	free(temp);
}
 
/* Peek operation */
void peek()
{
	if(top == NULL)
	{
    	printf("Stack is empty\n");
    	return;
	}
 
	printf("Top element: %d\n", top->data);
}
 
/* Display operation */
void display()
{
	struct node *temp;
 
	if(top == NULL)
	{
    	printf("Stack is empty\n");
    	return;
	}
 
	temp = top;
	printf("Stack elements:\n");
	while(temp != NULL)
	{
    	printf("%d\n", temp->data);
    	temp = temp->next;
	}
}
