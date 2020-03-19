#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int nn, mm;
const int maxn = 100010;
int day_spending[maxn];

bool checkFajoSpending(int expect_fajo_spending) {
    int cnt_fajo = 1;
    int cur_fajo_spending = 0;
    int max_fajo_spending = 0;
    for (int i = 0; i < nn; i++) {
        if (cur_fajo_spending + day_spending[i] > expect_fajo_spending && cnt_fajo < mm) {
            cur_fajo_spending = 0;
            cnt_fajo += 1;
        }
        cur_fajo_spending += day_spending[i];
        max_fajo_spending = max(max_fajo_spending, cur_fajo_spending);
    }
    return max_fajo_spending <= expect_fajo_spending;
}

int main() {
    scanf("%d %d", &nn, &mm);
    int day_spending_max = 0;
    int day_spending_min = 10010;
    for (int i = 0; i < nn; i++) {
        scanf("%d", day_spending + i);
        day_spending_max = max(day_spending_max, day_spending[i]);
        day_spending_min = min(day_spending_min, day_spending[i]);
    }
    int ll = day_spending_min - 1;
    int rr = 1000000010;
    // (ll, rr]
    while (rr - ll > 1) {
        int mid = (ll + rr + 1) >> 1;
        // printf("===ll: %d, mid: %d, rr: %d\n", ll, mid, rr);
        // getchar();
        if (checkFajoSpending(mid)) {
            rr = mid;
        } else {
            ll = mid;
        }
    }
    printf("%d\n", rr);
    return 0;
}