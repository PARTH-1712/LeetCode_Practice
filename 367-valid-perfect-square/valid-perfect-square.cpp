class Solution {
public:
    bool isPerfectSquare(int num) {
        long l=1,h=num;
        while(l<h)
        {
            long mid=(l+h)/2;
            if(mid>=num/mid)
            {
                h=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        if(l*l==num)
        return true;
        return false;
        
        double a=pow(num,0.5);
        for(int i=1;i<a+1;i++)
        {
            if(i==a)
            return true;
        }
        return false;
    }
};