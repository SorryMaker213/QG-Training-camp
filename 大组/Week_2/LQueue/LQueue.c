#include <stdio.h>
#include <stdlib.h>

#include "LQueue.h"

void printmenu()
{
	system("cls");
	printf("       队    列      \n");
	printf("*************************\n");
	printf("*     1.初始化队列      *\n");
	printf("*     2.入  队          *\n");
	printf("*     3.出  队          *\n");	
	printf("*     4.输出队头元素    *\n");
	printf("*     5.遍历队列        *\n");
	printf("*     6.清空队列        *\n");
	printf("*     7.销毁队列        *\n");
	printf("*     8.退出            *\n");
	printf("*************************\n");
}

void InitLQueue(LQueue **q)
{
	*q = (LQueue*)malloc(sizeof(LQueue));
	(*q)->front = NULL;
	(*q)->rear = NULL;
	(*q)->length = 0;
	printf("初始化成功！\n"); 
}

int IsEmptyLQueue(LQueue *q)
{
	if(q->length == 0)
		return 1;
	else
		return 0;
}

void EnLQueue(LQueue **q)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	printf("请输入结点数据：");
	gets(newnode->data);
	if(IsEmptyLQueue(*q))
	{
		(*q)->front = newnode;
		(*q)->rear = newnode;
		(*q)->rear->next = NULL;
	}else{
		(*q)->rear->next = newnode;
		(*q)->rear = newnode;
		(*q)->rear->next = NULL;
	}
	(*q)->length++;
	printf("入队成功！\n"); 
}

void DeLQueue(LQueue **q)
{
	if(IsEmptyLQueue(*q))
		printf("队列为空！\n");
	else{
		QNode* p = (*q)->front;
		if((*q)->front == (*q)->rear)		//只有一个结点 
		{	
			free(p); 
			(*q)->front = (*q)->rear =NULL;
		}else{
			(*q)->front =p->next;
			free(p);
		}
		(*q)->length--;
		printf("出队成功！\n"); 
	}
}

void GetHeadLQueue(LQueue *q)
{
	if(IsEmptyLQueue(q))
	{
		printf("队列为空！\n");
	}else{
		printf("队头元素为： %s\n",q->front->data);
	}
	
}

void TraverseLQueue(LQueue *q)
{
	if(IsEmptyLQueue(q))
		printf("队列为空！\n");
	else{
		QNode *p = q->front;
		printf("队头："); 
		while(p)
		{
			printf("%s  ",p->data);
			p = p->next;
		}
		printf("\n共%d个结点\n",q->length);
	} 
}

void ClearLQueue(LQueue **q)
{
	if(IsEmptyLQueue(*q))
		printf("队列已为空！\n");
	else{
		QNode* p = (*q)->front;
		while(p !=NULL)
		{
			QNode *next = p->next;
			free(p);
			(*q)->length--;
			p = next;
		}
		printf("清空成功！\n");
	}
}

void DestoryLQueue(LQueue **q)
{
	if(!IsEmptyLQueue(*q))
		ClearLQueue(q);
	LQueue* p = *q;
	free(p);
	*q = NULL;
	printf("摧毁成功！\n");
}

int main()
{
	int index = 0; 
	char input[20];
	LQueue* q = NULL;
	while(strcmp(input,"8")!=0)
	{
		printmenu();
		printf("请选择进行的操作:");
		gets(input);
		if(strcmp(input,"1")==0)
		{
			if(q == NULL){
				InitLQueue(&q);
			}else{
				printf("队列已初始化，请勿重复操作！\n");
			}
			system("pause");
		}else if(strcmp(input,"2")==0){
			if(q == NULL){
				printf("队列尚未初始化！\n");
			}else{
				EnLQueue(&q);
			} 
			system("pause");
		}else if(strcmp(input,"3")==0){
			if(q == NULL){
				printf("队列尚未初始化！\n");
			}else{
				DeLQueue(&q);
			} 
			system("pause");
		}else if(strcmp(input,"4")==0){
			if(q == NULL){
				printf("队列尚未初始化！\n");
			}else{
				GetHeadLQueue(q);
			} 
			system("pause");
		}else if(strcmp(input,"5")==0){
			if(q == NULL){
				printf("队列尚未初始化！\n");
			}else{
				TraverseLQueue(q);
			} 
			system("pause");
		}else if(strcmp(input,"6")==0){
			if(q == NULL){
				printf("队列尚未初始化！\n");
			}else{
				ClearLQueue(&q);
			} 
			system("pause");
		}else if(strcmp(input,"7")==0){
			if(q == NULL){
				printf("队列尚未初始化！\n");
			}else{
				 DestoryLQueue(&q);
			} 
			system("pause");
		}else if(strcmp(input,"8")==0){
			printf("See you!\n");
			system("pause");
		}else{
			printf("请输入1-8！ \n");
			system("pause");
		}
	}
	return 0;
}
