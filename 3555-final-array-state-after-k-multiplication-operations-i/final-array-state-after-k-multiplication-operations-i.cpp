class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) 
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0; i<nums.size(); i++)
        {
            pq.push({nums[i],i});
        }

        while(k--)
        {
            int num=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            pq.push({(num*multiplier),ind});
        }

        while(!pq.empty())
        {
            int ind=pq.top().second;
            int val=pq.top().first;
            pq.pop();

            nums[ind]=val;
        }

        return nums;
    }
};