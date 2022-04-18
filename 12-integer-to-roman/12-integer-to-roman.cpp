
class Solution {
public:
    string store(stack<string>& st){
        string r = "";
        while(!st.empty()){
            string temp = st.top();
            st.pop();
            r = r+temp;
        }
        return r;
    }
    string intToRoman(int num) {
        stack<string> st;
        int curr;
        curr = num%10;
        if(curr == 1) st.push("I");
        else if(curr == 2) st.push("II");
        else if(curr == 3) st.push("III");
        else if(curr == 4) st.push("IV");
        else if(curr == 5) st.push("V");
        else if(curr == 6) st.push("VI");
        else if(curr == 7) st.push("VII");
        else if(curr == 8) st.push("VIII");
        else if(curr == 9) st.push("IX");
        else if(curr == 0) st.push("");
        num /= 10;
        if(num == 0){
            return store(st);
        }
        curr = num%10;
        if(curr == 1) st.push("X");
        else if(curr == 2) st.push("XX");
        else if(curr == 3) st.push("XXX");
        else if(curr == 4) st.push("XL");
        else if(curr == 5) st.push("L");
        else if(curr == 6) st.push("LX");
        else if(curr == 7) st.push("LXX");
        else if(curr == 8) st.push("LXXX");
        else if(curr == 9) st.push("XC");
        else if(curr == 0) st.push("");
        num /= 10;
        if(num == 0){
            return store(st);
        }
        curr = num%10;
        if(curr == 1) st.push("C");
        else if(curr == 2) st.push("CC");
        else if(curr == 3) st.push("CCC");
        else if(curr == 4) st.push("CD");
        else if(curr == 5) st.push("D");
        else if(curr == 6) st.push("DC");
        else if(curr == 7) st.push("DCC");
        else if(curr == 8) st.push("DCCC");
        else if(curr == 9) st.push("CM");
        else if(curr == 0) st.push("");
        num /= 10;
        if(num == 0){
            return store(st);
        }
        curr = num%10;
        if(curr == 1) st.push("M");
        else if(curr == 2) st.push("MM");
        else if(curr == 3) st.push("MMM");
        return store(st);
    }
};