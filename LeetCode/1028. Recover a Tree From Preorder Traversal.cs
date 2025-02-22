 public class Solution
 {
     List<int> x, pre;
     void dfs(ref int i,ref int j,int lvl,TreeNode root)
     {
         if (i == x.Count) return;

        while(i!=x.Count&&lvl < pre[j]){
            TreeNode node = new TreeNode(x[i]);
            
            i++; j++;
            if (root.left == null)
                root.left = node;            
            else
                root.right = node;

            dfs(ref i, ref j, lvl + 1, node);
        }
     }
     public TreeNode RecoverFromPreorder(string traversal)
     {
         x = new List<int>();
         pre = new List<int>();
         string s = "";
         int c = 0;
         foreach (var k in traversal)
         {
             if (k == '-')
             {
                 if (s.Length != 0)
                     x.Add(int.Parse(s));
                 s = "";
                 c++;
             }
             else
             {
                 if (c != 0)
                     pre.Add(c);

                 c = 0;
                 s += k;
             }
         }

         x.Add(int.Parse(s));

         TreeNode root=new TreeNode(x[0]);
         int i = 1, j = 0;
      

         dfs(ref i, ref j, 0, root);

         return root;
     }

 }