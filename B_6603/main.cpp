#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
 
int n, arr[20], visit[20];
 
// cur: current position, cnt: 누적 횟수
void select_fn(int cur, int cnt) {  
    if (cur == n && cnt == 6) {
        for (int i = 0; i < n; i++) { if (visit[i] == 1) { cout << arr[i] << " "; } }
        cout << '\n';
    }
    if (cur == n) return;
    visit[cur] = 1;
    select_fn(cur+1, cnt+1);  // 오른쪽으로 한칸이동, 쌓은갯수+1
    visit[cur] = 0;  // 위에서 방문을 완료했기에 방문 초기화
    select_fn(cur+1, cnt);  // 현재 위치만 오른쪽으로 한칸이동후 재탐색
}
 
int main() {
	freopen("input.txt", "r", stdin);
    while (1) {
        cin >> n;
        if (n == 0)
            return 0;
        else {
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            visit[20] = { 0 };
            select_fn(0, 0);
        }
        cout << '\n';
    }
    return 0;
}
