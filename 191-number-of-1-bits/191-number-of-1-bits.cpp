class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> bits(n);
        int res = 0;
        for(int i = 0; i < bits.size(); i++)
            res += bits[i];
        return res;
    }
};