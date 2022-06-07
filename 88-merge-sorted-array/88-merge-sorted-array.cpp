class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        //pointer of arr1
        int p=m-1;
        
        //pointer for arr2
        int q=n-1;
        
        //pointer for resultant arr
        int l=m+n-1;
        
        //loop to traverse till last index or less
        while(p>=0 && q>=0)
        {
            if(nums1[p] >= nums2[q])
            {
                //goto nums of L and assign value of P and update the pointer
                nums1[l--] = nums1[p--];
            }
            else
            {
                //goto nums of L and assign value of Q and update the pointer
                nums1[l--] = nums2[q--];
            }
        }
            
            while(p>=0)
            {
                nums1[l--]=nums1[p--];
            }
            
            while(q>=0)
            {
                nums1[l--]=nums2[q--];
            }
        
            
            
        
    }
};