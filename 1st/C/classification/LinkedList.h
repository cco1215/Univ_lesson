typedef struct Node {  
    Element data;      
    struct Node* link;  
} Node;
//노드는 연결 리스트의 기본 단위인 노드를 정의한 구조체
//데이터는 노드가 저장하는 데이터
//엘리멘트는 특정 자료형으로 정의된 데이터 타입
//링크는 다음 노드를 가르키는 전역 포인터

Node* head = NULL;
//헤더는 연결리스트의 시작을 가르키는 전역 포인터
//널로 초기화되어 빈 리스트

Node* alloc_node(Element e) //노드를 할당하고 데이터와 링크를 초기화한 뒤에 반환
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = e;       
    p->link = NULL;    
    return p;
}

Element free_node(Node* p) //p의 데이터를 edp 복사하고 p를 해제한 뒤에 e를 반환
{
    Element e = p->data;
    free(p);            
    return e;           
}

void error(char* str)
{
    printf("%s\n", str);
    exit(1);
}

int is_empty() { return head == NULL; }
int is_full() { return 0; }
void init_list() { head = NULL; }

Node* get_node(int pos)
{
    if (pos < 0) return NULL;
    Node* p = head;
    for (int i = 0; i < pos; i++, p = p->link)
        if (p == NULL) return NULL;
    return p;
}
Element get_entry(int pos)
{
    Node* p = get_node(pos);
    if (p == NULL)
        error("인밸리드 포지션 오류!!");
    return p->data;
}

void insert(int pos, Element e)
{
    Node* p = alloc_node(e);  //노드 생성 및 초기화
    if (pos == 0) {
        p->link = head;
        head = p;
    }
    else {
        Node* before = get_node(pos - 1);
        if (before == NULL)
            error("인밸리드 포지션 오류!!");
        p->link = before->link;
        before->link = p;
    }
}
Element delete(int pos)
{
    if (is_empty()) //공백 검사
        error("언더플로우!!");
    Node* p = get_node(pos);            
    if (p == NULL)
        error("인밸리드 포지션 오류!!");
    Node* before = get_node(pos - 1);   
    if (before == NULL)                 
        head = head->link;
    else
        before->link = p->link;
    return free_node(p);
}

void destroy_list()
{
    while (is_empty() == 0) delete(0);
}
int size()
{
    int count = 0;
    for (Node* p = head; p != NULL; p = p->link) count++;
    return count;
}

void append(Element e)
{
    insert(size(), e);
}
Element pop()
{
    return delete(size() - 1);
}
void replace(int pos, Element e)
{
    Node* p = get_node(pos);
    if (p == NULL)
        error("인밸리드 포지션 오류!!");
    p->data = e;
}
int find(Element e)
{
    int i = 0;
    for (Node* p = head; p != NULL; p = p->link, i++)
        if (p->data == e) return i;
    return -1;
}

