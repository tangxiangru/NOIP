#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int q[5843] = {};
 
int main()
{
	int n;
	vector<int> in;
	while (cin >> n)
	{
		if (n==0)
		{
			break;
		}
		in.push_back(n);
	}
	sort(in.begin(), in.end());
	q[1] = 1;
	int h1=1,h2=1,h3=1,h4=1,x1,x2,x3,x4,tail=1,i;
	if (in.at(0)==1)
	{
		cout << "The 1st humble number is 1." << endl;
		i = 1;
	}
	else
	{
		i = 0;
	}
	while (tail<in.back())
	{
		x1 = q[h1]*2;
		x2 = q[h2]*3;
		x3 = q[h3]*5;
		x4 = q[h4]*7;
		if (x1 < x2 && x1 < x3 && x1 < x4)
		{
			q[++tail] = x1;
			h1++;
		}
		else if (x2 < x1 && x2 < x3 && x2 < x4)
		{
			q[++tail] = x2;
			h2++;
		}
		else if (x3 < x1 && x3 < x2 && x3 < x4)
		{
			q[++tail] = x3;
			h3++;
		}
		else if (x4 < x1 && x4 < x2 && x4 < x3)
		{
			q[++tail] = x4;
			h4++;
		}
		else if (x1==x2 && x1 < x3 && x1 < x4)
		{
			q[++tail] = x1;
			h1++;
			h2++;
		}
		else if (x1==x3 && x1 < x2 && x1 < x4)
		{
			q[++tail] = x1;
			h1++;
			h3++;
		}
		else if (x1==x4 && x1 < x2 && x1 < x3)
		{
			q[++tail] = x1;
			h1++;
			h4++;
		}
		else if (x2==x3 && x2 < x1 && x2 < x4)
		{
			q[++tail] = x2;
			h2++;
			h3++;
		}
		else if (x2==x4 && x2 < x1 && x2 < x3)
		{
			q[++tail] = x2;
			h2++;
			h4++;
		}
		else if (x3==x4 && x3 < x1 && x3 < x2)
		{
			q[++tail] = x3;
			h3++;
			h4++;
		}
		else if (x1==x2 && x2==x3 && x1 < x4)
		{
			q[++tail] = x1;
			h1++;
			h2++;
			h3++;
		}
		else if (x1==x2 && x2==x4 && x1 < x3)
		{
			q[++tail] = x1;
			h1++;
			h2++;
			h4++;
		}
		else if (x1==x3 && x3==x4 && x1 < x2)
		{
			q[++tail] = x1;
			h1++;
			h3++;
			h4++;
		}
		else if (x2==x3 && x3==x4 && x2 < x1)
		{
			q[++tail] = x2;
			h2++;
			h3++;
			h4++;
		}
		else
		{
			q[++tail] = x1;
			h1++;
			h2++;
			h3++;
			h4++;
		}
		if (tail==in.at(i))
		{
			if (tail%100==11 || tail%100==12 || tail%100==13)
			{
				cout << "The " << tail << "th humble number is " << q[tail] << "." << endl;
			}
			else if (tail%10==1)
			{
				cout << "The " << tail << "st humble number is " << q[tail] << "." << endl;
			}
			else if (tail%10==2)
			{
				cout << "The " << tail << "nd humble number is " << q[tail] << "." << endl;
			}
			else if (tail%10==3)
			{
				cout << "The " << tail << "rd humble number is " << q[tail] << "." << endl;
			}
			else
			{
				cout << "The " << tail << "th humble number is " << q[tail] << "." << endl;
			}
			i++;
		}
	}
	return 0;
}
