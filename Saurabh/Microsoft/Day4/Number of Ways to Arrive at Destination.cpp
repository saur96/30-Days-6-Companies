class Solution {
public:
     int mod = 1000000007;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long int, int>> record(n, {LONG_MAX, 1});
        vector<pair<int, int>> node[n];
        for(int i=0; i<roads.size(); i++){
            int a = roads[i][0], b = roads[i][1], c = roads[i][2];
            node[a].push_back({b, c});
            node[b].push_back({a,c});
        }
        record[0] = {0, 1};

        priority_queue<pair<long int, int>, vector<pair<long int, int>>, greater<pair<long int, int>>> pq;
        pq.push({0,0});
        pair<long int, int> temp;
        while(pq.size()){
            temp = pq.top(); pq.pop();
            long int currnode = temp.second;
            long currtime = temp.first;

        
            for(int i=0; i<node[currnode].size(); i++){
                int targetnode = node[currnode][i].first;
                long  targettime = node[currnode][i].second;
                if(targettime+currtime == record[targetnode].first) record[targetnode].second = (record[targetnode].second%mod + record[currnode].second%mod )%mod;
                if(targettime+currtime < record[targetnode].first){
                    record[targetnode].first = targettime+currtime;
                    record[targetnode].second = record[currnode].second;
                    pq.push({targettime+currtime, targetnode});
                }
            }
        }

        return record[n-1].second;
    }
};
