class Solution {
public:
    int maxArea(vector<int>& height) {
        int tail=0, head=height.size()-1;
        int ans=0, area;
        while(tail<head){
            area=max(area, abs(head-tail)*min(height[tail], height[head]));
            ans=max(ans, area);

            if (height[tail]<height[head]){
                tail++;
            } else {
                head--;
            }
        }

        return ans;
    }
};