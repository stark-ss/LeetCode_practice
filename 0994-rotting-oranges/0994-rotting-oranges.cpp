class Solution {
public:
    int rotten(queue<vector<int>>& q,vector<vector<int>>& g,int& m,int& n,int& orange){
        int time=0;

        while(!q.empty()){
            vector<int> cur=q.front();
            int i=cur[0];
            int j=cur[1];
            int t=cur[2];
            q.pop();
            time=max(time,t);
            int r[]={-1,0,1,0};
            int c[]={0,1,0,-1};
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
        queue<vector<int>> q;
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