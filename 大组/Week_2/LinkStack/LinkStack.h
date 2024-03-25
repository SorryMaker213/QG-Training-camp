typedef  struct StackNode
{
	char data[20];
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

void printmenu();
void initLStack(LinkStack **s);
void pushLStack(LinkStack **s); 
void popLStack(LinkStack **s); 
void TraverseLStack(LinkStack *s);
int isEmptyLStack(LinkStack *s);
void getTopLStack(LinkStack *s);
void clearLStack(LinkStack **s);
void destroyLStack(LinkStack **s)£» 
