#include <stdio.h>

typedef struct {
	int borad[3][3];
	int turn;
} state;

void init(state* s) {
	int i, j;
	for (j = 0; j < 3; j++) {
		for (i = 0; i < 3; i++) {
			s->borad[j][i] = -1;
		}
	}
	s->turn = 0;
}

void display(const state* s) {
	int i, j;
	for (j = 0; j < 3; j++) {
		for (i = 0; i < 3; i++) {
			switch (s->borad[j][i]) {
			case -1: printf(" %d ", j * 3 + i + 1); break;
			case  0: printf(" O "); break;
			case  1: printf(" X "); break;
			}
			if (i < 2)
				printf("|");
			else
				printf("\n");
		}
		if (j < 2)
			printf("---+---+---\n");
		else
			printf("\n");
	} 
}

int move(state* s, int i, int j) {
	if (s->borad[j][i] != -1)
		return 0;
	
	s->borad[j][i] = s->turn++ % 2;

	return 1;
}

void human(state* s) {
	char c;
	do {
		printf("%c: ", "OX"[s->turn % 2]);
		c = getchar();
		while(getchar() != '\n');
		printf("\n");
	} while(c < '1' || c > '9' || !move(s, (c - '1') % 3, (c - '1') / 3));
}

#define CHECK(j1, i1, j2, i2, j3, i3) \
	if (s->borad[j1][i1] != -1 && s->borad[j1][i1] == s->borad[j2][i2] && s->borad[j1][i1] == s->borad[j3][i3]) \
		return s->borad[j1][i1] == 0 ? 1 : -1;

int evaluate(const state* s) {
	int i;
	for (i = 0; i < 3; i++) {
		CHECK(i, 0, i, 1, i, 2);
		CHECK(0, i, 1, i, 2, i);
	}

	CHECK(0, 0, 1, 1, 2, 2);        // diagonal
	CHECK(0, 2, 1, 1, 2, 0); 

	return 0;
}

int main(int argc, char **argv) {
	state s;
	init(&s);
	display(&s);
	while(s.turn < 9) {
		human(&s);
		display(&s);
		switch (evaluate(&s)) {
			case  1: printf("O win\n"); return 0;
			case -1: printf("X win\n"); return 0;
		}
	}
}
