class Solution {
public:
    int m, n;
    // int dir[8][2] = {-1,0, -1,1, 0,1, 1,1, 1,0, 1,-1, 0,-1, -1,-1};
    int dir[4][2] = {-1,0, 0,1, 1,0, 0,-1};
    // vector<vector<int>> vis;
    int vis[1000][1000];
    void dfs(int xx, int yy, vector<vector<char>>& grid){
        vis[xx][yy] = 1;
        for(int i=0;i<4;i++){
            int next_xx = xx + dir[i][0];
            int next_yy = yy + dir[i][1];
            if(0<=next_xx && next_xx <m && 0<=next_yy && next_yy<n){
                if(vis[next_xx][next_yy]==0 && grid[next_xx][next_yy]=='1')
                    dfs(next_xx, next_yy, grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)
            return 0;
        
        m = grid.size();
        n = grid[0].size();
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && vis[i][j]==0){
                    dfs(i, j, grid);
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};