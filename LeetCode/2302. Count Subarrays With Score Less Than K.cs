public class Solution
{
    public long CountSubarrays(int[] nums, long k)
    {
        long ans = 0;

        List<long> x = [];
        x.Add(0);

        foreach (var i in nums)
            x.Add(i);

        for (int i = 1; i < x.Count; i++)
            x[i] += x[i - 1];

        for(int i = 1; i < x.Count; i++)
        {
            int l = i, r = x.Count - 1, m;
            while(l <= r)
            {
                m = l + r >> 1;
                if ((x[m] - x[i - 1]) * (m - i + 1) < k)
                    l = m + 1;
                else
                    r = m - 1;
            }

            ans += r - i + 1;
            Console.WriteLine(r);
        }
        return ans;
    }
}