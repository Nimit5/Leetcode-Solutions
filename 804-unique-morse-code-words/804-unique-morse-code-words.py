class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        l=[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        s=set()
        for item in words:
            t=""
            for i in item:
                t+=l[ord(i)-ord('a')]
            s.add(t)
        return len(s)