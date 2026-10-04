class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<int> s;
        vector<int> pos(n,0);
        for(int i=0;i<=n;i++){
            int curr=(i==n)?'0':num[i];
            if(!s.empty() && k>0 && curr<num[s.top()]){
                while(!s.empty() && k>0 && curr<num[s.top()]){
                   pos[s.top()]=1;
                   k--;
                   s.pop();
                }
            }
            s.push(i);
        }
        string res="";
        for(int i=0;i<n;i++){
            if(pos[i]==1)
            continue;
            if(res.empty() && num[i]=='0')
            continue;
            else
            res+=num[i];

        }
        return (res.empty())?"0":res;
    }
};