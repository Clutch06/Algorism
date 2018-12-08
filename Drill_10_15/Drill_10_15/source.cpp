#include <stdio.h>

int Graph[100][100];
int BFSvisit[100];
int DFSvisit[100];
int queue[100];

void DFS(int v, int N);
void BFS(int v, int N);

int main()
{
	int N, M, Start;
	int x, y;

	scanf("%d%d%d", &N, &M, &Start);

	for (int i = 0; i < M; i++) {
		scanf("%d%d", &x, &y);
		Graph[x][y] = 1;
		Graph[y][x] = 1;
	}

	DFS(Start, N);
	printf("\n");
	BFS(Start, N);
	return 0;
}

void DFS(int v, int N)
{
	DFSvisit[v] = 1;
	printf("%d", v);

	for (int i = 1; i <= N; i++) {
		if (Graph[v][i] == 1 && DFSvisit[i] == 0) {
			DFS(i, N);
		}
	}

	return;
}

void BFS(int v, int N)
{
	int front = 0, rear = 0, pop, i;

	printf("%d", v);
	queue[0] = v;
	rear++;
	BFSvisit[v] = 1;

	while (front < rear) {
		pop = queue[front];
		front++;

		for (i = 1; i <= N; i++) {
			if (Graph[pop][i] == 1 && BFSvisit[i] == 0) {
				printf("%d", i);
				queue[rear] = i;
				rear++;
				BFSvisit[i] = 1;
			}
		}
	}

	return;
}