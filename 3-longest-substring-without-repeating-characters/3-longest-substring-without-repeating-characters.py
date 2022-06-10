class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        visited = {}
        l = 0
        ans = 0
        for r in range(len(s)):
            if s[r] not in visited:
                ans = max(ans,r-l+1)
            else:
                if visited[s[r]]<l:
                    ans = max(ans,r-l+1)
                else:
                    l = visited[s[r]]+1
            visited[s[r]] = r
        return ans
    