#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int clkstt[10];
char opt[10][10] = {
    "",
    "ABDE",
    "ABC",
    "BCEF",
    "ADG",
    "BDEFH",
    "CFI",
    "DEGH",
    "GHI",
    "EFHI"
};
int ans[10];
int resnw[10];
int clk[10];
int cnt = 0, mncnt = 36;

void dfs(int dpth) {
    if (dpth > 9) {
        // printf("---");
        // for (int i = 1; i <= 9; i++) {
        //     printf("%d ", resnw[i]);
        // }
        // printf("\n");
        // printf("===");
        // for (int i = 0; i < 9; i++) {
        //     printf("%d ", clk[i]);
        // }
        // printf("\n");
        // getchar();
        for (int i = 0; i < 9; i++) {
            if (clk[i]) {
                return;
            }
        }
        if (cnt < mncnt) {
            for (int i = 1; i <= 9; i++) {
                ans[i] = resnw[i];
            }
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        resnw[dpth] = i;
        cnt += 1;
        for (int j = 0; opt[dpth][j]; j++) {
            clk[opt[dpth][j] - 'A'] += i;
            clk[opt[dpth][j] - 'A'] %= 4;
        }
        dfs(dpth + 1);
        cnt -= 1;
        for (int j = 0; opt[dpth][j]; j++) {
            clk[opt[dpth][j] - 'A'] += 4 - i;
            clk[opt[dpth][j] - 'A'] %= 4;
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        scanf("%d", clk + i);
    }
    // printf("---");
    // for (int i = 0; i < 9; i++) {
    //     printf("%d ", clk[i]);
    // }
    // printf("\n");
    dfs(1);
    if (cnt == 36) {
        printf("impossible\n");
        return 0;
    }
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j < ans[i]; j++) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}