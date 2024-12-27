public class Solution {
    public int MaxEqualRowsAfterFlips(int[][] x) {
        
    Dictionary<string, int> mp=new Dictionary<string, int>();

    foreach(var i in x)
    {
        string zero="",one="";

          for (int j = 0; j < i.Length; j++)
           {
              if (i[j] == 0) zero+=j;
              else one+= j;
          }

            if(!mp.ContainsKey(zero)) mp.Add(zero, 0);              
            if(!mp.ContainsKey(one)) mp.Add(one, 0);

           mp[one]++;
           mp[zero]++;
       }

         int ans = 0;
          foreach (var i in mp)
               ans = Math.Max(ans, i.Value);

          return ans;
    }
}