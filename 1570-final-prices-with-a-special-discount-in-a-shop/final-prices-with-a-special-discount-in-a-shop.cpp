class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res;
        for(int i = 0; i < prices.size();i++){
            if(i == prices.size() - 1){
                res.push_back(prices[i]);
            }
            else{
                int discount = 0;
                for(int j = i + 1;j < prices.size();j++){
                    if(prices[i] - prices[j] >= 0){
                        discount = prices[j];
                        res.push_back(prices[i] - prices[j]);
                        break;
                    }
                    if(discount == 0 && j == prices.size() - 1){
                        res.push_back(prices[i]);
                    }
                }
            }
        }
        return res;
    }
};