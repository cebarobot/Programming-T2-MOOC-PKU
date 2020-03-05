#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int pw2[16] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};
int ll;

void rec(int xx) {
    int flg = 1;
    for (int i = 15; i >= 0; i--) {
        if (xx >= pw2[i]) {
            xx -= pw2[i];
            if (flg) {
                flg = 0;
            } else {
                printf("+");
            }
            if (i == 0) {
                printf("2(0)");
            } else if (i == 1) {
                printf("2");
            } else {
                printf("2(");
                rec(i);
                printf(")");
            }

        }
    }
}

int main() {
    int xx;
    scanf("%d", &xx);
    rec(xx);
    printf("\n");
    return 0;
}