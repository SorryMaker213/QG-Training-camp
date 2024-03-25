#include <stdio.h>
#include <stdlib.h>

#include "LQueue.h"

void printmenu()
{
	system("cls");
	printf("       ��    ��      \n");
	printf("*************************\n");
	printf("*     1.��ʼ������      *\n");
	printf("*     2.��  ��          *\n");
	printf("*     3.��  ��          *\n");	
	printf("*     4.�����ͷԪ��    *\n");
	printf("*     5.��������        *\n");
	printf("*     6.��ն���        *\n");
	printf("*     7.���ٶ���        *\n");
	printf("*     8.�˳�            *\n");
	printf("*************************\n");
}

void InitLQueue(LQueue **q)
{
	*q = (LQueue*)malloc(sizeof(LQueue));
	(*q)->front = NULL;
	(*q)->rear = NULL;
	(*q)->length = 0;
	printf("��ʼ���ɹ���\n"); 
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
	printf("�����������ݣ�");
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
	printf("��ӳɹ���\n"); 
}

void DeLQueue(LQueue **q)
{
	if(IsEmptyLQueue(*q))
		printf("����Ϊ�գ�\n");
	else{
		QNode* p = (*q)->front;
		if((*q)->front == (*q)->rear)		//ֻ��һ����� 
		{	
			free(p); 
			(*q)->front = (*q)->rear =NULL;
		}else{
			(*q)->front =p->next;
			free(p);
		}
		(*q)->length--;
		printf("���ӳɹ���\n"); 
	}
}

void GetHeadLQueue(LQueue *q)
{
	if(IsEmptyLQueue(q))
	{
		printf("����Ϊ�գ�\n");
	}else{
		printf("��ͷԪ��Ϊ�� %s\n",q->front->data);
	}
	
}

void TraverseLQueue(LQueue *q)
{
	if(IsEmptyLQueue(q))
		printf("����Ϊ�գ�\n");
	else{
		QNode *p = q->front;
		printf("��ͷ��"); 
		while(p)
		{
			printf("%s  ",p->data);
			p = p->next;
		}
		printf("\n��%d�����\n",q->length);
	} 
}

void ClearLQueue(LQueue **q)
{
	if(IsEmptyLQueue(*q))
		printf("������Ϊ�գ�\n");
	else{
		QNode* p = (*q)->front;
		while(p !=NULL)
		{
			QNode *next = p->next;
			free(p);
			(*q)->length--;
			p = next;
		}
		printf("��ճɹ���\n");
	}
}

void DestoryLQueue(LQueue **q)
{
	if(!IsEmptyLQueue(*q))
		ClearLQueue(q);
	LQueue* p = *q;
	free(p);
	*q = NULL;
	printf("�ݻٳɹ���\n");
}

int main()
{
	int index = 0; 
	char input[20];
	LQueue* q = NULL;
	while(strcmp(input,"8")!=0)
	{
		printmenu();
		printf("��ѡ����еĲ���:");
		gets(input);
		if(strcmp(input,"1")==0)
		{
			if(q == NULL){
				InitLQueue(&q);
			}else{
				printf("�����ѳ�ʼ���������ظ�������\n");
			}
			system("pause");
		}else if(strcmp(input,"2")==0){
			if(q == NULL){
				printf("������δ��ʼ����\n");
			}else{
				EnLQueue(&q);
			} 
			system("pause");
		}else if(strcmp(input,"3")==0){
			if(q == NULL){
				printf("������δ��ʼ����\n");
			}else{
				DeLQueue(&q);
			} 
			system("pause");
		}else if(strcmp(input,"4")==0){
			if(q == NULL){
				printf("������δ��ʼ����\n");
			}else{
				GetHeadLQueue(q);
			} 
			system("pause");
		}else if(strcmp(input,"5")==0){
			if(q == NULL){
				printf("������δ��ʼ����\n");
			}else{
				TraverseLQueue(q);
			} 
			system("pause");
		}else if(strcmp(input,"6")==0){
			if(q == NULL){
				printf("������δ��ʼ����\n");
			}else{
				ClearLQueue(&q);
			} 
			system("pause");
		}else if(strcmp(input,"7")==0){
			if(q == NULL){
				printf("������δ��ʼ����\n");
			}else{
				 DestoryLQueue(&q);
			} 
			system("pause");
		}else if(strcmp(input,"8")==0){
			printf("See you!\n");
			system("pause");
		}else{
			printf("������1-8�� \n");
			system("pause");
		}
	}
	return 0;
}
