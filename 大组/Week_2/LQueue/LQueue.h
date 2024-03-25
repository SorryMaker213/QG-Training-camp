typedef struct QNode
{
    char data[20];                   //数据域指针
    struct node *next;            //指向当前结点的下一结点
} QNode;

typedef struct LQueue
{
    QNode *front;                   //队头
    QNode *rear;                    //队尾
    int length;            //队列长度
} LQueue;

void InitLQueue(LQueue **q);
void EnLQueue(LQueue **q);
void DeLQueue(LQueue **q);
void GetHeadLQueue(LQueue *q);
void TraverseLQueue(LQueue *q);
void ClearLQueue(LQueue **q); 
int IsEmptyLQueue(LQueue *q);
void DestoryLQueue(LQueue **q);

