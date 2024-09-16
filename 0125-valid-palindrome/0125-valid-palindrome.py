class Solution:
    def isPalindrome(self, s: str) -> bool:
        alphabets = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'}
        new_s = ""
        if s == " ":
            return True
        
        s = s.lower()
        for i in s:
            if i in alphabets:
                new_s += i
            else:
               continue
        # print(new_s, new_s[::-1])
        return new_s == new_s[::-1]

       
        
        