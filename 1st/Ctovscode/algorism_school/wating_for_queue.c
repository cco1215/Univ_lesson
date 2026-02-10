/*#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
struct Waiting {
	int id;
	int nperson;
	char info[32];
};

typedef struct Waiting Element;
#include "CircularQueue.h"

void main() {
	Element waiting[4] = {
		{12, 2, "010-1234-1234"},
		{13, 4, "010-1123-1234"},
		{14, 5, "010-1674-1234"},
		{15, 9, "010-1984-1234"}
	};

	init_queue();


	for (int i = 0; i < 4; i++) {
		printf("웨이팅 신청을 완료했습니다. 대기번호 %d 번, 인원: %d명 \n", waiting[i].id, waiting[i].nperson);
		enqueue(waiting[i]);
	}
	while (!is_empty()) {
		Element w = dequeue();
		printf("%d 번 손님! 들어오세dy. (%d명, %s) \n", w.id, w.nperson, w.info);
	}
}
*/