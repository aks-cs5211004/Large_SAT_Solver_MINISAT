#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#include <set>
#define vi vector <int>
#define pii pair<int,int>
#define vii vector<pii>
#define ff first
#define ss second  
#define ll long long
#define r(i,a,b) for(int i=a;i<b;i++)
typedef pair<int, int> edge;
map <edge,int> mapping;
int N, E, K1, K2;

vector<vector<int>> subset(vector<int> adj_i,int K1,vector<vector <vector<vector<int>> >>& dp){
    if(K1==0){
       return {{}};
    }
    if(K1>adj_i.size()){
        return {{}};
    }
    if(K1==adj_i.size()){
        return {adj_i};
    }
    vector<vector<int>> subset1,subset2;
    vector<int> new_adj_i(adj_i.begin(),adj_i.end()-1);

    if(dp[new_adj_i.size()][K1-1].size()!=0){
        subset1=dp[new_adj_i.size()][K1-1];
    }
    else{
        subset1=subset(new_adj_i,K1-1,dp);
    }

    for(int i=0;i<subset1.size();i++){
        subset1[i].push_back(adj_i[adj_i.size()-1]);
    }

    if(dp[new_adj_i.size()][K1].size()!=0){
        subset2=dp[new_adj_i.size()][K1];
    }
    else{
        subset2=subset(new_adj_i,K1,dp);
    }

    subset2.insert(subset2.begin(), subset1.begin(), subset1.end());
    return dp[adj_i.size()][K1]=subset2;
}

int main(){


    vector<vector<int>> ans;
    vector<int> adj_i={23,21,31,41,51,61,100};
    int K1=3;
    vector<vector <vector<vector<int>> >> dp(adj_i.size()+1,vector<vector<vector<int>>>(K1+1));
    ans=subset(adj_i,K1,dp);
    // print the subsets
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;

    }
}