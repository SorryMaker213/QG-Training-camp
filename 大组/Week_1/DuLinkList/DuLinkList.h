typedef struct Node
{
	char data[20];
	struct Node* prev;
	struct Node* next;
}Node; 

void printmenu();
void Listcreat(Node** head);
void printlist(Node* head);
void deletenode(Node** head);
void printmid(Node* head);
void insert(Node** head);
void destory(Node** head);
