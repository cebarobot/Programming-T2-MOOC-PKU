#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<int, int> ptt;
int aa, bb, cc;
int mapp[110][110];
int ope[110][110];
ptt lst[110][110];

string ope_name[] = {
    "FILL(1)",
    "FILL(2)",
    "DROP(1)",
    "DROP(2)",
    "POUR(1,2)",
    "POUR(2,1)"
}; 

ptt doOperation(int k, ptt cur) {
    if (k == 0) {
        return ptt(aa, cur.second);
    } else if (k == 1) {
        return ptt(cur.first, bb);
    } else if (k == 2) {
        return ptt(0, cur.second);
    } else if (k == 3) {
        return ptt(cur.first, 0);
    } else if (k == 4) {
        if (cur.first < bb - cur.second) {
            return ptt(0, cur.first + cur.second);
        } else {
            return ptt(cur.first + cur.second - bb, bb);
        }
    } else if (k == 5) {
        if (cur.second < aa - cur.first) {
            return ptt(cur.first + cur.second, 0);
        } else {
            return ptt(aa, cur.first + cur.second - aa);
        }
    }
    return ptt(0, 0);
}

int main() {
    scanf("%d %d %d", &aa, &bb, &cc);
    queue<ptt> que;
    mapp[0][0] = 0;
    que.push(ptt(0, 0));
    bool ok = false;
    ptt ok_status;
    while (!que.empty()) {
        ptt cur = que.front();
        que.pop();
        for (int i = 0; i < 6; i++) {
            ptt nxt = doOperation(i, cur);
            if (mapp[nxt.first][nxt.second]) {
                continue;
            }
            mapp[nxt.first][nxt.second] = mapp[cur.first][cur.second] + 1;
            lst[nxt.first][nxt.second] = cur;
            ope[nxt.first][nxt.second] = i;
            if (nxt.first == cc || nxt.second == cc) {
                ok_status = nxt;
                ok = true;
                break;
            }
            que.push(nxt);
        }
        if (ok) {
            break;
        }
    }
    if (ok) {
        printf("%d\n", mapp[ok_status.first][ok_status.second]);
        stack<int> stk;
        for (ptt t = ok_status; t != ptt(0, 0); t = lst[t.first][t.second]) {
            stk.push(ope[t.first][t.second]);
        }
        while (!stk.empty()) {
            printf("%s\n", ope_name[stk.top()].c_str());
            stk.pop();
        }
    } else {
        printf("impossible\n");
    }
    return 0;
}