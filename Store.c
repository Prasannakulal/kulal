#include<stdio.h>
#include<stdlib.h>


struct node
{
	char USN[20],name[20],dept[10];
	int m1,m2,m3;
	long phno;
	struct node *next;
	struct node *prev;
}*first = NULL,*temp = NULL, *last = NULL;	

void create()
{
	temp = (struct node *)(malloc(sizeof(struct node)));
	printf("Enter student details:\n");
	printf("USN: ");
	scanf("%s",temp->USN);
	printf("Name: ");
	scanf("%s",temp->name);
	printf("Department: ");
	scanf("%s",temp->dept);
    printf("Phone Number: ");
	scanf("%ld",&temp->phno);
	printf("Marks in 3 subjects: ");
	scanf("%d %d %d",&temp->m1,&temp->m2,&temp->m3);
	
	temp->next = NULL;
	temp->prev = NULL;
}

void insertBegin()
{
	if(first == NULL)
	{
		create();
		first = temp;
		last = temp;
	}
	else
	{
		create();
		temp->next = first;
		first->prev = temp;
		first = temp;
		
	}
	printf("\nNode successfully inserted in the front\n");
}
void insertEnd()
{
	if(first == NULL)
	{
		create();
		first = temp;
		last = temp;	
	}
	else
	{
		create();
		temp->prev = last;
		last->next = temp;
		last = temp;
	}
	printf("\nNode successfully inserted in the back\n");
}

void deleteBegin()
{
	if(first == NULL)
    {
		printf("\nError: Linked list is already empty\n");
		return;
    }
	if(first->next == NULL)
		{
			free(first);
			first = NULL;
			last = NULL;
		}	
		else
		{
			first = first->next;
			free(first->prev);
			first->prev = NULL;
		}
	printf("\nNode successfully deleted from Front\n");
}

void deleteEnd()
{
	if(first == NULL)
    {
		printf("\nError: Linked list is already empty\n");
		return;
    }    
	 if(last->prev == NULL)
		{
			free(last);
			first = NULL;
			last = NULL;
		}	
		else
		{
			last = last->prev;
			free(last->next);
			last->next = NULL;
		}
	printf("\nNode successfully deleted from End\n");
}

void displayStatus()
{
	int i,n;
	temp = first;
	if(first == NULL)
	{
	    printf("\nList is empty\n");
	    return;
	}    
	for(n=1;temp->next!=NULL;n++)
		temp=temp->next;
        temp = first;
	printf("\nList contains %d nodes\n\n",n);	
	for(i=0;i<n;i++)
	{
		printf("Details of student no. %d:\n",i+1);
		printf("USN: %s\n",temp->USN);
		printf("Name: %s\n",temp->name);
		printf("Department: %s\n",temp->dept);
		printf("Phone number: %ld\n",temp->phno);
		printf("Total marks: %d\n",(temp->m1+temp->m2+temp->m3));
		printf("Average marks: %d\n",(temp->m1+temp->m2+temp->m3)/3);
        printf("\n");
		temp = temp->next;
	}
}

void main()
{
	int n,s=0;
	char c;
	 while(s!=7)
	{
		printf("What would you like to do?\n1. Insert n nodes at end.\n2. Insert a node at the end.\n3. Insert a node in front.\n4. Delete a node from end.\n5. Delete a node from front.\n6. Display the Linked list\n7.Exit\n");
		scanf("%d",&s);
	    switch(s)
    	{
	    	case 1: 
		    	printf("Enter the value of n: ");
			    scanf("%d",&n);
			    for(int i=0;i<n;i++)
			    	insertEnd();
			    break;
		    case 2:	
		    	insertEnd();
		    	break;
		    case 3:
			    insertBegin();
			    break;
		    case 4:
                deleteEnd();
                break;
		    case 5: 
			    deleteBegin();
			    break;
			case 6:
    			displayStatus();
	    		break;						
	    }
        printf("\n");
	}
}
