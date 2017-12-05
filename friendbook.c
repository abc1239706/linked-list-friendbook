#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct friendbook
{
	char name[10];
	int age;
	struct friendbook *next;
} myfriend;


myfriend *create_newfriend()
{
	char newName[10];
	int newAge;
	printf("Please press name:\n");
	scanf("%s",newName);
	printf("Please press age:\n");
	scanf("%d",&newAge);
	
	myfriend *newFriend = (myfriend*)malloc(sizeof(myfriend));
	strcpy(newFriend->name,newName);
	newFriend->age=newAge;
	newFriend->next=NULL;
	
	return newFriend;
}


void insert_friend_lsit(myfriend *oldfriend,myfriend *newfriend)
{
	newfriend->next=oldfriend->next;
	oldfriend->next=newfriend;
}


void print_friend(myfriend *list)
{
	printf("Number Name Old NextAddress\n");
	myfriend *node = list;
	int number = 1;
	while(node != NULL)
	{
		printf("  %d  %s %d  %p.\n",number,node->name,node->age,node->next);
		node=node->next;
		number++;
	}
	
	printf("Print Complete\n");
}


void search_and_remove_friend(myfriend *friend_list)
{	
	char badfriend[10];
	int find=0;
	myfriend *remove_node;
	myfriend *pre_node;
	myfriend *check_node=friend_list;
	printf("Who do you want to remove from the friend book?\n");
	scanf("%s", badfriend);
	while(find==0)
	{
		if(check_node==NULL)
		{
			printf("This friend isn't found in your friendbook.\n");
			find=1;
		}
		else
		{
			if(strcmp(check_node->name, badfriend)==0)
			{
				remove_node = check_node;
				pre_node->next=pre_node->next->next;
				free(remove_node);
				printf("Remove complete!\n");
				find=1;
			}
			else
			{
				pre_node = check_node;
				check_node=check_node->next;
			}
		}
	} 
	
	
}




int main()
{
	myfriend *friend_list=NULL;
	myfriend *newfriend_node;
	int choice=0;
	while(choice!=5)
	{
		printf("--------------------------------------------------------------\n");
		printf("Welcome to my friend book. What do you want to do ?\n");
		printf("Press 1 to create friend.\n");
		printf("Press 2 to remove friend.\n");
		printf("Press 5 to exit this program.\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				
				if(friend_list==NULL)
				{
					friend_list=create_newfriend();
				}
				else
				{
					newfriend_node=create_newfriend(); 
					insert_friend_lsit(friend_list,newfriend_node);
				}
 
				print_friend(friend_list);
				break;
				
			case 2:
				
				search_and_remove_friend(friend_list);
				print_friend(friend_list);
				break;
				
			case 5:
				break;
				
			default:
				break;
		}
	}
	
	system("pause");
	return 0;
} 
