class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int startCooking = customers[0][0];
        double average = 0;
        for (int i = 0; i < customers.size(); ++i) {
            // if arrival time is greater than the previous cooking time this means cook can start cooking immediately
            if (startCooking < customers[i][0]) {
                startCooking = customers[i][0];
            }
            int cookingCompleted = startCooking + customers[i][1];
            // average = time of completing cooking - customer arrival time
            average += cookingCompleted - customers[i][0];
            // update cooking starting time for next customer
            startCooking = cookingCompleted;
        } 
        return average / customers.size();
    }
};