#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getNext(string &sl, string &ss, int i, int j, vector<int> &next){
    if(j == ss.length()) return;
    
    if(-1 == i || sl[i] == ss[j]){
        next.push_back(i+1);
        getNext(sl, ss, next.back(), j+1, next);
    }
    else
        getNext(sl, ss, next[i], j, next);
}

void countSubString(string &sl, string &ss, int i, int j, vector<int> &next, int *count){
    if(j == ss.length()) (*count)++;
    if(i == sl.length()) return;
    
    if(j != ss.length() && (-1 == j || sl[i] == ss[j]))
        countSubString(sl, ss, i+1, j+1, next, count);
    else
        countSubString(sl, ss, i, next[j], next, count);

}

int main(){
    
    int n;
    string str1, str2;
    
    cin>>n;
    while(n--){
        cin>>str1>>str2;
        
        vector<int> next(1, -1);
        int count = 0;
        
        getNext(str1, str1, -1, 0, next);
        countSubString(str2, str1, 0, 0, next, &count);
        cout<<count<<endl;
    }
    
    
    return 0;
}