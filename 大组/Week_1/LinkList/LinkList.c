#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "LinkList.h"

void printmenu()
{
	system("cls");
	printf("    ��    ��    ��    ��\n");
	printf("*************************\n");
	printf("*     1.��ʼ������      *\n");
	printf("*     2.�����½��      *\n");
	printf("*     3.�����������    *\n");
	printf("*     4.�м�������    *\n");
	printf("*     5.��ż����        *\n");
	printf("*     6.��ת����        *\n");
	printf("*     7.ɾ�����        *\n");
	printf("*     8.�ݻ�����        *\n");
	printf("*     9.�˳�ϵͳ        *\n");
	printf("*************************\n");
}

void Listcreat(Node** head)
{
	int num,i;
	printf("�����봴����������");
	if(scanf("%d",&num)!=1)
	{
		printf("�������\n");
		while(getchar()!='\n')		//��������� 
			continue;
		system("pause");
		return; 
	}
	getchar();
	*head=(Node*)malloc(sizeof(Node));
	Node* ptr=*head;
	for(i=0;i<num;i++)
	{
		Node* newnode=(Node*)malloc(sizeof(Node));
		printf("�������%d���������ݣ�",i+1);
		gets(newnode->data);
		ptr->next=newnode;
		newnode->next=NULL;
		ptr=ptr->next;
	}
	printf("��ʼ���ɹ���\n");
	system("pause");
	return ;
}

void insert(Node** head) 
{
	int i,pos,select,flag=1;
	if(*head==NULL)
	{
		printf("����δ��ʼ�������ȳ�ʼ������\n");
		return;
	}
	printf("�������ݣ�");
	printlist(*head);
	printf("������Ҫ�����λ�ã�");
	if(scanf("%d",&pos)!=1)
	{
		printf("�������\n");
		while(getchar()!='\n')
			continue;
		return; 
	}
	Node *ptr=(*head)->next;
	Node *plast=*head;
	for(i=1;i<pos;i++)
	{
		if(ptr==NULL)
		{
			printf("����������ô���𣿣���\n");
			getchar();
			return;
		}
		ptr=ptr->next;
		plast=plast->next;
	}
	printf("������Ҫ����Ľ�����ݣ�");
	Node* newnode=(Node*)malloc(sizeof(Node));
	getchar();
	gets(newnode->data);
	printf("��ѡ�����λ�ã�ǰ1/��2����");
	while(flag)
	{
		if(scanf("%d",&select)!=1)
		{
			printf("�������\n"); 
			while(getchar()!='\n')
				continue;
			return;
		}
		switch(select)
		{
			case 1:
			{
				flag=0;
				newnode->next=ptr;
				plast->next=newnode;
				printf("����ɹ���\n");
				getchar(); 
				break;
			}
			case 2:
			{ 
				flag=0;	
				if(ptr->next!=NULL)
				{
					newnode->next=ptr->next;
					ptr->next=newnode;
				}else{
					newnode->next=NULL;	
				}
				ptr->next=newnode;
				printf("����ɹ���\n"); 
				getchar();
				break;
			} 
			default:
				printf("�������\n");
				getchar();
				return;
		}
	}
	
}

void printlist(Node* head)
{
	if(head==NULL)
	{
		printf("����δ��ʼ�������ȳ�ʼ������\n");
		return;
	} 
	Node* ptr=head->next; 
	while(ptr!=NULL)
	{
		printf("%s->",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL\n");
}

void printmid(Node* head)
{
	int num=0,i,result;
	if(head==NULL)
	{
		printf("����δ��ʼ�������ȳ�ʼ������\n");
		return;
	}
	Node *ptr=head->next;
	while(ptr)
	{
		ptr=ptr->next;
		num++;
	}
	ptr=head->next;
	printf("�м�������Ϊ��");
	if(num%2==1)
	{
		for(i=1;i<(num/2+1);i++)
			ptr=ptr->next;
			printf("%s\n",ptr->data);
	}else{
		for(i=1;i<num/2;i++)
			ptr=ptr->next;
			printf("%s,%s\n",ptr->data,ptr->next->data);
	}
}


void exchange(Node** head)
{
	int num=0,i;
	if(*head==NULL)
	{
		printf("����δ��ʼ�������ȳ�ʼ������\n");
		return;
	}
	Node *ptr=(*head)->next;
	while(ptr)
	{
		ptr=ptr->next;
		num++;
	}
	Node* oddptr=(*head)->next;
	Node* evenptr=oddptr->next;
	if(num==1)
	{
		printf("ֻ��һ����㡣����\n");
		return;
	}
	//�Ƚ�����һ��������� 
	(*head)->next=evenptr;
	oddptr->next=evenptr->next;
	evenptr->next=oddptr;
	ptr=oddptr;		//��¼������λ��
	for(i=1;i<=(num/2)-1;i++)
	{
		oddptr=ptr->next;
		evenptr=oddptr->next;
		ptr->next=evenptr;
		oddptr->next=evenptr->next;
		evenptr->next=oddptr;
		ptr=oddptr;
	}
	printlist(*head);
	printf("�����ɹ���\n");
}

void reverselist(Node** head)
{
	if(*head==NULL)
	{
		printf("����δ��ʼ�������ȳ�ʼ������\n");
		return;
	}
	Node* ptr,* last,* next;
	ptr=(*head)->next;
	last=*head;
	next=ptr->next;
	if(next==NULL)
	{
		printf("ֻ��һ����㡣��\n");
		return;
	}
	ptr->next=NULL;
	last=ptr;
	ptr=next;
	next=next->next;
	while(next)
	{
		ptr->next=last;
		last=ptr;
		ptr=next;
		next=next->next;
	}
	ptr->next=last;
	(*head)->next=ptr;
	printlist(*head);
	printf("��ת�ɹ���");
}

void deletenode(Node** head)
{
	int i,pos;
	if(*head==NULL)
	{
		printf("����δ��ʼ�������ȳ�ʼ������\n");
		return;
	}
	Node *ptr=(*head)->next;
	Node *last=*head;
	printf("�������ݣ�");
	printlist(*head);
	printf("������Ҫɾ������λ�ã�");
	if(scanf("%d",&pos)!=1)
	{
		printf("�������\n"); 
		while(getchar()!='\n')
			continue;
		return;
	}
	for(i=1;i<pos;i++)
	{
		if(ptr==NULL)
		{
			printf("Ҫɾ�ĸ�������\n");
			getchar(); 
			return; 
		}
		ptr=ptr->next;
		last=last->next;
	}
	if(ptr->next!=NULL)
	{
		last->next=ptr->next;
	}else{
		last->next=NULL;
	}
	ptr->next=NULL;
	free(ptr);
	printf("ɾ����ϣ�\n");
	getchar();
} 

void destory(Node** head)
{
	if(*head==NULL)
	{
		printf("����δ��ʼ�������ȳ�ʼ������\n");
		return;
	}
	Node* ptr;
	while((*head)->next)
	{
		ptr=*head;
		*head=(*head)->next;
		free(ptr);
	}
	free(*head);
	*head=NULL;
	printf("����ݻ����!\n"); 
}

int main()
{
	char input[20];
	Node* head=NULL;
	while(strcmp(input,"9")!=0)
	{
		printmenu();
		printf("��ѡ����еĲ���:");
		gets(input);
		if(strcmp(input,"1")==0)
		{
			if(head==NULL){
				Listcreat(&head);
			}else{
				printf("�����ѳ�ʼ���������ظ�������\n");
				system("pause");
			}
		}else if(strcmp(input,"2")==0){
			insert(&head);
			system("pause");
		}else if(strcmp(input,"3")==0){
			printlist(head);
			system("pause");
		}else if(strcmp(input,"4")==0){
			printmid(head);
			system("pause");
		}else if(strcmp(input,"5")==0){
			exchange(&head);
			system("pause");
		}else if(strcmp(input,"6")==0){
			reverselist(&head);
			system("pause");
		}else if(strcmp(input,"7")==0){
			deletenode(&head);
			system("pause");
		}else if(strcmp(input,"8")==0){
			destory(&head);
			system("pause");
		}else if(strcmp(input,"9")==0){
			printf("See you!\n");
			system("pause");
		}else{
			printf("������1-9�� \n");
			system("pause");
		}
	}
	return 0;
}

