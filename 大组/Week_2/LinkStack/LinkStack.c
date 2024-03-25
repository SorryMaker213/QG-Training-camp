#include <stdio.h>
#include <stdlib.h>

#include "LinkStack.h"

void printmenu()
{
	system("cls");
	printf("        链    栈      \n");
	printf("*************************\n");
	printf("*     1.初始化栈        *\n");
	printf("*     2.入  栈          *\n");
	printf("*     3.出  栈          *\n");
	printf("*     4.输出栈顶元素    *\n");
	printf("*     5.清空栈          *\n");
	printf("*     6.遍  历          *\n");
	printf("*     7.摧毁栈          *\n");
	printf("*     8.退  出          *\n");
	printf("*************************\n");
}

void initLStack(LinkStack **s)
{
	*s = (LinkStack*)malloc(sizeof(LinkStack));
	(*s)->top = NULL;
	(*s)->count = 0;
	printf("初始化成功\n");
}

void pushLStack(LinkStack **s)
{
	LinkStackPtr news = (LinkStackPtr)malloc(sizeof(StackNode));
	printf("请输入结点数据：");
	gets(news->data); 
	news->next = (*s)->top;
	(*s)->top = news;
	(*s)->count++;
	printf("入栈成功！\n");
}

void popLStack(LinkStack **s)
{
	LinkStackPtr p;
	if(isEmptyLStack(*s))
		printf("链栈为空！\n");
	else
	{
		p = (*s)->top;
		(*s)->top = (*s)->top->next;
		free(p);
		(*s)->count--;
		printf("出栈成功！\n");
	}
}

void TraverseLStack(LinkStack *s)
{
	if(isEmptyLStack(s))
		printf("链栈为空!\n");
	else
	{
		LinkStackPtr p;
		p = s->top;
		printf("\n栈顶:\n");
		while(p)
		{
			printf("%s\n",p->data);
			p = p->next;
		}
		printf("\n共%d个结点\n\n",s->count);
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
		printf("链栈为空!\n");
	else
	{
		printf("栈顶元素为： %s\n",s->top->data);
	}
}

void clearLStack(LinkStack **s)
{
	if(isEmptyLStack(*s))
		printf("链栈已为空！\n");
	else{
		LinkStackPtr p;
		while((*s)->top)
		{
			p = (*s)->top;
			(*s)->top = p->next;
			(*s)->count--;
			free(p);
		}
		printf("清空成功！\n");
	} 
}

void destroyLStack(LinkStack **s)
{
	if(!isEmptyLStack(*s))
		clearLStack(s);
	LinkStack* p = *s;
	free(p);
	(*s) = NULL;
	printf("摧毁成功！\n");
}

int main()
{
	int index = 0; 
	char input[20];
	LinkStack* s = NULL;
	while(strcmp(input,"8")!=0)
	{
		printmenu();
		printf("请选择进行的操作:");
		gets(input);
		if(strcmp(input,"1")==0)
		{
			if(s == NULL){
				initLStack(&s);
			}else{
				printf("链栈已初始化，请勿重复操作！\n");
			}
			system("pause");
		}else if(strcmp(input,"2")==0){
			if(s == NULL){
				printf("链栈尚未初始化！\n");
			}else{
				pushLStack(&s);
			} 
			system("pause");
		}else if(strcmp(input,"3")==0){
			if(s == NULL){
				printf("链栈尚未初始化！\n");
			}else{
				popLStack(&s);
			} 
			system("pause");
		}else if(strcmp(input,"4")==0){
			if(s == NULL){
				printf("链栈尚未初始化！\n");
			}else{
				getTopLStack(s);
			} 
			system("pause");
		}else if(strcmp(input,"5")==0){
			if(s == NULL){
				printf("链栈尚未初始化！\n");
			}else{
				clearLStack(&s);
			} 
			system("pause");
		}else if(strcmp(input,"6")==0){
			if(s == NULL){
				printf("链栈尚未初始化！\n");
			}else{
				TraverseLStack(s);
			} 
			system("pause");
		}else if(strcmp(input,"7")==0){
			if(s == NULL){
				printf("链栈尚未初始化！\n");
			}else{
				destroyLStack(&s); 
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
