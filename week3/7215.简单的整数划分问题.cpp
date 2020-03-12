#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int dfs(int mx, int rm) {
    if (rm < 0) {
        return 0;
    }
    if (mx == 0 || rm == 0) {
        return 1;
    }
    int cnt = 0;
    for (int i = mx; i > 0; i--) {
        cnt += dfs(i, rm - i);
    }
    return cnt;
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        printf("%d\n", dfs(n, n));
    }
    return 0;
}