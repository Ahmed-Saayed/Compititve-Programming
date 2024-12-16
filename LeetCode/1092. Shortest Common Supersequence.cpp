string a,b;
int dp[(int)1e3+3][(int)1e3+3];
int rec(int i=0,int j=0){
    if(i==a.size()&&j==b.size())return 0;

    int&ret=dp[i][j];
    if(~ret)return ret;

    ret=1e9;

    if(i<a.size())
        ret=1+rec(i+1,j+(j<b.size()&&a[i]==b[j]));

    if(j<b.size())
        ret=min(ret,1+rec(i+(i<a.size()&&a[i]==b[j]),j+1));

    return ret;
}

string bul(int i=0,int j=0){
    if(i==a.size()&&j==b.size())return"";

    int best=rec(i,j);
    if(i<a.size()&&best==1+rec(i+1,j+(j<b.size()&&a[i]==b[j])))
        return a[i]+bul(i+1,j+(j<b.size()&&a[i]==b[j]));

    return b[j]+bul(i+(i<a.size()&&a[i]==b[j]),j+1);
}

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        a=str1,b=str2;

        for(int i=0;i<=a.size();i++)
            fill(dp[i],dp[i]+b.size()+1,-1);

        return bul();
    }
};