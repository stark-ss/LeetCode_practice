class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int area=0;
        int l=0,h=n-1;
        while(l<h){
            int len=min(height[l],height[h]);
            area=max(area,len*(h-l));
            if(height[l]<height[h])
            l++;
            else
            h--;
        }
        return area;
        
    }
};