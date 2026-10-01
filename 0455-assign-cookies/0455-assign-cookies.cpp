class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(),m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        if(m==0) return 0;
        int i=0,j=0;
        int c=0;
        while(i<n && j<m){
            if(s[j]>=g[i]){
              c++;
              i++;
              j++;
            }
            else{
                j++;
            }

        }
        return c;
    }
};