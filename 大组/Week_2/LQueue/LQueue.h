typedef struct QNode
{
    char data[20];                   //������ָ��
    struct node *next;            //ָ��ǰ������һ���
} QNode;

typedef struct LQueue
{
    QNode *front;                   //��ͷ
    QNode *rear;                    //��β
    int length;            //���г���
} LQueue;

void InitLQueue(LQueue **q);
void EnLQueue(LQueue **q);
void DeLQueue(LQueue **q);
void GetHeadLQueue(LQueue *q);
void TraverseLQueue(LQueue *q);
void ClearLQueue(LQueue **q); 
int IsEmptyLQueue(LQueue *q);
void DestoryLQueue(LQueue **q);

