class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> s;
        int n=arr.size();
        long long a=pow(10,9)+7;
        long long res=0;
        for(int i=0;i<=n;i++){
            int curr=(i==n)?0:arr[i];
            if(!s.empty() && arr[s.top()]>=curr){
                while(!s.empty() && arr[s.top()]>=curr){
                int num=arr[s.top()];
                int in=s.top();
                s.pop();
                int l=(s.empty())?-1:s.top();
                int r=i-in;
                res=(res+1ll*num*(in-l)*r)%a;
                }
            }
            s.push(i);
        }
        return res;
    }
};