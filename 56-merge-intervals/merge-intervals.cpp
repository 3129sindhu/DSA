class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> sol;
        int i=0;
        while(i<n)
        {
            int a=intervals[i][0];
            int b=intervals[i][1];
            int j=i+1;
            while(j<n && intervals[j][0]<=b)
            {
                b = max(b, intervals[j][1]);
                j++;
            }
            sol.push_back({a,b});
            i=j;
        }
        return sol;
    }
};