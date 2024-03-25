typedef struct Stack
{
	int data[50];
	int top;
}Stack;

Stack* InitStack();
void StackPop(Stack* s,int *x); 
void StackPush(Stack* s,int *x);
void Compute_1(Stack* NumStack,Stack* SymStack,int Sym);
void Compute_2(Stack* NumStack,Stack* SymStack);
void Compute_F(Stack *NumStack,int Sym);
int itsPri(int Sym);
