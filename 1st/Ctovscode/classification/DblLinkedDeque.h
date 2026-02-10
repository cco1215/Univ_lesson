typedef struct DNode {
    Element data; //데이터
    struct DNode* prev; //선행 노드
    struct DNode* next; //후속 노드
} DNode;
DNode* front = NULL; //프론트 초기화
DNode* rear = NULL; //마지막 초기화

DNode* alloc_dnode(Element e) //DblLinkedList와 동일
{
    DNode* p = (DNode*)malloc(sizeof(DNode));
    p->data = e;	
    p->prev = NULL;	
    p->next = NULL;	
    return p;
}
Element free_dnode(DNode* p)
{
    Element e = p->data;
    free(p);
    return e;
}
void error(char* str)
{
    printf("%s\n", str);
    exit(1);
};

int is_empty() { return front == NULL; }
int is_full() { return 0; }
void init_deque() { front = rear = NULL; }
int size()
{
	int count = 0;
	for (DNode* p = front; p != NULL; p = p->next) count++;
	return count;
}
void add_front(Element e)
{
    DNode* p = alloc_dnode(e);
    if (is_empty())
        front = rear = p; 
    else {
	p->next = front;
	front->prev = p;
	front = p;
    }
}
void add_rear(Element e)
{
    DNode* p = alloc_dnode(e);
    if (is_empty())
	front = rear = p;
    else {
	p->prev = rear;
	rear->next = p;
	rear = p;
    }
}

Element delete_front()
{
    if (is_empty())
	error("Underflow Error!");

    DNode* p = front;			
    if (front == rear)			
	front = rear = NULL;
    else {						
	front = front->next;
	front->prev = NULL;
    }
    return free_dnode(p);
}

Element delete_rear()
{
    if (is_empty())
	error("Underflow Error!");

    DNode* p = rear;       
    if (front == rear)     
        front = rear = NULL;
    else {                 
        rear = rear->prev;  
        rear->next = NULL;
    }
    return free_dnode(p);   

Element get_front()
{
    if (is_empty())
	error("Underflow Error!");
    return front->data;
}
Element get_rear()
{
    if (is_empty())
	error("Underflow Error!");
    return rear->data;
}

void destroy_deque()
{
    while (is_empty() == 0)
	delete_rear();
}
