class Solution { // max heap approach 
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        int n = quality.size();

        vector<pair<double, int>> workers; // Store {ratio, quality}

        for(int i = 0; i < n; i++){
            double ratio = (double)wage[i]/quality[i];

            workers.push_back({ratio, quality[i]});
        }

        sort(workers.begin(), workers.end()); // Sort workers by increasing ratio

        priority_queue<int> pq; // Max heap to keep K smallest qualities

        int sumQuality = 0;
        double ans = 1e18;

        for(auto & w : workers){ 
            double r = w.first;
            int q = w.second;

             // Add current worker
            pq.push(q);
            sumQuality += q;    

            if(pq.size() > k){ // If more than K workers, remove the worst (largest quality)
                sumQuality -= pq.top();

                pq.pop();
            }

            // If exactly K workers, calculate cost
            if(pq.size() == k){
                double cost = (r*sumQuality);

                ans = min(ans, cost);
            }
        }

        return ans; 
    }
};