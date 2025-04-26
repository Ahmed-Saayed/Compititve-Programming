using ll = System.Int64;

public class Solution
{
    public long CountSubarrays(int[] nums, int minK, int maxK)
    {
        List<int> x = [];
        x.Add(0);
        foreach (int i in nums)
            x.Add(i);

        int n = nums.Length;
        List<int> premx = Enumerable.Repeat(0, n + 5).ToList();
        List<int> premn = Enumerable.Repeat(0, n + 5).ToList();

        List<int> s = [];
        s.Add(n + 1);

        for (int i = 1; i <= n; i++)
        {
            premx[i] = ((x[i] == maxK) ? 1 : 0) + premx[i - 1];
            premn[i] = ((x[i] == minK) ? 1 : 0) + premn[i - 1];

            if (!(x[i] >= minK && x[i] <= maxK))
                s.Add(i);
        }

        s.Sort();

        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!(x[i] >= minK && x[i] <= maxK))
                continue;

            int le = 0, ri = s.Count - 1, md;
            while (le <= ri)
            {
                md = le + ri >> 1;

                if (s[md] <= i)
                    le = md + 1;
                else
                    ri = md - 1;
            }

            int it = s[le];
        
            if (x[i] == minK)
            {
                int l = i, r = it - 1, m;
                while (l <= r)
                {
                    m = l + r >> 1;

                    if (premx[m] - premx[i - 1] != 0)
                        r = m - 1;
                    else
                        l = m + 1;
                }
                
                if (l != it)
                    ans += it - l;
            }
            else if (x[i] == maxK)
            {
                int l = i, r = it - 1, m;
                while (l <= r)
                {
                    m = l + r >> 1;

                    if (premn[m] - premn[i - 1] != 0)
                        r = m - 1;
                    else
                        l = m + 1;
                }

                if (l != it)
                    ans += it - l;
            }
            else
            {
                int l = i, r = it - 1, m;
                while (l <= r)
                {
                    m = l + r >> 1;

                    if (premn[m] - premn[i - 1] != 0)
                        r = m - 1;
                    else
                        l = m + 1;
                }

                int l2 = i, r2 = it - 1, m2;
                while (l2 <= r2)
                {
                    m2 = l2 + r2 >> 1;

                    if (premx[m2] - premx[i - 1] != 0)
                        r2 = m2 - 1;
                    else
                        l2 = m2 + 1;
                }

                if (l2 != it && l != it)
                    ans += it - Math.Max(l, l2);
            }
        }

        return ans;

    }
}