#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int dx[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dy[] = {-2, -2, -1, -1, 1, 1, 2, 2};

int p, q;
int mapp[30][30];
int route_x[30];
int route_y[30];

bool dfs(int xx, int yy, int depth) {
    // printf("--%d--%c%d\n", depth, yy + 'A', xx + 1);
    if (depth >= p * q) {
        return true;
    }
    for (int i = 0; i < 8; i++) {
        int cur_x = xx + dx[i];
        int cur_y = yy + dy[i];
        if (cur_x < 0 || cur_x >= p || cur_y < 0 || cur_y >= q) {
            continue;
        }
        if (mapp[cur_x][cur_y]) {
            continue;
        }
        mapp[cur_x][cur_y] = 1;
        route_x[depth] = cur_x;
        route_y[depth] = cur_y;
        if (dfs(cur_x, cur_y, depth + 1)) {
            return true;
        }
        mapp[cur_x][cur_y] = 0;
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d %d", &p, &q);
        memset(mapp, 0, sizeof(mapp)); 
        printf("Scenario #%d:\n", i);
        route_x[0] = 0;
        route_y[0] = 0;
        mapp[0][0] = 1;
        if (dfs(0, 0, 1)) {
            for (int k = 0; k < p * q; k++) {
                printf("%c%d", route_y[k] + 'A', route_x[k] + 1);
            }
        } else {
            printf("impossible");
        }
        printf("\n\n");
    }
    return 0;
}