#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>vc;
int main()
{
	int k;
	cin>>k;
	while(k--)
	{
		int num;
		cin>>num;
		vc.push_back(num);
	}
	sort(vc.begin(), vc.end());
	int dis = vc[vc.size()-1]-vc[0];
	cout<<dis<<endl;
	return 0;
}
