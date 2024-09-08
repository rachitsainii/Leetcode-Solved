class Solution:
    def reverseWords(self, s: str) -> str:
        words = []
        words = s.split()
        print(words)
        words = words[::-1]
        ans = ""
        for i in words:
            ans = ans +  i
            ans = ans +  " "

        return ans[:-1]
        