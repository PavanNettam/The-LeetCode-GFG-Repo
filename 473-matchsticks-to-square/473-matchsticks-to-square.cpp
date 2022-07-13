class Solution
{
public:
    bool solve(int sides, vector<int> &m, int i, int s, int one_side, vector<bool> &visited)
    {
        if (sides == 0)
            return true;

        if (s == one_side)
        {
            return solve(sides - 1, m, m.size() - 1, 0, one_side, visited);
        }
        for (int k = i; k >= 0; k--)
        {
            if (!visited[k] && one_side >= s + m[k])
            {
                visited[k] = true;

                if (solve(sides, m, k - 1, s + m[k], one_side, visited))
                    return true;

                visited[k] = false;
            }
        }

        return false;
    }

    bool makesquare(vector<int> &m)
    {
        int peri = 0;
        int n = m.size();
        sort(m.begin(),m.end(),greater<int>());
        for (int i = 0; i < n; i++)
        {
            peri += m[i];
        }
        if (peri % 4 != 0)
            return false;
        vector<bool> visited(n, false);
        return solve(4, m, n - 1, 0, peri / 4, visited);
    }
};