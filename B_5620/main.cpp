#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

#define INF 987654321
#define MAX_V 20001
#define MAX_E 300001

using namespace std;

int start_node_num, V, E;
 
typedef struct NODE {
    int end;
    int val;
};

// 각 노드의 엣지를 저장하는 벡터 
// 0번 인덱스는 버린다. 
vector<NODE> EDGE_arr[MAX_E];
// 출발 노드에서부터의 거리를 저장하는 배열
int route_val[MAX_V] = { 0 };
int isUsed[MAX_V] = { 0 };
 
void dijkstra() {
    int now_node = start_node_num;
    isUsed[now_node] = 1;
    vector<int> can_change_node_vec;
 
    // 노드의 거리 갱신은 V-1 번 만큼 하면 된다. 
    for (int not_use = 0; not_use < V-1; not_use++){
        isUsed[now_node] = 1;
 
        // 현재 노드에서 부터 주변에 있는 얘들의 값을 갱신한다. 
        for (int k = 0; k < EDGE_arr[now_node].size(); k++) {
            int new_val = route_val[now_node] + EDGE_arr[now_node][k].val;
            int before_val = route_val[EDGE_arr[now_node][k].end];
 
            // 현재 노드로 부터 연결된 엣지의 목적지까지 가는 거리와 기존의 거리를 비교하여, 
            // 기존의 것이 더 크면 값을 갱신한다.  
            if (new_val < before_val) {
                route_val[EDGE_arr[now_node][k].end] = new_val;
                can_change_node_vec.push_back(EDGE_arr[now_node][k].end);
            }
        }
 
        int sub_start_node = -1; 
        int sub_index = -1;
        for (int i = 0; i < can_change_node_vec.size(); i++) {
            if ( !isUsed[can_change_node_vec[i]] ) {
                // 만약 다음 노드가 정해지지 않았으면, 다음 노드를 결정한다. 
                if (sub_start_node == -1)     sub_start_node = can_change_node_vec[i];
                // 다음 노드가 결정 되어 있으면 비교해서 변경한다. 
                else {
                    // 만약 최소 노드가 다시 발견되면 갱신한다.
                    if (route_val[sub_start_node] > route_val[can_change_node_vec[i]]) { 
                        sub_index = i;
                        sub_start_node = can_change_node_vec[i];
                    }
                }
            }
        } 
 
        if (sub_index != -1) can_change_node_vec.erase(can_change_node_vec.begin() + sub_index);
 
        // 다음 노드 갱신 
        now_node = sub_start_node; 
    }
}

int main(){
	freopen("input.txt", "r", stdin);
	
    cin >> V >> E >> start_node_num;
    
    int from, to, val;
    // 간선 연결 
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &from, &to, &val);
        int isExist = 0;
        // 간선간의 중복을 제거하기 위한 구문 
        for (int j = 0; (j < EDGE_arr[from].size()) && (!isExist); j++) {
            // 지금 노드가 더 작거나 같으면 교체한다. 
            if ((EDGE_arr[from][j].end == to) && EDGE_arr[from][j].val >= val) {
                EDGE_arr[from][j].val = val;
                isExist = 1;
            }
        }
        // 존재하지 않으면 밀어 넣는다. 
        if (isExist == 0)
            EDGE_arr[from].push_back(NODE{ to, val });
    }
 
    // 간선간의 거리 초기화 
    for (int i = 1; i <= V; i++) {
        route_val[i] = INF;
    }
    route_val[start_node_num] = 0;
 
    // 벨만-포드 알고리즘은 복잡도가 O(V*E) 이기 때문에, 이 문제에서는 너무 크다. 
    // 다익스트라 알고리즘을 진행한다.
    dijkstra();
 
    // 값을 출력한다. 
    for (int i = 1; i <= V; i++) {
        if (route_val[i] != INF) printf("%d\n", route_val[i] );
        else printf("INF\n");
    }
 
    return 0;
}