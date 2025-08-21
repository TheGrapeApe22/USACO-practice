// https://cses.fi/problemset/task/1643/
// 8 -1 3 -2 5 1 3 -5 2 2

public class SubArraySum {
    public static void main(String[] args) throws Exception {
        Brokenizer sc = new Brokenizer(System.in);
        // Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        //System.out.println(bruteForce(nums));
        System.out.println(recursion(nums, 0, 0, nums[0]));
    }
    public static int bruteForce (int[] nums) {
        int maxSum = nums[0];
        for (int i = 0; i < nums.length; i++) {
            int sum = 0;
            for (int j = i; j < nums.length; j++) {
                sum += nums[j];
                maxSum = Math.max(maxSum, sum);
            }
        }
        return maxSum;
    }
    public static int recursion (int[] nums, int a, int b, int currentSum) {
        //System.out.printf("[%d, %d]: %d\n", a, b, currentSum);
        int maxSum = currentSum;
        if (a == b && a != 0) {
            return nums[a];
        }
        if (a+1 <= b)
            maxSum = Math.max(maxSum, recursion(nums, a + 1, b, currentSum - nums[a]));
        if (a == 0 && b+1 < nums.length)
            maxSum = Math.max(maxSum, recursion(nums, a, b + 1, currentSum + nums[b+1]));
        return maxSum;
    }
}
