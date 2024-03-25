#include <stdio.h>
#include <stdlib.h>

#include "LinkStack.h"

void printmenu()
{
	system("cls");
	printf("        ��    ջ      \n");
	printf("*************************\n");
	printf("*     1.��ʼ��ջ        *\n");
	printf("*     2.��  ջ          *\n");
	printf("*     3.��  ջ          *\n");
	printf("*     4.���ջ��Ԫ��    *\n");
	printf("*     5.���ջ          *\n");
	printf("*     6.��  ��          *\n");
	printf("*     7.�ݻ�ջ          *\n");
	printf("*     8.��  ��          *\n");
	printf("*************************\n");
}

void initLStack(LinkStack **s)
{
	*s = (LinkStack*)malloc(sizeof(LinkStack));
	(*s)->top = NULL;
	(*s)->count = 0;
	printf("��ʼ���ɹ�\n");
}

void pushLStack(LinkStack **s)
{
	LinkStackPtr news = (LinkStackPtr)malloc(sizeof(StackNode));
	printf("�����������ݣ�");
	gets(news->data); 
	news->next = (*s)->top;
	(*s)->top = news;
	(*s)->count++;
	printf("��ջ�ɹ���\n");
}

void popLStack(LinkStack **s)
{
	LinkStackPtr p;
	if(isEmptyLStack(*s))
		printf("��ջΪ�գ�\n");
	else
	{
		p = (*s)->top;
		(*s)->top = (*s)->top->next;
		free(p);
		(*s)->count--;
		printf("��ջ�ɹ���\n");
	}
}

void TraverseLStack(LinkStack *s)
{
	if(isEmptyLStack(s))
		printf("��ջΪ��!\n");
	else
	{
		LinkStackPtr p;
		p = s->top;
		printf("\nջ��:\n");
		while(p)
		{
			printf("%s\n",p->data);
			p = p->next;
		}
		printf("\n��%d�����\n\n",s->count);
	}
} 

int isEmptyLStack(LinkStack *s)
{
		if(s->top == NULL)
			return 1;
		else
			return 0;
}

void getTopLStack(LinkStack *s)
{
	if(isEmptyLStack(s))
		printf("��ջΪ��!\n");
	else
	{
		printf("ջ��Ԫ��Ϊ�� %s\n",s->top->data);
	}
}

void clearLStack(LinkStack **s)
{
	if(isEmptyLStack(*s))
		printf("��ջ��Ϊ�գ�\n");
	else{
		LinkStackPtr p;
		while((*s)->top)
		{
			p = (*s)->top;
			(*s)->top = p->next;
			(*s)->count--;
			free(p);
		}
		printf("��ճɹ���\n");
	} 
}

void destroyLStack(LinkStack **s)
{
	if(!isEmptyLStack(*s))
		clearLStack(s);
	LinkStack* p = *s;
	free(p);
	(*s) = NULL;
	printf("�ݻٳɹ���\n");
}

int main()
{
	int index = 0; 
	char input[20];
	LinkStack* s = NULL;
	while(strcmp(input,"8")!=0)
	{
		printmenu();
		printf("��ѡ����еĲ���:");
		gets(input);
		if(strcmp(input,"1")==0)
		{
			if(s == NULL){
				initLStack(&s);
			}else{
				printf("��ջ�ѳ�ʼ���������ظ�������\n");
			}
			system("pause");
		}else if(strcmp(input,"2")==0){
			if(s == NULL){
				printf("��ջ��δ��ʼ����\n");
			}else{
				pushLStack(&s);
			} 
			system("pause");
		}else if(strcmp(input,"3")==0){
			if(s == NULL){
				printf("��ջ��δ��ʼ����\n");
			}else{
				popLStack(&s);
			} 
			system("pause");
		}else if(strcmp(input,"4")==0){
			if(s == NULL){
				printf("��ջ��δ��ʼ����\n");
			}else{
				getTopLStack(s);
			} 
			system("pause");
		}else if(strcmp(input,"5")==0){
			if(s == NULL){
				printf("��ջ��δ��ʼ����\n");
			}else{
				clearLStack(&s);
			} 
			system("pause");
		}else if(strcmp(input,"6")==0){
			if(s == NULL){
				printf("��ջ��δ��ʼ����\n");
			}else{
				TraverseLStack(s);
			} 
			system("pause");
		}else if(strcmp(input,"7")==0){
			if(s == NULL){
				printf("��ջ��δ��ʼ����\n");
			}else{
				destroyLStack(&s); 
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
