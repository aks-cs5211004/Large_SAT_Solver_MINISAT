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

vector<vector<int>> select(vector<vector<int>> adj,int i, int K1){
    vector<int> filtered=adj[i];
    for(auto j: adj[i]){
        if(adj[j].size()>=K1){
            filtered.push_back(j);
        }
    }

    vector<vector <vector<vector<int>> >> dp(filtered.size()+1,vector<vector<vector<int>>>(K1+1));
    vector<vector<int>> ans;
    ans=subset(filtered,K1,dp);
    return ans;
}

int main(){
    cin >> N >> E >> K1 >>K2;
    int ck1=0,ck2=0;
    vector <vector<int>> adj(N+1, vector<int>(0));
	edge curr;
    // Make adjacency list
	for(int i = 1 ; i <= E ; i++){
		cin >> curr.first >> curr.second;
		adj[curr.first].push_back(curr.second);
        adj[curr.second].push_back(curr.first);
        mapping[curr]=1;
	}
    // Print adj list
    // for(int i=1;i<=N;i++){  
    //     cout << i << " : ";
    //     for(auto j: adj[i]){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // Count number of clauses of each type
    for(int i=1; i<=N; i++){
        if(adj[i].size()>=K1-1){
            ck1+=select(adj,i,K1-1).size();
        }
        if(adj[i].size()>=K2-1){
            ck2+=select(adj,i,K2-1).size();
        }
    }

    int ne=0;
    for(int i=1;i<N;i++){
        // 3.For each not edge, 2 vertices should nt be in the same clique
        // 2*NC2 clauses
        // cout<<"C4"<<endl;
        for(int j=i+1;j<=N;j++){
            if(mapping.find({i,j})==mapping.end() && mapping.find({j,i})==mapping.end()){
                ne++;
            }
        }
    }

    int clauses = N +ck1+ck2+2*ne;
	int total_variables = 2*N;
	cout << "p cnf " << total_variables  << " " << clauses << endl;
    for(int i=1; i<=N; i++){
        
        // N clauses
        // 1.A vertex cannot be in 2 different cliques at the same time
        // cout<<"C1"<<endl;
        cout << "-" << i << " " << "-" <<i+N<<" 0" << endl;

        
        // 2. If atleast K1 of the neighbours of a vertex are in the clique 1, then the vertex should also be in the clique 1
        // ck1 clauses
        // cout<<"C2"<<endl;
        if(adj[i].size()>=K1-1){
            // P is K1-1 size subsets of adj[i]
            for(auto P: select(adj,i,K1-1))
                {
                    // iterate over each elemnet of the subset
                    // cout<<"size of subset"<<P.size()<<endl;
                    for(auto j: P){
                        cout <<"-" << j<<" ";  
                    }
                    for(auto j: adj[i]){
                        if(find(P.begin(),P.end(),j)==P.end())
                            cout <<j<<" ";  
                    }
                    cout <<"-" <<i<< " 0" << endl;
                }
        }

        // ck2 clauses
        // cout<<"C3"<<endl;
        if(adj[i].size()>=K2-1){
            // P is K1-1 size subsets of adj[i]
            for(auto P: select(adj,i,K2-1))
                {
                    // iterate over each elemnet of the subset
                    // cout<<"size of subset"<<P.size()<<endl;
                    for(auto j: P){
                        cout <<"-" << j+N<<" ";  
                    }
                    for(auto j: adj[i]){
                        if(find(P.begin(),P.end(),j)==P.end())
                            cout <<j+N<<" ";  
                    }
                    cout <<"-" <<i+N<< " 0" << endl;
                }
        }
    }

    for(int i=1;i<N;i++){
        // 3.For each not edge, 2 vertices should nt be in the same clique
        // 2*NC2 clauses
        // cout<<"C4"<<endl;
        for(int j=i+1;j<=N;j++){
            if(mapping.find({i,j})==mapping.end() && mapping.find({j,i})==mapping.end()){
                cout << "-" << i << " " << "-" <<j<<" 0" << endl;
                cout << "-" << i+N << " " << "-" <<j+N<<" 0" << endl;
            }

        }
    }
    // More constraints
    // cout<<"1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 0"<<endl;
    return 0;
}
