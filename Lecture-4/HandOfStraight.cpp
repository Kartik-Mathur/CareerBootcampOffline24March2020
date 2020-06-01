// https://leetcode.com/problems/hand-of-straights/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if(hand.size()%W != 0) return false;
        if(W == 1) return true;
        
        sort(hand.begin(),hand.end());
    
        while(!hand.empty()){
            int count = 1;
            int pos = hand.size() -1;
            int target = hand[pos]-1;
            pos --;
            while(count<W){
                
                if(pos<0) return false;
                if(hand[pos] == target+1) pos--;
                else if(hand[pos] == target){
                    int temp = hand[pos];
                    for(int i=pos;i<hand.size()-1-count;i++){
                        hand[i] = hand[i+1];
                    }
                    hand[hand.size()-1-count] = temp;
                    count++;
                    pos--;
                    target--;
                }
                else{
                    return false;
                }
            }
            for(int i=0;i<W;i++){
                hand.pop_back();
            }
            // In java : N = N-W;
        }
        return true;
    }
};