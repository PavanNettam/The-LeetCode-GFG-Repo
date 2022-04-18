class Solution:
    def calPoints(self, ops: List[str]) -> int:
        ans = []
        for i in ops:
            #print(i)
            
            if(i == "+"):
                new = ans[-1] + ans[-2]
                ans.append(new)
            elif(i == "D"):
                new = 2*ans[-1]
                ans.append(new)
            elif(i == "C"):
                ans.pop()
            else:
                ans.append(int(i))
            #print(ans)
        r = 0
        for i in ans:
            r+=i
        return r
        