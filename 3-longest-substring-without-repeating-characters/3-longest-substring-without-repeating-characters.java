class Solution {
    public int lengthOfLongestSubstring(String s) 
    {
        //two pointers to solve using sliding window technique
        int left=0, right=0;
        
        //check the duplicate characters 
        Set <Character> seen= new HashSet();
        
        //we will use it to store the the longest compared window
        int max=0;
        
        //it will move till we have not processed all character 
        //in right side of string
        while (right<s.length())
        {
            //adding character
            char c=s.charAt(right);
            
            //if characters are added to set
            //we have a valid window
            if(seen.add(c))
            {
                //window size is compared with stored window in max variable
                //and updated if we get new
                max=Math.max(max,right-left+1);
                right++;
            }
            else
            {
                //if character is not added to the set
                //while will run till the character is not removed
                while(s.charAt(left)!=c)
                {
                    //remove the character form the set 
                    //and move the left pointer
                    seen.remove(s.charAt(left));
                    left++;
                }
                //remove the duplicate character and move left pointer
                seen.remove(c);
                left++;
            }
        }
        return max;
        
    }
};