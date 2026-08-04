class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        vector<int> left(n);
        vector<int> right(n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                left[i]=-1;
            }
            else
            {
                left[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            st.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                right[i]=n;
            }
            else
            {
                right[i]=st.top();
            }
            st.push(i);
        }
        int max1=0;
        for(int i=0;i<n;i++)
        {
            int area=heights[i]*(right[i]-left[i]-1);
            max1=max(max1,area);
        }
        return max1;

    }
};