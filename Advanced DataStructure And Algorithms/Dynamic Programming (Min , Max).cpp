const int N = 500;
string s;
int dp[N][N];
int rec(int i = 0, int j = s.size() - 1){		//1312. Minimum Insertion Steps to Make a String Palindrome
    if(i >= j)return 0;

    int & ret = dp[i][j];
    if(~ret)return ret;

    if(s[i] == s[j])
        return ret = rec(i + 1, j - 1);

    return ret = 1 + min(rec(i + 1, j), rec(i, j - 1));
}
class Solution {
public:
    int minInsertions(string t) {
        s = t;
        for(int i = 0; i < s.size() ;i++)
            fill(dp[i], dp[i] + s.size(), -1);

        return rec();
    }
};