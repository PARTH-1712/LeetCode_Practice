class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int>store;  
        vector<int>ans(A.size()); 
        ans[0]=A[0]==B[0]?1:0; 
        store.insert(A[0]); 
        store.insert(B[0]);
        for(int i=1;i<A.size();i++){ 
            store.insert(A[i]);
            store.insert(B[i]);
            int total_ele=2*i+2;        
            ans[i]=total_ele-store.size();      
        }
        return ans;
    }
};