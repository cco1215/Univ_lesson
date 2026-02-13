Element data[MAX_SIZE]; //배열
int size = 0;  //배열의 수
void error(char str[])
{
    printf("%s\n", str);
    exit(1);
}

void init_list() { size = 0; }
int is_empty() { return size == 0; }
int is_full() { return size == MAX_SIZE; }

void insert(int pos, Element e)
{
    if (is_full())
        error("Overflow Error!");

    if (pos < 0 || pos > size) //잘못된 위치에 삽입
        error("Invalid Position Error!");

    for (int i = size - 1; i >= pos; i--) //맨 뒤에서 한칸씩 이동
        data[i + 1] = data[i];
    data[pos] = e;
    size += 1;
}

Element delete(int pos)
{
    if (is_empty())
        error("Underflow Error!");

    if (pos < 0 || pos >= size) //잘못된 위치에 
        error("Invalid Position Error!");

    Element e = data[pos];
    for (int i = pos + 1; i < size; i++) //pos + 1번부터 한칸씩 앞으로 이동
        data[i - 1] = data[i];
    size -= 1;
    return e;
}

Element get_entry(int pos)
{
    if (is_empty())
        error("Underflow Error!"); 
    if (pos < 0 || pos >= size)
        error("Invalid Position Error!"); //잘못된 위치
    return data[pos];
}

void append(Element e)
{
    insert(size, e);
}
Element pop()
{
    return delete(size - 1);
}
void replace(int pos, Element e)
{
    if (pos < 0 || pos >= size)
        error("Invalid Position Error!");
    data[pos] = e;
}
int find(Element e)
{
    for (int i = 0; i < size; i++)
        if (data[i] == e)
            return i;
    return -1;
}




