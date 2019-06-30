#include <iostream>
#include <vector>
#include <cfloat>
#include <math.h>
#include <iomanip>
#include <algorithm>
using namespace std;
 
int main()
{
	int k;
	cin>>k;
	std::vector<int> vc;
	while(k--)
	{
		int num;
		cin>>num;
		vc.push_back(num);
	}
	sort(vc.begin(),vc.end());
	int count[vc[vc.size()-1]+1]={0}; //从0开始
	for(int i=0;i<vc.size();i++)
	{
		count[vc[i]]++;
	}
	for(int i=0;i<vc[vc.size()-1]+1;i++)
		cout<<count[i]<<endl;
	return 0;
}
