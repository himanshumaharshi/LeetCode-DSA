class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // // Get the first edge, represented as a vector {a, b}.
        // vector<int> first  = edges[0];
        // // Get the second edge, represented as a vector {c, a}.
        // vector<int> second = edges[1];

        // // Check if the first element of the first edge is present in the
        // second edge. if(first[0] == second[0] || first[0] == second[1]) {
        //     // If it is, return the first element of the first edge.
        //     return first[0];
        // }

        // // If the first element of the first edge is not present in the second edge,
        // // then the second element of the first edge must be the center.
        // return first[1];

        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
    }
};