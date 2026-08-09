class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> umap;
        for(char c : s1){
            umap[c]++;
        }
        int need = umap.size();
        for(int i=0; i<s2.length(); i++){
            unordered_map<char, int> cnt;
            int cur = 0;
            for(int j=i; j<s2.length(); j++){
                char c = s2[j];
                cnt[c]++;
                
                if(umap[c] < cnt[c]) 
                    break;
                if(umap[c] == cnt[c]) 
                    cur++;
                if(cur == need) 
                    return true;
            }
        }

        return false;
    }
};
