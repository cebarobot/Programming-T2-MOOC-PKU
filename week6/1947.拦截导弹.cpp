#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int max_k = 30;
int missile_height[max_k];
int max_missile[max_k];

int main() {
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", missile_height + i);
    }
    max_missile[0] = 1;
    for (int i = 1; i < k; i++) {
        max_missile[i] = 0;
        for (int j = 0; j < i; j++) {
            if (missile_height[j] >= missile_height[i] && max_missile[j] > max_missile[i]) {
                max_missile[i] = max_missile[j];
            }
        }
        max_missile[i] += 1;
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans = max(ans, max_missile[i]);
    }
    printf("%d\n", ans);
    return 0;
}