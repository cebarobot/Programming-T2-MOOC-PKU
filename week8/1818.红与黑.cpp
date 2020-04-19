#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

char mapp[30][30];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int ans;
int ww, hh;

void dfs(int xx, int yy) {
    for (int i = 0; i < 4; i++) {
        int cur_x = xx + dx[i];
        int cur_y = yy + dy[i];
        if (cur_x < 0 || cur_x >= hh || cur_y < 0 || cur_y >= ww) {
            continue;
        }
        if (mapp[cur_x][cur_y] == '.') {
            mapp[cur_x][cur_y] = '@';
            ans ++;
            dfs(cur_x, cur_y);
        }
    }
}

int main() {
    while (scanf("%d %d", &ww, &hh) == 2 && ww && hh) {
        for (int i = 0; i < hh; i++) {
            scanf("%s", mapp[i]);
        }
        int sx, sy;
        for (int i = 0; i < hh; i++) {
            for (int j = 0; j < ww; j++) {
                if (mapp[i][j] == '@') {
                    sx = i;
                    sy = j;
                    break;
                }
            }
        }
        ans = 1;
        dfs(sx, sy);
        // for (int i = 0; i < hh; i++) {
        //     printf("%s\n", mapp[i]);
        // }
        printf("%d\n", ans);
    }
    
    return 0;
}