#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

typedef struct NODE_
{
	char id[100];
	char name[100];
	struct NODE_ *left;
	struct NODE_ *right;
}NODE;

NODE *head = NULL;

void Insert()
{
	NODE *index = head;
	NODE *position = NULL;
	
	char id[100];
	char name[100];
	
	system("cls");
	printf("ID: "); 
	scanf("%s", id);
	printf("Name: ");
	scanf("%s", name);
	
	
	while(index != NULL)
	{
		position = index;
		if(strcmp(id, index->id) < 0)
		{
			index = index->left;
		}
		else if(strcmp(id, index->id) > 0)
		{
			index = index->right;
		}
		else
		{
			printf("Same ID!!! :(\n\n\n");\
			return;
		}
	}
	
	NODE *newnode = (NODE *)malloc(sizeof(NODE));
	strcpy(newnode->id, id);
	strcpy(newnode->name, name);
	newnode->left = NULL;
	newnode->right = NULL;
	
	if(head == NULL)
	{
		head = newnode;
		return;
	}
	
	if(strcmp(id, position->id) < 0)
		position->left = newnode;
	else
		position->right = newnode;
}

void Search()
{
	char id[100];
	NODE *index = head;
	NODE *prev;
	system("cls");
	printf("ID: ");
	scanf("%s", id);
	
	while(index != NULL)
	{
		if(strcmp(id, index->id) == 0)
		{
			printf("\nID: %s \nName: %s \n\n\n", index->id, index->name);
			return;
		}
		else if(strcmp(id, index->id) < 0)
		{
			index = index->left;
		}
		else
		{
			index = index->right;
		}
	}
	
	printf("Cannot find... :(\n\n\n"); 
	return;
}

void Print(NODE *pNODE)
{
	if(pNODE != NULL)
	{
		Print(pNODE->left);
		printf("ID: %s \nName: %s\n\n", pNODE->id, pNODE->name);
		Print(pNODE->right);
	}
}

void Delete()
{
	NODE* dNODE = NULL;
	NODE *tmp = NULL;
	NODE *prev = NULL;
	int sw=0;
	
	char id[100];
	NODE *index = head;
	
	system("cls");
	printf("ID: ");
	scanf("%s", id);
	
	while(index != NULL)
	{
		if(strcmp(id, index->id) == 0) // ������ ���̵� �˻��� ��� 
		{
			printf("\nID: %s \nName: %s \nwill be deleted.\n\n", index->id, index->name);
			dNODE = index;
			
			if(index->right != NULL)  // �����ʿ� �ڽ� ��尡 ���� ��� 
			{
				if(prev == NULL)       // prev�� NULL�� ���. ��, ����� head�� ��� 
				{
					tmp = index->left;
					index = index->right;
					head = index;
					
					while(index->left != NULL)
					{
						index = index->left;
					}
					index->left = tmp;
				}
				else
				{
					tmp = index->left;
					
					if(sw == 1)  // prev�� ���� �ڽ� ��尡 �������� �Ŷ�� 
						prev->left = index->right;
					else  // prev�� ������ �ڽ� ��尡 �������� �Ŷ�� 
						prev->right = index->right;
					
					index = index->right;
					while(index->left != NULL)
					{
						index = index->left;
					}
					index->left = tmp;
				}	
			}
			else  // �����ʿ� �ڽ� ��尡 ���, ���� �ڽ� ��常 �ű�� �Ǵ� ���. Ȥ�� �ڽĳ�尡 ���� ���. 
			{
				if(prev==NULL)  // ���� ��尡 head
				{
					head = index->left;
				}
				else if(sw == 1)  // prev�� ������ �������� �Ŷ��
				{ 
					prev->left = index->left;
				}
				else  // prev�� �������� �������� �Ŷ�� 
				{
					prev->right = index->left;
				}
			}
			
			free(dNODE);
			Sleep(500);
			puts("Deleting Complete.");
			return;
		}
		else if(strcmp(id, index->id) < 0)
		{
			prev = index;
			sw = 1;
			index = index->left;
		}
		else
		{
			prev = index;
			sw = 2;
			index = index->right;
		}
	}
		
	printf("Cannot find... :(\n\n\n"); 
	return;
}




int main()
{
	int ch;
	
	while(1)
	{
		system("cls");
		puts("1. Insert");
		puts("2. Search");
		puts("3. Print");
		puts("4. Delete");
		puts("5. Exit");
		puts("");
		printf(": ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:
				Insert();
				break;
			case 2:
				Search();
				break;
			case 3:
				Print(head);
				break;
			case 4:
				Delete(head);
				break;
			case 5:
				return;
				return;
			default:
				continue;
		}
		system("pause");
	}
		
	return 0;
}
