class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> umap;
        for(char c : s1) umap[c]++;

        int match = umap.size();
        for(int i=0; i<s2.size(); i++){
            unordered_map<char, int> cnt;
            int sum = 0;
            for(int j=i; j<i+s1.size() && j<s2.size(); j++){
                char c = s2[j];
                cnt[s2[j]]++;

                if(umap[c] < cnt[c]) break;
                if(umap[c] == cnt[c]) sum++;
                if(sum == match) return true; 
            } 
        }

        return false;
    }
};