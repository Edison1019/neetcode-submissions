class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> price(n, INT_MAX);
        price[src] = 0;

        for(int i=0; i<=k; i++){
            vector<int> tmp = price;
            for(vector<int> f : flights){
                int s = f[0];
                int d = f[1];
                int cost = f[2];
                if(price[s] == INT_MAX){
                    continue;
                }
                if(price[s] + cost < tmp[d]){
                    tmp[d] = price[s] + cost;
                }
            }
            price = tmp;
        }

         return price[dst] == INT_MAX ? -1 : price[dst];
    }
};
