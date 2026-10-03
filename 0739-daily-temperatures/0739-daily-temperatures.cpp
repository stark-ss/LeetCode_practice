class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> res(n,0);
        stack<int> dif;
        for(int i=0;i<n;i++){
            if(!dif.empty() && temperatures[dif.top()]<temperatures[i]){
             while(!dif.empty() && temperatures[dif.top()]<temperatures[i]){
                res[dif.top()]=i-dif.top();
                dif.pop();
             }
            }
            dif.push(i);
        }
        return res;
    }
};