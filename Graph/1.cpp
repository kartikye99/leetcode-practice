// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
#include <iostream>

using namespace std;
int main() {
    int n ; // number of vertics
    int m ; // number of edges;
    cout<<"Enter the number of vertices";
    cin>>n;
    cout<<"Enter the number of edges";
    cin>>m;
    
    unordered_map<int,list<int>>adjlist;
    cout<<"Enter edges (U,V)"<<endl;
    
    for(int i = 0 ; i<m;i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u); // only for undirected graph
    }
    
cout<<"Adj LIST is: "<<endl;
for(auto i : adjlist){
    cout<<i.first<<"->";
    for(auto j :i.second){
        cout<< j <<" ";
    }
    cout<<endl;
}
    return 0;
}