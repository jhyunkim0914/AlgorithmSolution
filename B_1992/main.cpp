#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
 
char** video;
int video_size;
 
void compress(int start_x, int start_y, int size) {
    // 확인하는 영역의 숫자가 전부 같은지 확인하고 출력 
    for (int a = start_x; a < start_x + (size); a++) {
        for (int b = start_y; b < start_y + (size); b++) {
 
            // 확인하는 영역의 숫자가 전부 같지 않다면 
            if (video[a][b] != video[start_x][start_y]) {  
                cout << "(";
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        // 크기가 1일 경우에는 숫자들을 출력해주고 그냥 종료한다. 
                        if (size == 1) {
                            cout << video[start_x][start_y];
                            return;
                        }
                        // 크기가 1 보다 클 경우에는 size 를 반으로 줄여서 4개로 분할한다.   
                        compress(start_x + (size / 2)*i, start_y + (size / 2)*j, size / 2);
                    }
                }
                cout << ")";
                return; 
            }
        }
    }
     
    // 확인하는 영역의 모두 숫자가 같다면 
    cout << video[start_x][start_y]; 
    return; 
}
 
 
int main() {
	freopen("input.txt", "r", stdin);
    cin >> video_size;
    video = (char**)malloc(sizeof(char*)*video_size);
 
    // 데이터 읽어오기
    for (int i = 0; i < video_size; i++) {
        video[i] = (char*)malloc(sizeof(char)*video_size);
        cin >> video[i];
    }
 
    compress(0,0,video_size);
 
    return 0;
}
