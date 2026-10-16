class Solution {
public:
    int rotten(queue<array<int,3>>& q,vector<vector<int>>& g,int& m,int& n,int& orange){
        int time=0;
        int r[]={-1,0,1,0};
        int c[]={0,1,0,-1};

        while(!q.empty()){
           auto[i,j,t]=q.front();

            q.pop();
            time=max(time,t);
            for(int k=0;k<4;k++){
                int row=i+r[k];
                int col=j+c[k];
                if(row>=0 && row<m && col>=0 && col<n && g[row][col]==1){
                    g[row][col]=2;
                    orange--;
                    q.push({row,col,t+1});
                }
            }
        }
        return time;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<array<int,3>> q;
        int orange=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                q.push({i,j,0});
                else if(grid[i][j]==1)
                orange++;
            }
        }
      
      int res= rotten(q,grid,m,n,orange);
      if(orange>0) return -1;
      else return res;
    }
};