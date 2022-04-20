class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
       
        if(nums1.size()>nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int n = nums1.size();
        int m = nums2.size();
        
        // Processing variables
        int start = 0;  
        int end = n;
        int MaxLeftX;
        int MaxLeftY;
        int MinRightX;
        int MinRightY;
        
        // BINARY SEARCH to find ideal partition.
        while(start<=end)
        {
            int partitionX = start + (end-start)/2;
            int partitionY = (n+m+1)/2 - partitionX;
            
            // Find MaxLeft and MinRight from nums1
            MaxLeftX = partitionX==0 ? INT_MIN : nums1[partitionX-1];
            MinRightX = partitionX==n ? INT_MAX : nums1[partitionX];
            MaxLeftY = partitionY==0 ? INT_MIN : nums2[partitionY-1];
            MinRightY = partitionY==m ? INT_MAX : nums2[partitionY];
            
            if(MaxLeftX > MinRightY)
            {
                end = partitionX-1; // GO LEFT
            }
            else if(MaxLeftY > MinRightX)
            {
                start = partitionX+1; // GO RIGHT
            }
            else
            {
                if((m+n)%2==0)
                {
                    return ((double)max(MaxLeftX, MaxLeftY) + (double)min(MinRightX, MinRightY))/2;
                }
                else{
                    return (double)max(MaxLeftX, MaxLeftY);
                }
            }
        }
        return double(-1);
    }
};