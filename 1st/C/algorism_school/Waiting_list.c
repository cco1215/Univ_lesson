#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Waiting {
    int id;
    int nperson;
    char info[32];
};
typedef struct Waiting Element;
#include "DblLinkedList.h"

void reserve(int nperson, const char info[]) {
    static int id = 0;
    Element e;
    e.id = ++id;
    e.nperson = nperson;
    strcpy(e.info, info);
    insert(size(), e);
    printf("번호=%d, 인원=%d 명 %s\n", e.id, e.nperson, e.info);
}
void find(int wid) {
    int nTeam = 0, nPeople = 0;
    for (int pos = 0; pos < size(); pos++) {
        Element e = get_entry(pos);
        if (e.id == wid) {
            printf("번호=%d, 대기팀 =%d팀 %d명\n", wid, nTeam, nPeople);
            return;
        }
        nTeam += 1;
        nPeople += e.nperson;
    }
}

void cancel(int wid) {
    for (int pos = 0; pos < size(); pos++) {
        Element e = get_entry(pos);
        if (e.id == wid) {
            delete(pos);
            printf("%d번이 취소 되었습니다.\n", wid);
            return;
        }
    }
}
void delay(int wid) {
    for (int pos = 0; pos < size(); pos++) {
        Element e = get_entry(pos);
        if (e.id == wid) {
            delete(pos);
            insert(pos + 1, e);
            printf("%d번이 한 칸 연기했습니다.\n", wid);
            return;
        }
    }
}
void print() {
    printf("대기선수 명록\n");
    for (int pos = 0; pos < size(); pos++) {
        Element e = get_entry(pos);
        printf("번호=%d, 인원=%d 명 %s\n", e.id, e.nperson, e.info);
    }
    printf("\n");
}
void service() {
    Element e = delete(0);
    printf("%d번 손님 입장 (5d명, %s)\n", e.id, e.nperson, e.info);
}
void main() {
    init_list();
    print();
    reserve(2, "010-1234-1234");
    reserve(2, "010-1234-1234");
    reserve(5, "010-1234-1234");
    reserve(1, "010-1234-1234");
    print();

    service();
    print();

    reserve(3, "010-1234-1234");
    reserve(4, "010-1234-1234");
    print();

    find(4);
    delay(3);
    delay(3);
    print();

    cancel(5);
    print();

    destroy_list();
}