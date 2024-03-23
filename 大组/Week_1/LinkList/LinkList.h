typedef struct Node
{
	char data[20];
	struct Node* next;
}Node;

void printmenu(); 
void Listcreat(Node** head);
void insert(Node** head);
void printlist(Node* head);
void printmid(Node* head);
void exchange(Node** head);
void reverselist(Node** head);
void deletenode(Node** head);
void destory(Node** head);
