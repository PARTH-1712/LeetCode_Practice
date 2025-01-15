class Solution {
    public:
    int countsetbits(int no) {
        int count = 0;
        while (no) {
            if (no & 1)
                count++;
            no >>= 1;
        }
        return count;
    }
    int minimizeXor(int num1, int num2) {
        int set1 = countsetbits(num1);
        int set2 = countsetbits(num2);
        int ans = num1;
        int mask = 1;
        int keepones = min(set1, set2);
        int trimones = set1 - keepones; 
        while (trimones) {
            if (mask & ans) {
                ans &= ~mask;
                trimones--;
            }
            mask <<= 1;
        }
        mask = 1;
        int addones = max(0, set2 - keepones); 
        while (addones) {
            if (!(mask & ans)) {
                ans |= mask;
                addones--;
            }
            mask <<= 1;
        }
        return ans;
    }
};