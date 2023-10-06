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
#include <string>
#define ll long long
#define r(i,a,b) for(int i=a;i<b;i++)
typedef pair<int, int> edge;
map <edge,int> mapping;
int N, E, K1;


int main(int argc, char** argv){
    cin >> N >> E;
    int K1=stoi(argv[1]);
    vector <vector<int>> adj(N+1, vector<int>(0));
	edge curr;
    // Make adjacency list
	for(int i = 1 ; i <= E ; i++){
		cin >> curr.first >> curr.second;
		adj[curr.first].push_back(curr.second);
        adj[curr.second].push_back(curr.first);
        mapping[curr]=1;
	}
    int ne=0;
    for(int i=1;i<=N;i++){
        // 3.For each not edge, 2 vertices should nt be in the same clique
        // ne clauses
        for(int j=i+1;j<=N;j++){
            if(mapping.find({i,j})==mapping.end() && mapping.find({j,i})==mapping.end()){
                ne++;
            }
        }
    }

    int clauses = ne+(2+4*(N-1)+4*(N-1)*(N-1)+1);
	int total_variables = N+N*N;
	cout << "p cnf " << total_variables  << " " << clauses << endl;

    // Clique 1
    // C1 ->2
    cout << "-" << 1 << " "<<1+2*N-N<<" 0" << endl;
    cout << "-" << 1+2*N-N<< " "<<1<<" 0" << endl;
    // C2 ->(N-1)
    for(int i=2; i<=N; i++){
        cout << "-"<<i+2*N-N<<" 0" << endl;
    }
    for(int i=2; i<=N; i++){
        // C3 ->3*(N-1)
        cout <<i<< " "<<1+(i)*N-N<<" "<<"-"<<1+(i+1)*N-N<<" 0" << endl;
        cout <<"-"<<i<< " "<<1+(i+1)*N-N<<" 0" << endl;
        cout <<"-"<<1+(i)*N-N<<" "<<1+(i+1)*N-N<<" 0" << endl;
        // cout << "-" <<1+(i)*N<< " "<<1+(1+i)*N<<" 0" << endl;
        for(int j=2; j<=N; j++){
            // C5 ->3*(N-1)*(N-1)
            // cout <<  "-" << i<<" "<< "-" << (j-1)+(i)*N<<" "<<j+(1+i)*N<<" 0" << endl;
            // cout <<  "-" << j+(1+i)*N<<" "<< i<<" 0" << endl;
            // cout <<  "-" << j+(1+i)*N<<" "<<(j-1)+(i)*N<<" 0" << endl;

            // C4-> 4*(N-1)(N-1)
            cout <<  "-" <<i<<" "<<"-"<<j+(1+i)*N-N<<" "<<(j-1)+(i)*N-N<<" 0" << endl;
            cout <<  "-" <<i<<" "<<"-"<<(j-1)+(i)*N-N<<" "<<j+(1+i)*N-N<<" 0" << endl;
            cout <<i<<" "<<"-"<<j+(i)*N-N<<" "<<j+(1+i)*N-N<<" 0" << endl;
            cout <<i<<" "<<"-"<<j+(i+1)*N-N<<" "<<j+(i)*N-N<<" 0" << endl;

            // cout << "-" << (j)+(i)*N<<" "<<j+(1+i)*N<<" 0" << endl;
        }
    }
    // C7 ->1
    for(int i=K1+1;i<=N;i++)
        cout<<"-"<<i+N*(N+1)-N<<" 0"<<endl;
    cout<<K1+N*(N+1)-N<<" 0"<<endl;

    for(int i=1;i<=N;i++){
        // 3.For each not edge, 2 vertices should nt be in the same clique
        // ne clauses
        for(int j=i+1;j<=N;j++){
            if(mapping.find({i,j})==mapping.end() && mapping.find({j,i})==mapping.end()){
                cout << "-" << i << " " << "-" <<j<<" 0" << endl;
            }
        }
    }
    return 0;
}
