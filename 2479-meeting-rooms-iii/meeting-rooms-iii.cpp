class Solution { // using two min heap.
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        sort(meetings.begin(), meetings.end());

        // availableRooms:
        // Min-heap storing FREE room numbers
        priority_queue<int, vector<int>, greater<int>> availableRooms;

        // busyRooms:
        // Min-heap storing (endTime, roomNumber)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyRooms;

        // Count how many meetings each room handles
        vector<long long> count(n, 0);

        for(int i = 0; i < n; i++){
            availableRooms.push(i);
        }

         // Before assigning a meeting starting at 'start',
            // move all rooms that are free by 'start' from busy -> available
        for (auto& meeting : meetings) {
            long long start = meeting[0];
            long long end   = meeting[1];
            long long duration = end - start;


            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                int room = busyRooms.top().second;
                busyRooms.pop();
                availableRooms.push(room);
            }

            if (!availableRooms.empty()) { // Case 1: At least one room is free
                int room = availableRooms.top();
                availableRooms.pop();

                busyRooms.push({end, room});
                count[room]++;
            }

            // Case 2: No room is free → delay meeting
            else {
                auto [earliestEnd, room] = busyRooms.top();
                busyRooms.pop();

                // Invariant:
                // Meeting is delayed until earliestEnd
                long long newEnd = earliestEnd + duration;

                busyRooms.push({newEnd, room});
                count[room]++;
            }
        }

        int answer = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[answer]) {
                answer = i;
            }
        }

        return answer;
    }
};