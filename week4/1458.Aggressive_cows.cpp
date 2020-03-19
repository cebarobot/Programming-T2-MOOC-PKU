#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int stalls_location[maxn];
int nn, cc;

int countCows(int min_distance) {
    int cnt = 1;
    int last_location = stalls_location[0];
    for (int i = 1; i < nn; i++) {
        if (stalls_location[i] - last_location >= min_distance) {
            cnt += 1;
            last_location = stalls_location[i];
        }
    }
    return cnt;
}

int main() {
    scanf("%d %d", &nn, &cc);
    int location_max = 0;
    int location_min = 1000000010;
    for (int i = 0; i < nn; i++) {
        scanf("%d", stalls_location + i);
        location_max = max(location_max, stalls_location[i]);
        location_min = min(location_min, stalls_location[i]);
    }
    sort(stalls_location, stalls_location + nn);
    int ll = location_min;
    int rr = location_max;
    while (rr - ll > 1) {
        int mid = (ll + rr) >> 1;
        if (countCows(mid) >= cc) {
            ll = mid;
        } else {
            rr = mid;
        }
    }
    printf("%d\n", ll); 
    return 0;
}