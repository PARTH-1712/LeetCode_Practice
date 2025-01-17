class Solution {
public:
 vector<string>ans;
void solve(string s,int ct,string help){
   if(ct==0){
       if(s==""|| (s.size()>=2 && s[0]=='0')|| s.size()>3) return;
       if(stoi(s)<=255) ans.push_back(help+s);
        return;
   } 

    for(int i=0;i<s.size();i++){
         string left=s.substr(0,i+1);

       if(left.size()>=2 && left[0]=='0') return;

        if(left.size()>3) return;
        else if(left!="" && stoi(left)<=255){
              string right=s.substr(i+1);
             solve(right,ct-1,help+left+'.');
        }
     }
  }

    vector<string> restoreIpAddresses(string s) {
        solve(s,3,"");
        return ans;
    }
};