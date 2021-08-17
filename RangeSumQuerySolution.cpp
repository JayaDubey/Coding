class NumArray {
public:
     vector<int> vec;
    NumArray(vector<int>& nums) {
        vec = nums;
      //  if(nums.size() > 0){
     //       vec[0] = nums[0];
        //    for(int i = 1; i < nums.size(); i++){
     //           vec[i] = vec[i-1] + vec[i];
      //      }
   // }
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        //if(left == 0)
        //    return vec[right];
       // return vec[right] - vec[left-1];
        for(int i = left; i <= right; i++){
            sum+=vec[i];
        }
        return sum;
    }
};
