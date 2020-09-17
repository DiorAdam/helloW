public class maxContinuousSum {
    public static int longestSum(int[] t){
        int ans = 0;
        int[] mem = new int[t.length+1];
        mem[0] = 0;
        for (int i=1; i <= t.length; i++){
            mem[i] = Math.max(mem[i-1]+t[i-1], t[i-1]);
            ans = Math.max(ans, mem[i]);
        }
        return ans;
    }
    public static void main(String[] args){
        int[] nums = {-2,1,-3,4,-1,2,1,-5,4};
        System.out.println(longestSum(nums));
    }
}

