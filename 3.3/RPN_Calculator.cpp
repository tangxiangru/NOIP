#include <stack> 
#include <iostream> 
#include <iomanip>
#include <math.h> 
#include <vector> 
#include <algorithm> 
#include <sstream>
#include <queue> 
using namespace std; 
void cal(string param, stack<double> &num); 
void bolan(string &param, stack<double> &num) { // 遇到数字就入栈 
    if (param != "+"&&param != "*"&&param != "-"&&param != "/"&&param!="^") {
        num.push(atof(param.c_str())); 
    } // 遇到操作符就计算，并将结果入栈 
    else { cal(param, num); } 
} 
void cal(string param, stack<double> &num) { 
    double num1 = num.top(); 
    num.pop(); 
    double num2 = num.top(); 
    num.pop();
    if (param == "+") { num.push(num2 + num1); } 
    if (param == "-") { num.push(num2 - num1); }
    if (param == "*") { num.push(num2 * num1); } 
    if (param == "/") { num.push(num2 / num1); } 
    if (param == "^") { num.push(pow(num2, num1)); } // cout<<"cal result:"<<num.top()<<endl; }

int main() { 
    int n;
    cin>>n; // 初始化memory
    priority_queue<double,vector<double>,greater<double>> p; 
    vector<double> nums; 
    for(int i=0;i<n;i++) { 
        double inData; 
        cin>>inData; 
        p.push(inData); 
    } 
    getchar(); 
    // 计算后缀表达式的值 

    stack<double> bolan_num;
    string command; 
    while(getline(cin,command)) { 
        int index1 = 0, index2 = command.length()-1; // 从右向左遍历表达式 获取操作符和数字 
        for (int i = 0; i<=command.length(); i++) {
            if (command[i] == ' ' || command[i] == '\0') {
                index2 = i; 
                string param = command.substr(index1, index2-index1); // cout << index1 << " " << index2 << " #" << param << endl; 
                index1 = index2+1; 
                if(param == "=") { // printf("%e\n", bolan_num.top()); // 用新计算出的值，替换掉memory中的最小值 
                    cout<<fixed<<setprecision(6)<<scientific<<bolan_num.top()<<endl; 
                    p.pop();
                    p.push(bolan_num.top());
                    bolan_num.pop();
                    if(!bolan_num.empty()) { 
                        cout<<"expect empty"<<endl; 
                    }
                }
                else { 
                    bolan(param, bolan_num);
                }
            } 
        } 
    } 
    cout<<endl; // 输出memory中的值 
    int count = 0;
    for(int i=1;i<=n;i++) { 
        count++; 
        if(i==n) cout<<fixed<<setprecision(6)<<scientific<<p.top(); 
        else if(count%10 == 0) cout<<fixed<<setprecision(6)<<scientific<<p.top()<<endl; 
        else cout<<fixed<<setprecision(6)<<scientific<<p.top()<<" ";
        p.pop(); 
    } 
}
