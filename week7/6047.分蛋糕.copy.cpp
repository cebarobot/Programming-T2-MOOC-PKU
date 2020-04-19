#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int mx = 0x3f3f3f3f;
const int max_whm = 30;
int ww, hh, mm;
int dp[max_whm][max_whm][max_whm];

int main() {
    while (scanf("%d %d %d", &ww, &hh, &mm) == 3 && (ww || hh || mm)) {
        for (int iw = 0; iw <= ww; iw++) {
            for (int ih = 0; ih <= hh; ih++) {
                dp[iw][ih][0] = iw * ih;
            }
        }
        for (int im = 1; im <= mm; im++) {
            for (int iw = 0; iw <= ww; iw++) {
                for (int ih = 0; ih <= hh; ih++) {
                    if (iw * ih < mm + 1) {
                        dp[iw][ih][im] = mx;
                        continue;
                    }
                    int sv = mx;
                    for (int i = 1; i <= iw - 1; i++) {
                        int si = mx;
                        for (int k = 0; k < mm; k++) {
                            si = min(si, max(dp[i][ih][k], dp[iw - i][ih][im - 1 -k]));
                        }
                        sv = min(sv, si);
                    }
                    int sh = mx;
                    for (int i = 1; i <= ih - 1; i++) {
                        int si = mx;
                        for (int k = 0; k < mm; k++) {
                            si = min(si, max(dp[iw][i][k], dp[iw][ih - i][im - 1 -k]));
                        }
                        sh = min(sh, si);
                    }
                    dp[iw][ih][im] = min(sv, sh);
                }
            }
        }
        printf("%d\n", dp[ww][hh][mm]);
    }
    return 0;
}