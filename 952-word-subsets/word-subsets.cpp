class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> freqMap;
        vector<string> ans;

        for(auto word : words2) {
            unordered_map<char, int> tempFreq;
            for(auto ch : word) {
                tempFreq[ch]++;
                freqMap[ch] = max(freqMap[ch], tempFreq[ch]);
            }
        }

        for(auto word : words1) {
            unordered_map<char, int> tempFreq;
            for(auto ch : word) 
                tempFreq[ch]++;
            bool universal = true;
            for(auto [ch, freq] : freqMap) {
                if(tempFreq[ch] < freq) {
                    universal = false;
                    break;
                }
            }
            if(universal)
                ans.push_back(word);
        }

        return ans;
    }
};