#include <stdio.h>
#include <stdlib.h>

#include "SpCalculator.h"

//仅支持整数运算，一次性使用 
Stack* InitStack()		//初始化栈 
{
	Stack* news;
	news = (Stack*)malloc(sizeof(Stack));
	news->top = -1;
	return news;
}

void StackPush(Stack* s,int *x)		//入栈 
{
	s->data[ ++s->top ] = *x;
}

void StackPop(Stack* s,int *x)		//出栈 
{
	*x = s->data[s->top--];
}

int itsPri(int Sym)		//设置运算符优先级 
{
	switch(Sym)
	{
		case '(':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	 } 
}

void Compute_1(Stack* NumStack,Stack* SymStack,int Sym)		//无括号运算操作 
{
	int preSym;
	if(SymStack->top == -1 || Sym == '(')		//符号栈为空或者为左括号 
	{
		StackPush(SymStack , &Sym);
		return; 
	}
	preSym = SymStack->data[SymStack->top];
	if(itsPri(Sym) > itsPri(preSym))
	{
		StackPush(SymStack , &Sym);
		return;
	}
	while(itsPri(Sym) <= itsPri(preSym))
	{
		StackPop(SymStack,&preSym);
		Compute_F(NumStack,preSym);
		if(SymStack->top == -1)
			break;
		preSym = SymStack->data[SymStack->top];
	}
	StackPush(SymStack , &Sym);
} 

void Compute_2(Stack* NumStack,Stack* SymStack)		//遇到右括号的运算操作 
{
	int preSym;
	preSym = SymStack->data[SymStack->top];
	while(preSym != '(')
	{
		StackPop(SymStack,&preSym);
		Compute_F(NumStack,preSym);
		preSym = SymStack->data[SymStack->top];
	} 
	StackPop(SymStack,&preSym);
}

void Compute_F(Stack *NumStack,int Sym)		//计算 
{
	int n1,n2,res;
	StackPop(NumStack,&n2);
	StackPop(NumStack,&n1);
	switch(Sym)
	{
		case '+':
			res = n1 + n2;
			break;
		case '-':
			res = n1 - n2;
			break;
		case '*':
			res = n1 * n2;
			break;
		case '/':
			res = n1 / n2;
			break;
		default:
			break;
	}
	StackPush(NumStack,&res);
}

int main()
{
	char exp[30];
	int i ,value,flag = 0 ,preSym,index = 0;
	while(1)
	{
		value = 0;
		index = 0;
		printf("请输入正确的表达式：\n");
		gets(exp);
		for(i = 0;exp[i]!= '\0';i++)
		{
			if(!((exp[i]>='0'&&exp[i]<='9')||exp[i]=='('||exp[i]==')'||exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'))
			{
				printf("输入有错误！\n");
				system("pause");
				index = 1;
				break;
			}
		}
		if(index)
			continue; 
		Stack* NumStack = InitStack();
		Stack* SymStack = InitStack();
		for(i = 0;exp[i] != '\0';i++)
		{
			if(exp[i] >= '0' && exp[i] <= '9')
			{
				value = value*10 + (exp[i] - '0');
				flag = 1;
			}else{
				if(flag)
				{
					StackPush(NumStack,&value);
					value = 0;
					flag = 0;
				}
				if(exp[i] == ')')
					Compute_2(NumStack,SymStack);
				else
					Compute_1(NumStack,SymStack,exp[i]);
			}
	
		}
		if(flag)		//最后一个数字 
		{
			StackPush(NumStack,&value);
		}
		while(SymStack->top != -1)		//至少有一个符号 
		{
			StackPop(SymStack,&preSym);
			Compute_F(NumStack,preSym); 
		}
		StackPop(NumStack,&value);
		printf("结果为：%d\n",value);
		system("pause");
	}
}
