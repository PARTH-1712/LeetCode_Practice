class Solution {
public:
    string largestOddNumber(string nums) {
        int n = nums.size() ; 
        int flag = 0 ; 
        int ind = 0 ; 
        for(int i = n ; i>=0 ; i--){
            if(nums[i] %2){
                flag = 1 ; 
                ind = i ; 
                break ; 
            }
        }
        if(flag==0) return "" ; 
        string ans ; 
        for(int i = 0 ; i<=ind ; i++){
            ans+=nums[i] ; 
        }
        return ans ; 
    }
};