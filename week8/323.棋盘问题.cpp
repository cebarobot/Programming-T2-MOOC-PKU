#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int nn, kk;
char mapp[10][10];
bool flg[10];
int ans;

void dfs(int row, int cnt) {
    if (row >= nn) {
        if (cnt == kk) {
            ans += 1;
        }
        return;
    }
    for (int i = 0; i < nn; i++) {
        if (!flg[i] && mapp[row][i] == '#') {
            flg[i] = true;
            dfs(row + 1, cnt + 1);
            flg[i] = false;
        }
    }
    dfs(row + 1, cnt);
}

int main() {
    while (scanf("%d %d", &nn, &kk) == 2 && nn != -1 && kk != -1) {
        for (int i = 0; i < nn; i++) {
            scanf("%s", mapp[i]);
        }
        ans = 0;
        dfs(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}