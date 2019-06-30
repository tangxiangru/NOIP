#include <stack> 
#include <iostream> 
#include <iomanip> 
#include <math.h>
using namespace std; 
void cal(string param, stack<double> &num); 
void bolan(string &param, stack<double> &num) { // 遇到数字就入栈 
    if (param != "+"&&param != "*"&&param != "-"&&param != "/") {
        num.push(atof(param.c_str())); 
    } // 遇到操作符就计算，并将结果入栈
    else { 
        cal(param, num);
        } 
    } 
void cal(string param, stack<double> &num) { 
    double num1 = num.top(); num.pop(); 
    double num2 = num.top(); num.pop();
    
    if (param == "+") { num.push(num1 + num2); } 
    if (param == "-") { num.push(num1 - num2); }
    if (param == "*") { num.push(num1 * num2); } 
    if (param == "/") { num.push(num1 / num2); } // cout<<"cal result:"<<num.top()<<endl; } 

int main() { 
    stack<double> num; 
    string command; 
    getline(cin, command); 
    int index1 = 0, index2 = command.length()-1; // 从右向左遍历表达式 获取操作符和数字
    for (int i = command.length()-1; i>=0; i--) { 
        if (command[i] == ' ' || i == 0) { 
            if(i==0) index1 = 0; 
            else index1 = i+1; 
            string param = command.substr(index1, index2-index1+1); // cout << index1 << " " << index2 << " #" << param << endl; 
            index2 = i-1; 
            bolan(param, num); 
        } 
    } 
    cout<<fixed<<setprecision(6)<<num.top()<<endl; 
}
