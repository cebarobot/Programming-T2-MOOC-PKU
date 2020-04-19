#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int max_n = 60;

int nn, kk;
int dp_k_sum[max_n][max_n];         // dp[n][k]
int dp_diff_sum[max_n];             // dp[max_int][n]
int dp_odd_sum[max_n];              // dp[max_int][n]

int main() {
    while (scanf("%d %d", &nn, &kk) == 2) {
        dp_k_sum[1][1] = 1;
        for (int i = 2; i <= nn; i++) {
            for (int j = 1; j <= i; j++) {
                dp_k_sum[i][j] = dp_k_sum[i - j][j] + dp_k_sum[i - 1][j - 1];
            }
        }
        memset(dp_diff_sum, 0, sizeof(dp_diff_sum));
        dp_diff_sum[0] = 1;
        for (int i = 1; i <= nn; i++) {
            for (int j = nn; j >= i; j--) {
                dp_diff_sum[j] += dp_diff_sum[j - i];
            }
        }
        memset(dp_odd_sum, 0, sizeof(dp_odd_sum));
        dp_odd_sum[0] = 1;
        for (int i = 1; i <= nn; i += 2) {
            for (int j = nn; j >= i; j--) {
                for (int t = j - i; t >= 0; t -= i) {
                    dp_odd_sum[j] += dp_odd_sum[t];
                }
            }
        }

        printf("%d\n", dp_k_sum[nn][kk]);
        printf("%d\n", dp_diff_sum[nn]);
        printf("%d\n", dp_odd_sum[nn]);
    }

    return 0;
}