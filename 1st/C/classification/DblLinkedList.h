typedef struct DNode {
    Element data; // 데이터
    struct DNode* prev; // 선행 노드
    struct DNode* next;  // 후속 노드
} DNode;
DNode org;
DNode* alloc_dnode(Element e)
{
    DNode* p = (DNode*)malloc(sizeof(DNode));
    p->data = e; //초기화
    p->prev = NULL; //초기화
    p->next = NULL; //초기화
    return p;
}
Element free_dnode(DNode* p) //p를 e에 복사해 두고 p를 해제한 뒤에 e를 반환 (저장)
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
int is_empty() { 
    return org.next == NULL; 
}
int is_full() {
     return 0; 
}
void init_list() { 
    org.next = NULL; 
}
DNode* get_node(int pos) //p는 -1 위치 (배열은 0부터 시작)에서 시작해 pos + 1번 링크를 타고 이동
{
    DNode* p = &org;
    for (int i = 0; i <= pos; i++, p = p->next)
        if (p == NULL)
            return NULL;
    return p;
}
Element get_entry(int pos)
{
    DNode* p = get_node(pos);
    if (pos < 0 || p == NULL)
        error("Invalid Position Error!");
    return p->data;
}
void insert(int pos, Element e)
{
    DNode* before = get_node(pos - 1);
    if (before == NULL)
        error("Invalid Position Error!");
    DNode* p = alloc_dnode(e);
    p->next = before->next;
    p->prev = before;
    before->next = p;
    if (p->next != NULL)
        p->next->prev = p;
}
Element delete(int pos)
{
    DNode* p = get_node(pos);
    if (pos < 0 || p == NULL)
        error("Invalid Position Error!");
    p->prev->next = p->next;
    if (p->next != NULL)
        p->next->prev = p->prev;
    return free_dnode(p);
}
void destroy_list() { 
    while (is_empty() == 0) delete(0); 
}
int size()
{
    int count = 0;
    for (DNode* p = org.next; p != NULL; p = p->next)
        count++;
    return count;
}