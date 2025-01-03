class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int num = low; num <= high; num++) {
            if (isSymmetric(num)) {
                count++;
            }
        }
        return count;
    }

private:
    bool isSymmetric(int num) {
        std::string strNum = std::to_string(num);
        int n = strNum.size();

        if (n % 2 != 0) {
            return false;
        }

        int leftSum = 0, rightSum = 0;
        for (int i = 0; i < n / 2; i++) {
            leftSum += strNum[i] - '0'; 
            rightSum += strNum[n - i - 1] - '0'; 
        }

        return leftSum == rightSum;
    }
};
