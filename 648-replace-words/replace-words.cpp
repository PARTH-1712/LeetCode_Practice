class Solution {
public:
    string replaceWords(vector<string>& di, string se) {
        se+=" ";
        int n=di.size();
        unordered_map<string,int>hash;
        for(int i=0;i<n;i++)
        {
            hash[di[i]]++;
        }
        string ans="";
        for(int i=0;i<se.size();i++)
        {
            int j=i;
            string nw="";
            while(hash[nw]==0&&se[j]!=' ')
            {
            nw=se.substr(i,j-i+1);
            j++;
            }
                ans+=nw;
                ans+=" ";
            while(se[j]!=' ')
            {
                j++;
            }
            i=j;
        }
       
        ans=ans.substr(0,ans.size()-1);
        return ans;
    }
};