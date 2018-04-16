#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct NODE {
	vector<int>* co_node_vec;
}NODE;

// ��� �迭�� �湮�� ���� ���ڸ� �ִ´�. 
NODE** node_arr;
int* visited;
queue<int> networkQueue;
int answer = -1;	

int bfs() {
	networkQueue.push(1);
	while (networkQueue.size()) {
		// queue �� �ִ� ���Ҹ� �ϳ� ���� ���� visited �� 1�� ���� 
		int sub_node = networkQueue.front();
		networkQueue.pop();

		if (visited[sub_node] == 1) continue;
		visited[sub_node] = 1;
		answer++;

		// �� ������ ���踦 ���캸��, ����� ������ �߰��Ѵ�. 
		for (int i = 0; i < node_arr[sub_node]->co_node_vec->size(); i++) {
			networkQueue.push(node_arr[sub_node]->co_node_vec->at(i));
		}
	}

	return answer;
}

int main()
{
	freopen("input.txt", "r", stdin);
	
	int total_node_num, relation_num;
	cin >> total_node_num >> relation_num;

	// ��� ���� _ 0���� ������� �ʴ´�. 
	node_arr = (NODE**)malloc(sizeof(NODE*)*(total_node_num + 1));
	visited = (int*)malloc(sizeof(int)*(total_node_num + 1));
	for (int i = 1; i <= total_node_num; i++) {
		node_arr[i] = (NODE*)malloc(sizeof(NODE));
		node_arr[i]->co_node_vec = new vector<int>;
		visited[i] = 0;
	}

	// ���� ���� 
	int sub_node_1, sub_node_2;
	for (int i = 0; i < relation_num; i++) {
		cin >> sub_node_1 >> sub_node_2;
		node_arr[sub_node_1]->co_node_vec->push_back(sub_node_2);
		node_arr[sub_node_2]->co_node_vec->push_back(sub_node_1);
	}

	cout << bfs();

	return 0;
}