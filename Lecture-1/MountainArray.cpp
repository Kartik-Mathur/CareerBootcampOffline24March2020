// MountainArray
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
    int pivot(MountainArray &a,int n){
        int s = 0;
        int e = n-1;
        
        while(s<e){
            int mid = (s+e)/2;
            if(a.get(mid)<a.get(mid+1)){
                s = mid+1;
            }
            else{
                e = mid;
            }
        }
        return s;
    }
    
    // Binary Search on ascending part of the array
    int BSasc(MountainArray &a,int s,int e,int target){
        if(s>e){
            return -1;
        }
        int mid = (s+e)/2;
        int val = a.get(mid);
        if(val == target){
            return mid;
        }
        else if(val<target){
            return BSasc(a,mid+1,e,target);
        }
        else{
            return BSasc(a,s,mid-1,target);
        }
    }
    // Binary Search on descending part of the array
    int BSdsc(MountainArray &a,int s,int e,int target){
        if(s>e){
            return -1;
        }
        int mid= (s+e)/2;
        int val = a.get(mid);
        if(val == target){
            return mid;
        }
        else if(val>target){
            return BSdsc(a,mid+1,e,target);
        }
        else{
            return BSdsc(a,s,mid-1,target);
        }
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        int k = pivot(mountainArr,n);
        
        int ans = BSasc(mountainArr,0,k,target);
        if(ans!=-1){
            return ans;
        }
        return BSdsc(mountainArr,k+1,n-1,target);
    }
};