#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr1[40];
int arr2[40];
int arr3[40];
int ans = 0;

int main() {
    char ch;
    int nn = 0;
    while ((ch = getchar()) != '\n') {
        if (ch == '0') {
            arr1[nn] = 0;
            arr2[nn++] = 0;
        } else {
            arr1[nn] = 1;
            arr2[nn++] = 1;
        }
    }
    nn = 0;
    while ((ch = getchar()) != '\n') {
        if (ch == '0') {
            arr3[nn++] = 0;
        } else {
            arr3[nn++] = 1;
        }
    }
    
    ans = 0;
    for (int i = 1; i < nn; i++) {
        if (arr1[i - 1] != arr3[i - 1]) {
            ans ++;
            arr1[i - 1] = !arr1[i - 1];
            arr1[i] = !arr1[i];
            arr1[i + 1]  = ! arr1[i + 1];
        }
    }
    if (arr1[nn - 1] == arr3[nn - 1]) {
        printf("%d\n", ans);
        return 0;
    }
    ans = 1;
    arr2[0] = !arr2[0];
    arr2[1] = !arr2[1];
    for (int i = 1; i < nn; i++) {
        if (arr2[i - 1] != arr3[i - 1]) {
            ans ++;
            arr2[i - 1] = !arr2[i - 1];
            arr2[i] = !arr2[i];
            arr2[i + 1]  = ! arr2[i + 1];
        }
    }
    if (arr2[nn - 1] == arr3[nn - 1]) {
        printf("%d\n", ans);
        return 0;
    }
    printf("impossible\n");
    return 0;
}