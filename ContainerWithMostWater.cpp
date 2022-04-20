class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0;
        int right = height.size()-1;
        
        int max_water=0;
        while(left < right)
        {
            int l1 = height[left];
            int l2 = height[right];
            int final_height = min(l1,l2);
            int sum = final_height*(right-left);
            max_water = max(sum, max_water);
            if(l1>=l2)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return max_water;
    }
};