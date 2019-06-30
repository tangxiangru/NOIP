#include <queue> 
#include <vector> 
#include <iostream> 
#include <algorithm> 
using namespace std; 
int main() { //优先队列底层使用vector作为容器 
    priority_queue<int,vector<int>,greater<int>> heap;//小根堆 //数据 
    vector<int> nums; 
    int count; 
    cin>>count; 
    for(int i=0;i<count;i++) {
        int num; 
        cin>>num; 
        nums.push_back(num); 
    } 
    sort(nums.begin(),nums.end(),greater<int>()); 
    int max = nums[0]; //找出最大值作为标准 //假设有1-n个集合，尝试每种可能，取最小偏差和最小的集合个数
    int result = 0; 
    int min_Value = 0x7fffffff; //INT_MAX 
    for(int k=1;k<=count;k++) { 
        heap.push(nums[0]); //最大值入堆 //构造一个k个节点的小根堆的小根堆 
        int value = 0; 
        for(int i=1;i<k;i++) { 
            heap.push(0); 
        } // 分配数据 
        for(int i=1;i<count;i++) { 
            int min = heap.top(); 
            heap.pop(); 
            heap.push(min+nums[i]); 
        } // 计算偏差和 
        while(!heap.empty()) { // cout<<heap.top()<<" ";
            value+=abs(heap.top()-max); 
            heap.pop(); 
        } // cout<<endl; // 寻找偏差和最小的可能 
        if(value<=min_Value) { // cout<<value<<" "<<min_Value<<endl;
            min_Value = value; 
            result = k; 
        }
    } 
    cout<<result;
    return 0; 
}
