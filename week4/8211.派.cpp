#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int nn, ff;
const int maxn = 10010;
double pie_vol[maxn];

int countPies(double pie_vol_one) {
    int cnt = 0;
    for (int i = 0; i < nn; i++) {
        double pie_vol_remain = pie_vol[i];
        while (pie_vol_remain >= pie_vol_one) {
            pie_vol_remain -= pie_vol_one;
            cnt += 1;
        }
    }
    return cnt;
}

int main() {
    scanf("%d %d", &nn, &ff);
    ff += 1;
    double max_pie_vol = 0.0;
    double min_pie_vol = (double) 10000 * 10000 * M_PI;
    for (int i = 0; i < nn; i++) {
        int tt;
        scanf("%d", &tt);
        pie_vol[i] = (double) tt * tt * M_PI;
        max_pie_vol = max(max_pie_vol, pie_vol[i]);
        min_pie_vol = min(min_pie_vol, pie_vol[i]);
    }
    double ll = 0.0;
    double rr = max_pie_vol;
    while (rr - ll > 0.000001) {
        double mid = (ll + rr) / 2.0;
        if (countPies(mid) >= ff) {
            ll = mid;
        } else {
            rr = mid;
        }
    }
    printf("%.3f\n", ll);
    return 0;
}