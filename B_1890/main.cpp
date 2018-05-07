#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

using namespace std;

int N, number;
int arr[101][101];
int visited[101][101];

int findRoute(int x, int y)
{
	int rightRoute = 0;
	int downRoute = 0;

	if (x == N && y == N) {
		return 1;
	}
	else {
		rightRoute = findRoute(x + arr[y][x], y);
		downRoute = findRoute(x, y + arr[y][x]);
		return rightRoute + downRoute;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	
	cin >> N;
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			visited[j][i] = 0;

		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> number;
			arr[j][i] = number;
		}
	}

	//for (int i = 1; i <= N; i++)
	//{
	//	for (int j = 1; j <= N; j++)
	//	{
	//		cout << arr[j][i] << ' ';
	//	}
	//	cout << endl;
	//}

	cout << findRoute(1, 1);


	return 0;
}