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
    if(wt!="SAT"){
        cout<<0<<endl;
    }
    else{
    vector<int> c1;
    vector<int> c2;

    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        if(x>0 && i<N){
            c1.push_back(x);
    }
    }
    cout<<"#"<<1<<endl;
    
    for(int i=0;i<c1.size()-1;i++){
        cout<<c1[i]<<" ";
    }
    cout<<c1[c1.size()-1];
    }

}
