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


int main(int argc, char** argv){
    int N=stoi(argv[1]);
    string wt;
    cin>>wt;
    vector<int> c1;
    vector<int> c2;

    for(int i=0;i<2*N;i++){
        int x;
        cin>>x;
        if(x>0 && i<N){
            c1.push_back(x);
        }
        else if(x>0 && i<2*N){
            c2.push_back(x);
        }
    }
    cout<<"#1"<<endl;
    for(int i=0;i<c1.size();i++){
        cout<<c1[i]<<" ";
    }
    cout<<endl;

    cout<<"#2"<<endl;
    for(int i=0;i<c2.size();i++){
        cout<<c2[i]<<" ";
    }
    cout<<endl;


}
