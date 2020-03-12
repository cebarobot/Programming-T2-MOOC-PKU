#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

int opt(char a) {
    return a == '|'? 1 : a == '&'? 2 : a == '!'? 3 : 0;
}

bool num(char a) {
    return a == 'F' ? false : true;
}

int main() {
    int n = 0;
    char ch;
    stack <int> operators;
    stack <bool> numbers;
    while (1) {
        ch = getchar();
        // printf("====%c\n", ch);
        if (ch == 'V' || ch == 'F') {
            numbers.push(num(ch));
        } else if (ch == '!') {
            operators.push(opt(ch));
        } else if (ch == '&' || ch == '|') {
            int curopt = opt(ch);
            while (!operators.empty() && operators.top() >= curopt) {
                // printf("------------opt = %d: size = %d\n", ch, operators.size());
                if (operators.top() == opt('!')) {
                    bool x = numbers.top();
                    numbers.pop();
                    numbers.push(!x);
                } else if (operators.top() == opt('&')) {
                    bool y = numbers.top();
                    numbers.pop();
                    bool x = numbers.top();
                    numbers.pop();
                    numbers.push(x & y);
                } else if (operators.top() == opt('|')) {
                    bool y = numbers.top();
                    numbers.pop();
                    bool x = numbers.top();
                    numbers.pop();
                    numbers.push(x | y);
                }
                operators.pop();
            }
            operators.push(opt(ch));
        } else if (ch == '(') {
            operators.push(opt(ch));
        } else if (ch == ')' || ch == '\n' || ch == EOF) {
            while (!operators.empty() && operators.top() != opt('(')) {
                // printf("------------opt = %d: size = %d\n", ch, operators.size());
                if (operators.top() == opt('!')) {
                    bool x = numbers.top();
                    numbers.pop();
                    numbers.push(!x);
                } else if (operators.top() == opt('&')) {
                    bool y = numbers.top();
                    numbers.pop();
                    bool x = numbers.top();
                    numbers.pop();
                    numbers.push(x & y);
                } else if (operators.top() == opt('|')) {
                    bool y = numbers.top();
                    numbers.pop();
                    bool x = numbers.top();
                    numbers.pop();
                    numbers.push(x | y);
                }
                operators.pop();
            }
            if (!operators.empty() && operators.top() == opt('(')) {
                operators.pop();
            }
        }
        if (ch == '\n' || ch == EOF) {
            if (numbers.empty()) {
                printf("error!!!!\n");
            } else {
                printf("Expression %d: %c\n", ++n, numbers.top()? 'V' : 'F');
                numbers.pop();
            }
        }
        if (ch == EOF) {
            break;
        }
    }
    return 0;
}