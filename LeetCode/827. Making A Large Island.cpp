
        public class Solution
        {
            List<int> dx = new List<int> { 1, -1, 0, 0 };
            List<int> dy = new List<int> { 0, 0, 1, -1 };
            List<List<int>> vis, grd;
            List<int> sz;
            int id,n,m;
            
            bool Ok(int i, int j) => (Math.Min(i, j) >= 0 &&i<n&&j<m);

            void dfs(int i,int j)
            {
            
                vis[i][j] = id;
                sz[id]++;

                for(int k = 0; k < 4; k++)
                {
                    int a = i + dx[k], b = dy[k] + j;
                    if (Ok(a, b) && vis[a][b] == 0 && grd[a][b] == 1)
                        dfs(a, b);
                }
            }
            public int LargestIsland(int[][] grid)
            {
                 n = grid.Length;
                 m = grid[0].Length;
                 id = 0;

                vis = new List<List<int>>();
                grd = new List<List<int>>();
                sz = new List<int>(new int[n*m+5]);


                for (int i = 0; i < n; i++)
                {
                    vis.Add(new List<int>(new int[m]));
                    grd.Add(new List<int>(grid[i].ToList()));
                }

                

                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++)
                        if (grid[i][j] == 1 && vis[i][j] == 0)
                        {
                            id++;
                            dfs(i, j);
                        }

                int ans = 0;
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++)
                        if (grid[i][j] == 0)
                        {
                            SortedSet<int> st = new SortedSet<int>();
                            for (int k = 0; k < 4; k++)
                            {
                                int a = i + dx[k], b = dy[k] + j;
                                if (Ok(a, b))
                                {
                                    st.Add(vis[a][b]);
                                }    
                            }

                            int sm = 0;
                            foreach (var o in st)
                                sm += sz[o];

                            ans = Math.Max(ans, sm + 1);
                        }
                        else
                        {
                            ans = Math.Max(ans, sz[vis[i][j]]);
                        }

                return ans;
            }
        }