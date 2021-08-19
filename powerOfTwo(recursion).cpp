class Solution {
public:
    bool isPowerOfTwo(int n) {
        //by bit manipulation O(1) time
        if(n <= 0)
          return false;
        if((n&(n-1)) == 0)
           return true;
        return false;
        
        //by recursion O(log n) time
       //  if(n == 1)
      //     return true;
     //   if(n%2 == 0)
    //       return isPowerOfTwo(n/2);
   //    return false;
        
        
   //by iterative O(log n) time
   //     if (n <= 0) 
   //        return false;
   //    while(n%2 == 0) 
   //        n/=2;
   //    if(n == 1)
   //       return true;
   //     return false;
    }
};