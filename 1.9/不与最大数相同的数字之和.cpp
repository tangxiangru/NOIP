#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
	vector<int> vc;
	int maxC=-1000001,k,result=0;
	cin>>k;
	while(k--)
	{
		int num;
		cin>>num;
		if(maxC<num) maxC=num;
		vc.push_back(num);
	}
	for(int i=0;i<vc.size();i++)
	{
		if(vc[i]!=maxC)	result+=vc[i];
	}
	cout<<result;
	return 0;
}


