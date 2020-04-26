#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int mm, nn, tt;
char mapp[210][210];
bool flg_map[210][210];
int time_map[210][210];
int tt_map[210][210][12];
int ans;
int st_xx, st_yy;
int ed_xx, ed_yy;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void dfs(int xx, int yy, int cur_time, int cur_tt) {
    // printf("---(%d, %d): time = %d, tt = %d\n", xx, yy, cur_time, cur_tt);
    if (cur_time >= time_map[ed_xx][ed_yy]) {
        return;
    }
    if (cur_time >= tt_map[xx][yy][cur_tt]) {
        return;
    }
    time_map[xx][yy] = min(time_map[xx][yy], cur_time);
    tt_map[xx][yy][cur_tt] = min(tt_map[xx][yy][cur_tt], cur_time);
    if (mapp[xx][yy] == '+') {
        return;
    }
    for (int k = 0; k < 4; k++) {
        int cur_x = xx + dx[k];
        int cur_y = yy + dy[k];
        if (cur_x < 0 || cur_x >= mm || cur_y < 0 || cur_y >= nn) {
            continue;
        }
        if (flg_map[cur_x][cur_y]) {
            continue;
        }
        flg_map[cur_x][cur_y] = true;
        if (mapp[cur_x][cur_y] == '#') {
            if (cur_tt) {
                dfs(cur_x, cur_y, cur_time + 1, cur_tt - 1);
            }
        } else {
            dfs(cur_x, cur_y, cur_time + 1, cur_tt);
        }
        flg_map[cur_x][cur_y] = false;
    }
}

int main() {
    scanf("%d %d %d", &mm, &nn, &tt);
    for (int i = 0; i < mm; i++) {
        scanf("%s", mapp[i]);
    }
    memset(time_map, 0x3f, sizeof(time_map));
    memset(tt_map, 0x3f, sizeof(tt_map));
    for (int i = 0; i < mm; i++) {
        for (int j = 0; j < nn; j++) {
            if (mapp[i][j] == '@') {
                st_xx = i;
                st_yy = j;
            } else if (mapp[i][j] == '+') {
                ed_xx = i;
                ed_yy = j;
            }
        }
    }
    dfs(st_xx, st_yy, 0, tt);
    if (time_map[ed_xx][ed_yy] < 0x3f3f3f3f) {
        printf("%d\n", time_map[ed_xx][ed_yy]);
    } else {
        printf("-1\n");
    }
    return 0;
}