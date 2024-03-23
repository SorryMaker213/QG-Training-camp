#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "DuLinkList.h"

void printmenu()
{
	system("cls");
	printf("    双    向    链    表\n");
	printf("*************************\n");
	printf("*     1.初始化链表      *\n");
	printf("*     2.插入新结点      *\n");
	printf("*     3.遍历输出链表    *\n");
	printf("*     4.中间结点数据    *\n");
	printf("*     5.删除结点        *\n");
	printf("*     6.摧毁链表        *\n");
	printf("*     7.退出系统        *\n");
	printf("*************************\n");
}

void Listcreat(Node** head)
{
	int num,i;
	printf("请输入创建结点个数: ");
	if(scanf("%d",&num)!=1)
	{
		printf("输入错误！\n");
		while(getchar()!='\n')		//清除缓冲区 
			continue;
		system("pause");
		return;
	} 
	*head=(Node*)malloc(sizeof(Node));
	Node* lastnode=*head;
	getchar();
	for(i=0;i<num;i++)
	{
		Node* newnode=(Node*)malloc(sizeof(Node));
		printf("请输入第%d个结点的数据：",i+1); 
		gets(newnode->data);
		newnode->next=NULL;
		newnode->prev=lastnode;
		lastnode->next=newnode;
		lastnode=lastnode->next;
	}
	printf("初始化成功！\n");
	system("pause");
	return ;
}

void insert(Node** head) 
{
	int i,pos,select,flag=1;
	if(*head==NULL)
	{
		printf("链表未初始化，请先初始化链表！\n");
		return;
	}
	printf("链表数据：");
	printlist(*head);
	printf("请输入要插入的位置：");
	if(scanf("%d",&pos)!=1)
	{
		printf("输入错误！\n");
		while(getchar()!='\n')
			continue;
		return; 
	}
	Node *ptr=(*head)->next;
	for(i=1;i<pos;i++)
	{
		if(ptr==NULL)
		{
			printf("这链表有这么长吗？？？\n");
			getchar();
			return;
		}
		ptr=ptr->next;
	}
	printf("请输入要插入的结点数据：");
	Node* newnode=(Node*)malloc(sizeof(Node));
	getchar();
	gets(newnode->data);
	printf("请选择插入位置（前1/后2）：");
	while(flag)
	{
		if(scanf("%d",&select)!=1)
		{
			printf("输入错误！\n"); 
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
				newnode->prev=ptr->prev;
				ptr->prev->next=newnode;
				ptr->prev=newnode;
				printf("插入成功！\n"); 
				getchar();
				break;
			}
			case 2:
			{ 
				flag=0;
				newnode->prev=ptr;	
				if(ptr->next!=NULL)
				{
					newnode->next=ptr->next;
					ptr->next->prev=newnode;
				}else{
					newnode->next=NULL;	
				}
				ptr->next=newnode;
				printf("插入成功！\n"); 
				getchar();
				break;
			} 
			default:
				printf("输入错误\n");
				getchar();
				return;
		}
	}
	
}

void printlist(Node* head)
{
	if(head==NULL)
	{
		printf("链表未初始化，请先初始化链表！\n");
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
		printf("链表未初始化，请先初始化链表！\n");
		return;
	}
	Node *ptr=head->next;
	while(ptr)
	{
		ptr=ptr->next;
		num++;
	}
	ptr=head->next;
	printf("中间结点数据为：");
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

void deletenode(Node** head)
{
	int i,pos;
	if(*head==NULL)
	{
		printf("链表未初始化，请先初始化链表！\n");
		return;
	}
	Node *ptr=(*head)->next;
	printf("链表数据：");
	printlist(*head);
	printf("请输入要删除结点的位置：");
	if(scanf("%d",&pos)!=1)
	{
		printf("输入错误！\n"); 
		while(getchar()!='\n')
			continue;
		return;
	}
	for(i=1;i<pos;i++)
	{
		if(ptr==NULL)
		{
			printf("要删哪个？？？\n");
			getchar(); 
			return; 
		}
		ptr=ptr->next;
	}
	if(ptr->next!=NULL)
	{
		ptr->next->prev=ptr->prev;
		ptr->prev->next=ptr->next;
	}else{
		ptr->prev->next=NULL;
	}
	ptr->next=NULL;
	ptr->prev=NULL;
	free(ptr);
	printf("删除完毕！\n");
	getchar();
} 

void destory(Node** head)
{
	if(*head==NULL)
	{
		printf("链表未初始化，请先初始化链表！\n");
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
	printf("链表摧毁完毕!\n"); 
}

int main()
{
	char input[20];
	Node* head=NULL;
	while(strcmp(input,"7")!=0)
	{
		printmenu();
		printf("请选择进行的操作:");
		gets(input);
		if(strcmp(input,"1")==0)
		{
			if(head==NULL){
				Listcreat(&head);
			}else{
				printf("链表已初始化，请勿重复操作！\n");
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
			deletenode(&head);
			system("pause");
		}else if(strcmp(input,"6")==0){
			destory(&head);
			system("pause");
		}else if(strcmp(input,"7")==0){
			printf("See you!\n");
			system("pause");
		}else{
			printf("请输入1-7！ \n");
			system("pause");
		}
	}
	return 0;
}
