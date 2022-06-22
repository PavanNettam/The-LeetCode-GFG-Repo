class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        for(int i=0;i<words.size();i++){
            string s = words[i];
            int outer = 0;
            for(int j=0;j<s.size();j++){
                int inner = 0;
                for(int k=0;k<allowed.size();k++){
                    if(s[j] == allowed[k]){
                        inner = 1;
                        break;
                    }
                }
                if(inner == 0){
                    outer = 1;
                }
            }
            if(outer == 0) count++;
        }
        return count;
    }
};