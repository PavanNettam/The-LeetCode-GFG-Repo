class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,-1);
        vector<int> right(n,n);
        //cout<<"hi"<<endl;
        stack<int> st1;
        for(int i=0;i<n;i++){
            //cout<<"i = "<<i<<endl;
            if(!st1.empty()){
                int ele = heights[i];
                while(!st1.empty() && heights[st1.top()] > ele){
                    right[st1.top()] = i;
                    st1.pop();
                }
            }
            //cout<<"after i = "<<i<<endl;
            st1.push(i);
        }
        stack<int> st2;
        for(int i=n-1;i>=0;i--){
            //cout<<"i = "<<i<<endl;
            if(!st2.empty()){
                int ele = heights[i];
                while(!st2.empty() && heights[st2.top()] > ele){
                    left[st2.top()] = i;
                    st2.pop();
                }
            }
            //cout<<"after i = "<<i<<endl;
            st2.push(i);
        }
        // for(int i=0;i<n;i++){
        //     cout<<left[i]<<" ";
        // }
        int maxi = -1;
        int temp = -1;
        for(int i=0;i<n;i++){
            temp = (heights[i]*(right[i]-left[i]-1));
            maxi = (maxi>temp)?maxi:temp;
        }
        return maxi;
    }
};