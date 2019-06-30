#include <iostream>
#include <vector>
#include <cfloat>
#include <math.h>
#include <iomanip>
#include <algorithm>
using namespace std;
/*
注意考虑情况，10 10 20 20 20这种只有多个最大最小值的情况
*/
int main()
{
	vector<double> vc;
	double sum=0;
	int k;
	cin>>k;
	while(k--)
	{
		double num;
		cin>>num;
		vc.push_back(num);
	}
	sort(vc.begin(),vc.end());
	for(int i=1;i<vc.size()-1;i++)
	{
		sum+=vc[i];
	}
	float average = sum/(vc.size()-2);
	float maxD = 0;
	for(int i=1;i<vc.size()-1;i++)
	{
		
		if(maxD<fabs(vc[i]-average)) maxD =fabs(vc[i]-average);
	}
	cout<<fixed<<setprecision(2)<<average<<" ";
	cout<<maxD<<endl;
	return 0;
}

