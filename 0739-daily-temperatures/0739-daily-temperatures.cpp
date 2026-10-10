class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> res(n,0);
        stack<int> q;
        for(int i=0;i<n;i++){
            while(!q.empty() && temperatures[i]>temperatures[q.top()]){
                res[q.top()]=i-q.top();
                q.pop();
            }
            q.push(i);
        }
        return res;
    }
};