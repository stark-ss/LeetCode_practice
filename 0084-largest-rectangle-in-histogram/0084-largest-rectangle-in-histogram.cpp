class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> temp;
        int h=0;
        int a=0;
        for(int i=0;i<=n;i++){
         int ch=(i==n)?0:heights[i];
         if(!temp.empty() && heights[temp.top()]>ch){
          while(!temp.empty() && heights[temp.top()]>ch){
            h=heights[temp.top()];
            temp.pop();
            int l=(temp.empty())?-1:temp.top();
            a=max(a,h*(i-l-1));
          }
          
    
         } 
         temp.push(i);
        }
        return a;
    }
};