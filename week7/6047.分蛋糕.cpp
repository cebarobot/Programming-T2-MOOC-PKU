#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int mx = 0x3f3f3f3f;
const int max_whm = 30;
int ww, hh, mm;
int dp_array[max_whm][max_whm][max_whm];
bool has_do[max_whm][max_whm][max_whm];

int dp(int iw, int ih, int im) {
    // printf("--------%d %d %d\n", iw, ih, im);
    if (im == 0) {
        return iw * ih;
    }
    if (iw * ih < im + 1) {
        return mx;
    }
    if (has_do[iw][ih][im]) {
        return dp_array[iw][ih][im];
    }
    int sv = mx;
    for (int i = 1; i <= iw - 1; i++) {
        int si = mx;
        for (int k = 0; k <= im - 1; k++) {
            si = min(si, max(dp(i, ih, k), dp(iw - i, ih, im - 1 - k)));
        }
        sv = min(sv, si);
    }
    int sh = mx;
    for (int i = 1; i <= ih - 1; i++) {
        int si = mx;
        for (int k = 0; k <= im - 1; k++) {
            si = min(si, max(dp(iw, i, k), dp(iw, ih - i, im - 1 - k)));
        }
        sh = min(sh, si);
    }
    has_do[iw][ih][im] = true;
    dp_array[iw][ih][im] = min(sv, sh);
    return dp_array[iw][ih][im];
}

int main() {
    while (scanf("%d %d %d", &ww, &hh, &mm) == 3 && (ww || hh || mm)) {
        memset(dp_array, 0x3f, sizeof(dp_array));
        memset(has_do, 0, sizeof(has_do));
        printf("%d\n", dp(ww, hh, mm - 1));
    }
    return 0;
}