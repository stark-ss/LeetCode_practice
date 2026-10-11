class Solution {
public:
    bool check(int i,int j,vector<vector<char>>& b,string& w,bool& res,int k,vector<vector<bool>>& v){
        if(k==w.size()) return true;
         if(i<0 || i>=b.size() || j<0 || j>=b[0].size() || v[i][j] || b[i][j]!=w[k])
         return false;
         
         v[i][j]=true;
         res=check(i,j+1,b,w,res,k+1,v) || check(i+1,j,b,w,res,k+1,v) || check(i,j-1,b,w,res,k+1,v) || check(i-1,j,b,w,res,k+1,v);
          v[i][j]=false;

    
        return res;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        bool res=false;
        vector<vector<bool>> visit(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(board[i][j]==word[0]){
                 if(check(i,j,board,word,res,0,visit)) return true;
                 }
            }
        }
        return false;
    }
};