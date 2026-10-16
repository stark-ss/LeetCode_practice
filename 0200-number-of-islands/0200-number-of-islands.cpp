class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>& g,int& m,int& n){
        queue<pair<int,int>> q;
        g[i][j]='a';
        q.push({i,j});
        vector<int> r={-1,0,1,0};
        vector<int> c={0,1,0,-1};
        while(!q.empty()){
            auto[rr,cc]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int row=rr+r[k];
                int col=cc+c[k];
                if(row>=0 && row<m && col>=0 && col<n && g[row][col]=='1'){
                    q.push({row,col});
                    g[row][col]='a';
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                 count++;
                 bfs(i,j,grid,m,n);
                }
            }
        }
        return count;
    }
};