public class Solution {
    public int[] TwoSum(int[] nums, int target) {
            int[] Ans = new int[2];
            for (int i = 0; i < nums.Length; i++)
            {
                for (int j = 1; j +i< nums.Length; j++)
                {
                    if (nums[i] + nums[i + j] == target)
                    {
                        Ans[0] =i;
                        Ans[1] =i + j;
                    }
                }
            }
            return Ans;
    }
}