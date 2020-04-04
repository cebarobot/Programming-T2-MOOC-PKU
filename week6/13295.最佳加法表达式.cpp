#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int max_huge_num = 20;
class HugeInt {
private:
    int size;
    int digits[max_huge_num];
public:
    void calcSize() {
        if (size == 0) {
            size = 1;
        }
        while (size > 1 && !digits[size - 1]) {
            size -= 1;
        }
    }
    HugeInt(): size(0) {
        memset(digits, 0, sizeof(digits));
    }
    HugeInt(int n) {
        memset(digits, 0, sizeof(digits));
        size = 0;
        while (n) {
            digits[size++] = n % 10000;
            n /= 10000;
        }
        calcSize();
    }
    HugeInt(const char * str) {
        memset(digits, 0, sizeof(digits));
        size = 0;
        if (!str) {
            return;
        }
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            int i_rev = len - i - 1;
            digits[i_rev / 4] = digits[i_rev / 4] * 10 + str[i] - '0';
        }
        size = len / 4 + 1;
        calcSize();
    }
    HugeInt(const HugeInt & xx): size(xx.size) {
        memcpy(digits, xx.digits, sizeof(digits));
    }
    HugeInt operator + (const HugeInt & yy) const {
        HugeInt xx = *this;
        int carry_io = 0;
        xx.size = max(xx.size, yy.size);
        for (int i = 0; i < xx.size; i++) {
            int res = xx.digits[i] + yy.digits[i] + carry_io;
            carry_io = res / 10000;
            xx.digits[i] = res % 10000;
        }
        xx.digits[xx.size++] = carry_io;
        xx.calcSize();
        return xx;
    }
    friend HugeInt operator + (int xx, const HugeInt & yy) {
        return HugeInt(xx) + yy;
    }
    HugeInt operator + (int xx) const {
        return *this + HugeInt(xx);
    }
    bool operator < (const HugeInt & yy) const {
        if (size != yy.size) {
            return size < yy.size;
        }
        for (int i = size - 1; i >= 0; i--) {
            if (digits[i] != yy.digits[i]) {
                return digits[i] < yy.digits[i];
            }
        }
        return false;
    }
    bool operator < (int xx) const {
        return *this < HugeInt(xx);
    }
    friend bool operator < (int xx, const HugeInt & yy) {
        return HugeInt(xx) < yy;
    }
        friend ostream & operator << (ostream & os, const HugeInt & xx) {
        char tmp[10];
        for (int i = xx.size - 1; i >= 0; i--) {
            // printf("====== digits[%d] = %d;\n", i, xx.digits[i]);
            if (i == xx.size - 1) {
                sprintf(tmp, "%d", xx.digits[i]);
            } else {
                sprintf(tmp, "%04d", xx.digits[i]);
            }
            os << tmp;
        }
        return os;
    }
};

const int max_n = 60;
string str;
HugeInt dp[max_n][max_n];
HugeInt num[max_n][max_n];

int main() {
    int mm;
    while (cin >> mm >> str) {
        int len = str.length();
        // cout << "len = " << len << endl;
        for (int i = 0; i < len; i++) {
            for (int j = 1; i + j <= len; j++) {
                // cout << "i = " << i << ", j = " << j << ", ";
                // cout << str.substr(i, j).c_str() << ", ";
                num[i][j] = HugeInt(str.substr(i, j).c_str());
                // cout << num[i][j] << endl;
            }
        }

        dp[0][0] = HugeInt(0);
        for (int pos = 1; pos <= len; pos++) {
            for (int cnt = 0; cnt < pos; cnt++) {
                dp[pos][cnt] = num[0][pos];
                if (cnt != 0) {
                    // 之前已经放了 cnt - 1 个加号，这意味着之前的长度至少为 cnt
                    for (int i = cnt; i < pos; i++) {
                        HugeInt cur = num[i][pos - i] + dp[i][cnt - 1];
                        // cout << i << "-" << pos - i << endl;
                        // cout << "i = " << i << " : " << num[i][pos - i] << " + " << dp[i][cnt - 1] << "=" << cur << endl;
                        if (cur < dp[pos][cnt]) {
                            dp[pos][cnt] = cur;
                        }
                    }
                }
                // cout << "pos = " << pos << ", cnt = " << cnt << " : " << dp[pos][cnt] << endl;
            }
        }
        cout << dp[len][mm] << endl;
    }
    return 0;
}