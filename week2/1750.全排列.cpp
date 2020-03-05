#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

char str[110];
char ans[110];
int len;

void dfs(int dpth) {
    if (dpth >= len) {
        printf("%s\n", ans);
    }
    for (int i = 0; i < len; i++) {
        if (str[i]) {
            ans[dpth] = str[i];
            str[i] = 0;
            dfs(dpth + 1);
            str[i] = ans[dpth];
        }
    }
}

int main() {
    scanf("%s", str);
    len = strlen(str);
    dfs(0);
    return 0;
}