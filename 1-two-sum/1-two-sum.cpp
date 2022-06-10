class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        //created a hashmap
          unordered_map<int,int> map;
        
        //created a vector to store our answer
          vector<int> result;
        
        //now we will traverse our array
        for(int i=0;i<nums.size();i++)
        {
            //we will subtract our current number with target
            //9-2=7
            int currelement=target-nums[i];
            
            //now go to hashmap to search our number
            //check the currelement index 
            //ki dobara to nahi check kar rhee
            if(map.find(currelement)!=map.end() && i!=map[currelement])
            {
                //we will begin from the start and go to the end of the hashmap.
                //if we find out element 
                //we are storing the second element in hashmap
                result.push_back(map[currelement]);
                
                //now we store position index of currelement 
                result.push_back(i);
                break;
            }
            else
            {
                //since the elment is not present we will add it to hasmap
                //with [2(value),0(key)]  [7,1] 
                map[nums[i]]=i;
            }
        }
               //at last return our result 
                return result;
    }
};