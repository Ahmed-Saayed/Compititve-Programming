class Solution {
    public int maxEqualRowsAfterFlips(int[][] x) {
        HashMap<String, Integer> mp=new HashMap<String, Integer>();

    for(var i : x)
    {
        String zero="",one="";

          for (int j = 0; j < i.length; j++)
           {
              if (i[j] == 0) zero+=j;
              else one+= j;
          }

            if(!mp.containsKey(zero)) mp.put(zero, 0);              
            if(!mp.containsKey(one)) mp.put(one, 0);

         int currentCount = mp.getOrDefault(one, 0);
         int currentCount2 = mp.getOrDefault(zero, 0);
           mp.put(one, currentCount + 1);
           mp.put(zero, currentCount2 + 1);
       }

         int ans = 0;
          for (var i :  mp.values())
               ans =  Math.max(ans, i);

          return ans;
    }
}