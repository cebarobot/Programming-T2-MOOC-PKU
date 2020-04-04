#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int max_str = 210;
char str1[max_str];
char str2[max_str];
char str3[max_str + max_str];
bool ans;
bool dp[max_str][max_str];

int main() {
    int nnn;
    scanf("%d", &nnn);
    for (int nnn_i = 1; nnn_i <= nnn; nnn_i++) {
        scanf("%s %s %s", str1, str2, str3);
        printf("Data set %d: ", nnn_i);
        
        int len_1 = strlen(str1);
        int len_2 = strlen(str2);

        for (int i = 0; i <= len_1; i++) {
            for (int j = 0; j <= len_2; j++) {
                dp[i][j] = false;
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                }
                if (i != 0 && str3[i + j - 1] == str1[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                    // printf("-------update from iiiii\n");
                }
                if (j != 0 && str3[i + j - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                    // printf("-------update from jjjjj\n");
                }
                // printf("str1[i - 1] = %c, str2[j - 1] = %c, str3[i + j - 1] = %c\n", str1[i - 1], str2[j - 1], str3[i + j - 1]);
                // fprintf(stdout,"dp[%d][%d] = %s\n", i, j, dp[i][j]? "true" : "false");
            }
        }
        printf("%s\n", dp[len_1][len_2]? "yes" : "no");
    }
    return 0;
}