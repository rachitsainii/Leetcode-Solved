class Solution:
    def reverse(self, x: int) -> int:
        negative = False

        if x < 0:
            negative = True
            x = x * -1
        
        res = 0
        while x > 0:
            res = (res * 10) + (x % 10)
            x //= 10

        if res > 2 ** 31 - 1:
            return 0
        
        return res * -1 if negative else res