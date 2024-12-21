const int N=1e5+1;
int seg[N*4];
void bul(int node,int l,int r,vector<vector<int>>& points){
    if(l==r){
        seg[node]=points[l][0]+points[l][1];
        return;
    }

    int m=l+r>>1;
    bul(node*2,l,m,points),
    bul(node*2+1,m+1,r,points);

    seg[node]=max(seg[node*2],seg[node*2+1]);
}

int get(int node,int l,int r,int lef,int righ){
    if(l>righ||r<lef)return INT_MIN;
    if(l>=lef&&r<=righ)return seg[node];

    int m=l+r>>1;
    return max(get(node*2,l,m,lef,righ),get(node*2+1,m+1,r,lef,righ));
}

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n=points.size(),ans=INT_MIN;
        fill(seg,seg+n*4+1,INT_MIN);
        points.insert(points.begin()+0,{0,0});
       
        bul(1,1,n,points);

        for(int i=1;i<=n;i++){
            int l=i+1,r=n,m;
            while(l<=r){
                m=l+r>>1;

                (points[m][0]-points[i][0]>k?r=m-1:l=m+1);
            }

            if(r>i)
                ans=max(ans,points[i][1]+get(1,1,n,i+1,r)-points[i][0]);
        }

        return ans;
    }
};