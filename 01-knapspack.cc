#include <iostream>

using namespace std;

inline int max2(int a, int b){
    return (a>b)?a:b;
}

int main(){
    
    int need[505] = {0}, value[505] = {0}, dp[100005] = {0};
    int n, m, max=0;
    cin>>n>>m;
    
    for(int i = 0; i < n; ++i){
        cin>>need[i]>>value[i];
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = m; j >= need[i]; --j){
            dp[j] = max2(dp[j], dp[j-need[i]]+value[i]);
        }
    }
    
    for(int i = 0; i <= m; ++i){
        max = max2(max, dp[i]);
    }
    
    cout<<max<<endl;
    
    return 0;
}