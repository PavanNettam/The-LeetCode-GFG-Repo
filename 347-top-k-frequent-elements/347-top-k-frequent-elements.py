class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        s = set(nums)
        #print(s)
        d = dict()
        for i in s:
            d[i] = 0
        for i in nums:
            d[i]+=1
        temp = k
        l=[]
        
        while(temp):
            temp-=1
            keymax = max(d, key= lambda x: d[x])
            l.append(keymax)
            del d[keymax]
            #print(d)
        return l
                