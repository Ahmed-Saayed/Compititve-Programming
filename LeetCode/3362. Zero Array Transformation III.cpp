#define ll long long
class Solution {
public:
    int v[(ll)1e5+5];

    struct st{
        int mx,lazy;
    };
    
    st seg[(ll)5e5];

    void push(int node,int l,int r){
        seg[node].mx+=seg[node].lazy;

        if(l!=r){
            seg[node*2].lazy+=seg[node].lazy,
            seg[node*2+1].lazy+=seg[node].lazy;
        }
        seg[node].lazy=0;
    }

    void bul(int node,int l,int r){
        if(l==r){
            seg[node].mx=v[l];
            return;
        }

        int m=(l+r)>>1;
        bul(node*2,l,m),
        bul(node*2+1,m+1,r);

        seg[node].mx=max(seg[node*2].mx,seg[node*2+1].mx);
    }

      int get(int node,int l,int r,int lef,int righ){
        push(node,l,r);
          
        if(l>righ||r<lef)return -1e9;
        if(l>=lef&&r<=righ)return seg[node].mx;

        int m=(l+r)>>1;
        return max(get(node*2,l,m,lef,righ),get(node*2+1,m+1,r,lef,righ));
      }

     void up(int node,int l,int r,int lef,int righ){
        push(node,l,r);
        
        if(l>righ||r<lef)return;
        if(l>=lef&&r<=righ){
            seg[node].lazy++,
            push(node,l,r);
            
            return;
        }

        int m=(l+r)>>1;
        up(node*2,l,m,lef,righ),
        up(node*2+1,m+1,r,lef,righ);

        seg[node].mx=max(seg[node*2].mx,seg[node*2+1].mx);
      }


    int maxRemoval(vector<int>& x, vector<vector<int>>& q) {
        x.insert(x.begin()+0,0);

        int n=x.size()-1;
        vector<ll>pre(n+5);

        for(auto i:q)
            pre[i[0]+1]--,pre[i[1]+2]++;
        
        for(int i=1;i<=n;i++){
            pre[i]+=pre[i-1],
            x[i]+=pre[i];
            
            if(x[i]>0)return -1;
        }

        for(int i=0;i<x.size();i++)v[i]=x[i];
        bul(1,1,n);
    
        vector<array<ll,3>>qq;
        for(auto i:q){
            qq.push_back({abs(i[0]-i[1]),i[0],i[1]});
        }

        sort(qq.begin(),qq.end());
        int ans=0;
        for(auto i:qq)
            if(get(1,1,n,i[1]+1,i[2]+1)<0){
                up(1,1,n,i[1]+1,i[2]+1);
                ans++;
            }

        return ans;
    }
};