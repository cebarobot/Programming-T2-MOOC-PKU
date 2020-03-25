#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int arr[maxn];
int n, k;

void findBigK(int * a, int * b, int k) {
    if (b - a <= 1) {
        return;
    }
    // printf("==========%ld %ld %d\n", a - arr, b - arr, k);
    // printf("!!!");
    // // for (int * p = a; p != b; p++) {
    // //     printf("%d ", *p);
    // // }
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
    // getchar();
    int ppp = *a;
    int * i = a;
    int * j = b - 1;
    while (i < j) {
        // printf("==========i: %ld j: %ld\n", i - arr, j - arr);
        while (i < j && *j <= ppp) {
            j -= 1;
        }
        while (i < j && *i >= ppp) {
            i += 1;
        }
        swap(*i, *j);
    }
        // printf("==========i: %ld j: %ld\n", i - arr, j - arr);
    swap(*i, *a);
    if (i - a >= k) {
        // printf("way1\n");
        findBigK(a, i, k);
    } else {
        // printf("way2\n");
        // printf("way2 : %ld %ld\n", a - arr, i - arr);
        int cnt_l = i - a;
        int cnt_r = k - cnt_l;
        findBigK(a, i, cnt_l);
        findBigK(i + 1, b, cnt_r);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    scanf("%d", &k);
    findBigK(arr, arr + n, k);
    for (int i = 0; i < k; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}