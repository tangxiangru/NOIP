#include<iostream>
#include<cstdio>
using namespace std;

int Mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool Judge(int num) {
if((num % 4 == 0 && num % 100 != 0) || num % 400 == 0)
return true;
return false;
}
struct Date {
int year, month, day;
Date() {
year = month = day = 0;
}

Date Inc() {
if(Judge(year)) Mon[2] = 29;
else Mon[2] = 28;
if(day == Mon[month]) {
if(month == 12) {
year++;
month = day = 1;
}
else {
month++;
day = 1;
}
}
else day++;
return *this;
}
}a;
istream& operator >> (istream &in, Date &num) {
int a, b, c;
scanf("%d-%d-%d", &a, &b, &c);
num.year = a, num.month = b, num.day = c;
return in;
}
ostream& operator << (ostream &out, const Date &num) {
printf("%04d-%02d-%02d\n", num.year, num.month, num.day);
return out;
}

int main() {
cin >> a;
cout << a.Inc();
}
