class Solution {
public:

    void moveZeroes(vector<int>& nums) {
        int currZeroes = 0;
        cout << "size " << nums.size() << endl;
        for(int i = 0; i < nums.size(); i++) {
            cout << i << " " << currZeroes << endl;
            if (nums[i] == 0) currZeroes++;
            else {
                nums[i - currZeroes] = nums[i];
            }
            
        }

        for(int i = nums.size() - 1; i > nums.size() - 1 - currZeroes; i--) {
            cout << "zeroing " << i << " " << currZeroes << endl;
            nums[i] = 0;
        }
    }
};