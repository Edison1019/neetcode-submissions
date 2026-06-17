class Solution {
public:
    int binary_search(int l, int r, vector<int>& nums, int target){
        if(l > r) return -1;
        
        int m = l + (r-l)/2;
        if(target > nums[m])
            return binary_search(m+1, r, nums, target);
        else if(target < nums[m])
            return binary_search(l, m-1, nums, target);
        else
            return m;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> v;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                v.push_back(matrix[i][j]);
            }
        }

       if(binary_search(0, v.size()-1, v, target) == -1)
            return false;
        else
            return true;
    }
};
