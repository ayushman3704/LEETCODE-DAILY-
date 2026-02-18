class Solution { // using max heap
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int fuel = startFuel; // current fuel
        int i = 0;  // index for stations
        int stops = 0; // number of refuels done

        int n = stations.size();

        priority_queue<int> maxHeap; // Max heap to store fuels of all reachable but unused stations

        while(fuel < target){ // While destination is not reachable

            while(i < n && stations[i][0] <= fuel){ // Push all stations that can be reached with current fuel
                maxHeap.push(stations[i][1]);
                i++;
            }

            // If no past station is available to refuel from.  Cannot move further → impossible
            if(maxHeap.empty()) return -1;

            fuel += maxHeap.top(); // Refuel from the station with maximum fuel 
            maxHeap.pop();

            stops++; // Count this refueling stop
        }
        return stops;   
    }
};