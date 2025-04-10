using ll = System.Int64;
public class Solution
{
    string s="", t="", o="";
    ll lmt;
    ll[,,] dp = new ll[17, 2, 2];
    ll rec(ll i = 0, ll f1 = 0, ll f2 = 0)
    {
        if (i == s.Length)
            return 1;

        ref ll ret = ref dp[i, f1, f2];
        if (ret != -1)
            return ret;

        ret = 0;
        int mn = (f1 == 0 ? s[((int)i)] - '0' : 0),
            mx = (f2 == 0 ? t[((int)i)] - '0' : 9);

        for (int j = mn; j <= Math.Min(lmt, mx); j++)
        {
            if (i >= s.Length - o.Length)
            {
                if (j == o[((int)i) - (s.Length - o.Length)] - '0')
                    ret += rec(i + 1, (f1 == 0 && j == mn) ? 0 : 1, (f2 == 0 && j == mx) ? 0 : 1);
            }
            else
                ret += rec(i + 1, (f1 == 0 && j == mn) ? 0 : 1, (f2 == 0 && j == mx) ? 0 : 1);
        }

        return ret;
    }
    public long NumberOfPowerfulInt(long start, long finish, int limit, string ss)
    {
        s = start.ToString();
        t = finish.ToString();
        o = ss;
        lmt = limit;

        s = new string('0', t.Length - s.Length) + s;

        System.Runtime.InteropServices.MemoryMarshal.CreateSpan(ref dp[0, 0, 0], dp.Length).Fill(-1);

        return rec();
    }
}