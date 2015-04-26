#include <iostream>

using namespace std;

inline int max2(int a, int b){
    return (a > b)?a:b;
}

int main(){
    
    int dp[101][101] = {0};
    int n, max = 0;
    
    cin>>n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            cin>>dp[i][j];
            dp[i][j] += max2(dp[i-1][j], dp[i-1][j-1]);
        }
    }
    
    for(int i = 1; i <= n; ++i){
        if(max < dp[n][i]) max = dp[n][i];
    }
    
    cout<<max<<endl;
    
    return 0;
}