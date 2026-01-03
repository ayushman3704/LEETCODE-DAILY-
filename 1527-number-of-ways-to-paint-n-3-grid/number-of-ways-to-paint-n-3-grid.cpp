class Solution { // Pattern- "STATE COMPRESSION DP"
public:
    int m = 1e9 + 7;
    typedef long long ll;

    int numOfWays(int n) {
        ll dp1 = 6; // ABC
        ll dp2 = 6; // ABA

        for(int i = 2; i <= n; i++){
            ll new_dp1 = (dp1*2 + dp2*2) % m;
            ll new_dp2 = (dp1*2 + dp2*3) % m;

            dp1 = new_dp1;
            dp2 = new_dp2;
        }

        return (dp1 + dp2) % m;
    }
};


// Concepts You Learn:-
// State reduction
// DP with pattern grouping
// Combinatorics + DP
// Matrix DP without matrix
// Transition counting

// Where This Pattern Reappears:-
// Grid coloring problems
// DP with adjacency constraints
// Painting fence / house coloring variants
// State compression DP
// Google / Meta style DP questions