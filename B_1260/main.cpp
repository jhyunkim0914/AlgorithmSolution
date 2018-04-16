#include <iostream>
#include <queue>

using namespace std;

int v, e, start;

int adj[1001][1001];
int visited[1001];

void dfs(int start) {
	cout << start << ' ';
	
	for (int i = 1; i <= v; i++) {
		if (adj[start][i] == 1 && visited[i] != 1) {
			visited[start] = 1;
			dfs(i);
		}
	}
}

void bfs(int start) {
	queue<int> router;

	router.push(start);
	visited[start] = 2;

	while (!router.empty()) {
		int point = router.front();
		cout << point << ' ';
		router.pop();
		for (int i = 1; i <= v; i++) {
			if (adj[start][i] == 1 && visited[i] != 2) {
				visited[i] = 2;
				router.push(i);
			}
		}
	}
}

int main()
{
	cin >> v >> e >> start;

	for (int i = 0; i < 1001; i++) {
		visited[i] = 0;
		for (int j = 0; j < 1001; j++) {
			adj[i][j] = 0;
		}
	}

	for (int i = 1; i <= e; i++)
	{
		int n, m;
		cin >> n >> m;
		adj[n][m] = 1;
		adj[m][n] = 1;
	}

	dfs(start);
	cout << endl;
	bfs(start);
	cout << endl;

	return 0;
}