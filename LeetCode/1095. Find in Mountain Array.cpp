
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
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
          int l=0,n=mountainArr.length(),r=n-2;

          while(l<=r){
                int m=l+r>>1;

                (mountainArr.get(m)<mountainArr.get(m+1)?l=m+1:r=m-1);
          }

          int md=l;

          l=0,r=md;
          while(l<=r){
                int m=l+r>>1;

                (mountainArr.get(m)<target?l=m+1:r=m-1);
          }

          if(l!=n&&mountainArr.get(l)==target)return l;

          l=md+1,r=n-1;
          while(l<=r){
                int m=l+r>>1;

                (mountainArr.get(m)>target?l=m+1:r=m-1);
          }

          if(l!=n&&mountainArr.get(l)==target)return l;


          return -1;
    }
};