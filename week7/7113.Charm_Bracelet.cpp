#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int max_n = 3410;
const int max_m = 12890;
int weight[max_n];
int desirability[max_n];
int dp[max_m];

int main() {
    int nn, mm;
    scanf("%d %d", &nn, &mm);

    for (int i = 0; i < nn; i++) {
        scanf("%d %d", weight + i, desirability + i);
    }
    for (int i = 0; i < nn; i++) {
        for (int j = mm; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + desirability[i]);
        }
    }
    printf("%d\n", dp[mm]);
    return 0;
}