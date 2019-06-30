#include <iostream> 
#include <stack>
#include <vector>
#include <string>
using namespace std;
/*
优先级表
a<b表示a的优先级小于等于b
a>b表示a的优先级大于b
=表示遇到了右括号
-表示不可能出现的比较

*/
char table[][5] = { /* !    &    |    (    )  */ { '>', '<', '<', '>', '<' }, { '>', '<', '<', '>', '<' }, { '>', '<', '<', '>', '<' }, { '>', '>', '>', '>', '=' }, { '>', '>', '>', '-', '<' } };
// 获取优先级
char precede(char a, char b) { 
    int i, j; switch (a) { 
        case '!': i = 0; break; 
        case '&': i = 1; break; 
        case '|': i = 2; break; 
        case '(': i = 3; break; 
        case ')': i = 4; break; 
    } 
    switch (b) { 
        case '!': j = 0; break; 
        case '&': j = 1; break; 
        case '|': j = 2; break; 
        case '(': j = 3; break; 
        case ')': j = 4; break; 
    } 
    return table[i][j]; 
} 

bool boolIt(char a) { 
    if (a == 'V') return true; 
    if (a == 'F') return false; 
} // 计算与、或、非操作的结果 
char cal(char op, char a, char b = 'V') { 
    bool num1 = boolIt(a); 
    bool num2 = boolIt(b); 
    bool result; 
    switch (op) { 
        case '|': result = num1 | num2; break;
        case '&': result = num1&num2; break; 
        case '!': result = !num1;break;
    } // cout <<"##"<< num1 << " " << num2 << " " << result << endl; 
    if (result == true) return 'V'; 
    else return 'F';
} // 将与、或、非操作的结果压栈
void goCal(stack<char> &op, stack<char> &data) { 
    char op_cal = op.top(); // cout << "op_cal:" << op_cal << endl; 
    op.pop();
    if (op_cal == '!') {
        char num1 = data.top(); 
        data.pop(); 
        char result = cal(op_cal, num1); 
        data.push(result); 
    } 
    else {
        char num1 = data.top(); 
        data.pop();
        char num2 = data.top(); 
        data.pop(); 
        char result = cal(op_cal, num1, num2); 
        data.push(result);
    }
} // 根据操作符优先级，进行不同的操作

void operateCh(char ch, int &i, stack<char> &op, stack<char> &data) {
    char pre = precede(op.top(), ch);
    if (pre == '>') { 
        op.push(ch);
        i++;
        return;
    }
    else if (pre == '=') {
        op.pop(); 
        i++; 
    } 
    else if (pre == '<') { 
        goCal(op, data);
    }
} 

void showResult(string command) {
    stack<char> op; 
    stack<char> data; 
    for (int i = 0; i<command.size();) { 
        char ch = command[i]; 
        if (ch == ' ') { 
            i++;
            continue; 
        } // 操作符 
        if (ch == '|' || ch == '&' || ch == '!' || ch == '(' || ch == ')') { // cout << "ch:" << ch << endl; 
            if (op.empty()) { 
                op.push(ch); 
                i++;
            } 
            else { 
                operateCh(ch, i, op, data);
            }
        } // 数字，直接压入数字栈 
        else if (ch == 'V' || ch == 'F') { 
            data.push(ch); 
            i++; // cout << "dp:" << ch << endl; 
        }
    } 
    while (!op.empty()) { 
         goCal(op, data);
    }
    cout << data.top() << endl;
} 

int main() {
    string command; 
    while(getline(cin, command)) { 
        showResult(command); 
    } 
    return 0;
}
