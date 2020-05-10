#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

struct point {
    int x, y;
    int last_x, last_y;
    
    point(): x(0), y(0), last_x(0), last_y(0) {}
    point(int x, int y, int last_x, int last_y): x(x), y(y), last_x(last_x), last_y(last_y) {}
};

int mapp[5][5];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
point path[5][5];


int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &mapp[i][j]);
        }
    }
    queue<point> que;
    que.push(point(0, 0, 0, 0));
    while (!que.empty()) {
        point cur = que.front();
        que.pop();
        if (mapp[cur.x][cur.y]) {
            continue;
        }
        mapp[cur.x][cur.y] = 1;
        path[cur.x][cur.y] = cur;
        for (int k = 0; k < 4; k++) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];

            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
                que.push(point(nx, ny, cur.x, cur.y));
            }
        }
    }
    stack<point> stk;
    for (point cur = path[4][4]; cur.x != 0 || cur.y != 0; cur = path[cur.last_x][cur.last_y]) {
        stk.push(cur);
    }
    printf("(0, 0)\n");
    while (!stk.empty()) {
        printf("(%d, %d)\n", stk.top().x, stk.top().y);
        stk.pop();
    }
    return 0;
}