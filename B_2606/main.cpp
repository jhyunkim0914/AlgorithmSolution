#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct NODE {
	vector<int>* co_node_vec;
}NODE;

// 노드 배열과 방문한 곳의 숫자를 넣는다. 
NODE** node_arr;
int* visited;
queue<int> networkQueue;
int answer = -1;	

int bfs() {
	networkQueue.push(1);
	while (networkQueue.size()) {
		// queue 에 있는 원소를 하나 빼고 나서 visited 를 1로 변경 
		int sub_node = networkQueue.front();
		networkQueue.pop();

		if (visited[sub_node] == 1) continue;
		visited[sub_node] = 1;
		answer++;

		// 뺀 노드와의 관계를 살펴보고, 연결된 노드들을 추가한다. 
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

	// 노드 생성 _ 0번은 사용하지 않는다. 
	node_arr = (NODE**)malloc(sizeof(NODE*)*(total_node_num + 1));
	visited = (int*)malloc(sizeof(int)*(total_node_num + 1));
	for (int i = 1; i <= total_node_num; i++) {
		node_arr[i] = (NODE*)malloc(sizeof(NODE));
		node_arr[i]->co_node_vec = new vector<int>;
		visited[i] = 0;
	}

	// 관계 형성 
	int sub_node_1, sub_node_2;
	for (int i = 0; i < relation_num; i++) {
		cin >> sub_node_1 >> sub_node_2;
		node_arr[sub_node_1]->co_node_vec->push_back(sub_node_2);
		node_arr[sub_node_2]->co_node_vec->push_back(sub_node_1);
	}

	cout << bfs();

	return 0;
}