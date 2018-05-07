#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int T, N, number;
int arr[1001];
int visited[1001];

int findCycle(int start)
{
	int size = 0;
	visited[start] = 1;
	if (visited[arr[start]] == 0)
	{
		findCycle(arr[start]);
		size++;
	}
	return size;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		int result = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> number;
			arr[i + 1] = number;
		}
		for (int i = 0; i < N; i++)
		{
			visited[i + 1] = 0;
		}

		int start = 1;

		for (int i = 1; i <= N; i++)
		{
			int size;
			if (visited[i] == 0)
			{
				size = findCycle(i);
				result++;
			}
		}
		cout << result << endl;
	}
	
	return 0;
}