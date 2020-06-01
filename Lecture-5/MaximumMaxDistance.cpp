
// Problem : https://leetcode.com/problems/minimize-max-distance-to-gas-station/
// On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], 
// where N = stations.length.

// Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.

// Return the smallest possible value of D.

// Example:

// Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
// Output: 0.500000
// Note:

// stations.length will be an integer in range [10, 2000].
// stations[i] will be an integer in range [0, 10^8].
// K will be an integer in range [1, 10^6].
// Answers within 10^-6 of the true value will be accepted as correct.

class Solution {
    bool KyaPossibleHai(vector<int>& stations, int K,double dist){
        int total_stations_placed = 0;
        for(int i=0;i<stations.size()-1;i++){
            total_stations_placed += (int)(stations[i+1]-stations[i])/dist;
        }
        if(total_stations_placed<=K) return true;
        return false;
    }
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        
        double s = 0;
        double e = 1e8;
        
        while(e - s > 1e-6){
            double mid = (s+e)/2;
            
            if(KyaPossibleHai(stations,K,mid)){
                e = mid;
            }
            else{
                s = mid;
            }
        }
        return s;
    }
};