#include<iostream>
#include<queue>

using namespace std;

int nx, ny;
int graph[101][101];
int dx[4] = {-1, 1, 0, 0};  // 상하 이동
int dy[4] = {0, 0, -1, 1};  // 좌우 이동

int maze(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++){
            int mx = qx + dx[i];
            int my = qy + dy[i];

            if(mx < 0 || mx >= nx || my < 0 || my >= ny){   // 다음 탐색 할 위치가 미로 밖인지 확인
                continue;
            }
            else if(graph[mx][my] == 0){                    // 다음 탐색 할 위치가 이동이 가능한 위치인지 확인
                continue;
            }
            else if(graph[mx][my] == 1){                    // 이동 가능하면서 최초로 탐색하는 위치인지
                graph[mx][my] = graph[qx][qy] + 1;
                q.push(make_pair(mx, my));
            }
        }
    }

    return graph[nx-1][ny-1];                               // 모두 수행한 후 마지막 정점위치의 값 반환
}

int main(){
    scanf("%d %d", &nx, &ny);

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            scanf("%1d", &graph[i][j]);
        }
    }

    cout << maze(0,0) << endl;

    return 0;
}
