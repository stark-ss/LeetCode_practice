class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
         stack<int> s;
         int vol=0,h=0;
         for(int i=0;i<n;i++){
          
            while(!s.empty() && height[s.top()]<height[i]){
            int b=s.top();
            s.pop();
            if(s.empty()) continue;
            int l=s.top();
            int walls=min(height[l],height[i]);
            vol+=(i-l-1)*(walls-height[b]);
            }

            if(s.empty() && height[i]==0){

            continue;
            }
            s.push(i);
         }

         return vol;
    }
};