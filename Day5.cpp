/*
An element is considered a leader if it is greater than all the elements to its right
*/
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
  
vector<int> findLeaders(const vector<int>&arr){
    int n=arr.size();
    vector<int> leaders;
    int maxRight=arr[n-1];
    leaders.push_back(maxRight);

    for(int i=n-2; i>=0;--i){
        if(arr[i]>maxRight){
        maxRight=arr[i];
        leaders.push_back(maxRight);
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
    
}
int main(){
    vector<int>arr={16,17,4,3,5,2};
    vector<int>leaders=findLeaders(arr);
    
    cout<<"leaders:";
    for(int num: leaders){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}

