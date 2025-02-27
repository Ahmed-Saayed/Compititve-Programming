#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--) {
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=2e5+5;
vector<int>adj[N];
int ans;
struct Centroid_Decomposition{

    vector<int>Sz,Is_Removed;
    vector<vector<pair<int, int>>> Centroids;

    Centroid_Decomposition(int n){
        Sz=Is_Removed=vector<int>(n+1);
        Centroids=vector<vector<pair<int,int>>>(n+1);
        Build_Centroid();
    }

    int Get_SubTreeSz(int node, int par = -1) {
        if(ans)return 0;
        Sz[node] = 1;
        for (int i : adj[node]) {
            if(i == par || Is_Removed[i])continue;

            Sz[node] += Get_SubTreeSz(i, node);
        }

        return Sz[node];
    }

    int Get_Centroid(int node, int TreeSize, int par = -1) {
        if(ans)return 0;
        for (int i : adj[node]) {
            if(i == par || Is_Removed[i])continue;

            if(Sz[i] * 2 > TreeSize)
                return Get_Centroid(i, TreeSize, node);
        }

        return node;
    }

    void Get_Dis(int node, int centroid, int par = -1, int dis = 1) {
        if(ans)return;
        for (int i : adj[node]) {
            if(i == par || Is_Removed[i])continue;

            dis++,
            Get_Dis(i, centroid, node, dis),
            dis--;
        }

        Centroids[node].push_back({centroid, dis});
    }

    void Build_Centroid(int node = 1) {
        int centroid = Get_Centroid(node, Get_SubTreeSz(node));

        if(!ans)ans=centroid;
        if(ans)return;

        for (int i : adj[centroid]) {
            if(Is_Removed[i])continue;

            Get_Dis(i, centroid, centroid);
        }

        Is_Removed[centroid] = 1;
        for (int i : adj[centroid]) {
            if(Is_Removed[i])continue;

            Build_Centroid(i);
        }
    }
};

int main()
{
Ahmed_Sayed();
int n;cin>>n;
for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}

Centroid_Decomposition op(n);
cout<<ans;
}
