class Solution {
public:
    bool checkString(string s) {
      int n = s.size();
      int count = 0;
      for(int i=0; i<n; i++){
        if(s[i]=='a'){
            count++;
        }
      }
      if(count==0){
        return true;
      }
      for(int i=0; i<count; i++){
        if(s[i]=='b'){
            return false;
        }
      }
      return 1;  
    }
};