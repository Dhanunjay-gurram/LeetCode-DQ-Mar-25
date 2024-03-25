class Solution {
public:
    //Negation Approach
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;        //To store the answer
        int index;              //To store the index temporarily
        
        for( int i = 0; i < nums.size(); i++){
            index = abs(nums[i]) - 1;       //Calculating index
            if(nums[index] < 0){            //Indicates repeated number
                ans.push_back(index+1);
            }
            else{                           //Sets a count of 1 for the number by negating
                nums[index] = -nums[index];
            }
        }
        
        return ans;
    }
};


/*
    Approach                Time Complexity            Space Complexity
  1.Negating                    O(n)                       O(1)(excluding result arr)
  2.Hashing                     O(n)(avg)                  O(n)
  3. Sorting                    O(nlogn)                   O(n)
  4. Brute Force                O(n^2)                     O(1)(excluding result arr)
 */

    //2. Hashing Approach
/*
 vector<int> findDuplicates(vector<int>& nums) {
         unordered_map<int,int> up;
         for(auto x:nums){
             up[x]++;           //Maintaining count for the frequency of numbers
         }
         vector<int> ans;
         for(auto it=up.begin();it!=up.end();it++){
             if(it->second==2){
                 ans.push_back(it->first);
             }
         }
         return ans;
     }

 */

    //3. Sorting Approach
/*
 vector<int> findDuplicates(vector<int>& nums) {
         sort(nums.begin(),nums.end());     //Sorting the given array
         vector<int> ans;
         for(int i=0;i<nums.size();i++){
             if(i<nums.size()-1 && nums[i]==nums[i+1]){ //Checks the double frequency
                 ans.push_back(nums[i]);
                 i++;
             }
         }
         return ans;
     }
 */

    //4. Brute Force
/*
 vector<int> findDuplicates(vector<int>& nums) {
         vector<int> ans;
         for(int i=0;i<nums.size();i++){
             for(int j=i+1;j<nums.size() && nums[i];j++){
                 if(nums[i] == nums[j]){
                     nums[j] = 0;
                     ans.push_back(nums[i]);
                     break;
                 }
             }
         }
         return ans;
     }
 
 //TLE !!!!!
 */
