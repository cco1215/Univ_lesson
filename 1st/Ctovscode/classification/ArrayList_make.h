Element data[MAX_SIZE]; //배열
int size = 0; //배열의 수

void error(char str[]) {
    printf("%s\n", str);
    exit(1);
}

void init_list() { 
    size = 0;
}
int is_empty() {
    return size == 0;
}
int is_full() {
    return size == MAX_SIZE;
}

void insert(int pos, Element e) {
    if (is_full()) {
        error("오버플러우!!!");
    }
    if (pos < 0 || pos > size) { //잘못된 위치에 삽입
        error("인밸리드 포지션 오류!!!");
    }
    for (int i = size - 1; i >= pos; i--) { //맨 뒤에서 한칸씩 이동
        data[i + 1] = data[i];
    }
    data[pos] = e;
    size++;
}

Element delete(int pos) {
    if (is_empty()) {
        error("언더플로우!!");
    }
    if (pos < 0 || pos >= size) { //잘못된 위치에 삭제
        error("인밸리드 포지션 오류!!!");
    }
    Element e = data[pos];
    for (int i = pos + 1; i < size - 1; i++) { //pos + 1번부터 한칸씩 앞으로 이동
        data[i-1] = data[i];
    }
    size --;
    return e;
}
Element get_entry(int pos) {
    if (is_empty()) {
        error("언더플로우!!");
    }
if (pos < 0 || pos >= size) { //잘못된 위치
        error("인밸리드 포지션 오류!!!");
    }
    return data[pos];
}