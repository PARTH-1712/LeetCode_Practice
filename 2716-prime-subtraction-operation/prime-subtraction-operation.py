import math

class Solution:
    def checkPrime(self, x):
        if x < 2:
            return False
        for i in range(2, int(math.sqrt(x)) + 1):
            if x % i == 0:
                return False
        return True

    def primeSubOperation(self, nums):
        primes = [i for i in range(2, 1001) if self.checkPrime(i)]
        
        for i in range(len(nums)):
            bound = nums[i] - nums[i - 1] if i > 0 else nums[i]
            if bound <= 0:
                return False
            
            largest_prime = 0
            for j in range(bound - 1, 1, -1):
                if j in primes:
                    largest_prime = j
                    break
            
            nums[i] -= largest_prime
            
            if i > 0 and nums[i] <= nums[i - 1]:
                return False
            
        return True    