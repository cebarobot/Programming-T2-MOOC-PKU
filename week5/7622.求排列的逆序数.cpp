#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int arr[maxn];
int temp[maxn];
int n;

long long mergeSortCount(int * arr, int ll, int rr) {
    if (rr - ll <= 1) {
        return 0;
    }
    int mid = (ll + rr) >> 1;
    long long ans = 0;
    ans += mergeSortCount(arr, ll, mid);
    ans += mergeSortCount(arr, mid, rr);
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
    int * temp = new int[rr - ll];
    int pt = 0;
    int p1 = ll, p2 = mid;
    while (p1 < mid && p2 < rr) {
        if (arr[p1] <= arr[p2]) {
            // for (int kkk = mid; kkk < p2; kkk ++) {
            //     printf("--(%d, %d)\n", arr[p1], arr[kkk]);
            // }
            temp[pt++] = arr[p1++];
            ans += (p2 - mid);
        } else {
            temp[pt++] = arr[p2++];
        }
    }
    while (p1 < mid) {
        // for (int kkk = mid; kkk < rr; kkk ++) {
        //     printf("--(%d, %d)\n", arr[p1], arr[kkk]);
        // }
        temp[pt++] = arr[p1++];
        ans += rr - mid;
    }
    while (p2 < rr) {
        temp[pt++] = arr[p2++];
    }
    memcpy(arr + ll, temp, (rr - ll) * sizeof(int));
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    long long ans = mergeSortCount(arr, 0, n);
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
    printf("%lld\n", ans);
    return 0;
}