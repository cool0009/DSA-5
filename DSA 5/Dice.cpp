 class Solution {  
     int dp[31][1001];
     int M = 1000000007;
     int recursion( int n, int k, int target ){
         if(n==0 && target==0){return 1;}
         if(n==0){return 0;}
         if(target==0){return 0;}
         long ans=0;
         if(dp[n][target]!=-1){
             return dp[n][target];
         }
         for(int i=1;i<=k;i++){
             if(i<=target){
                 if(dp[n-1][target-i]==-1){
                     ans = (ans + recursion(n-1,k,target-i)*1ll)%M;
                 }else{
                     ans = (ans+ dp[n-1][target-i]*1ll)%M;
                 }
             }
         }
         return dp[n][target]=ans;
     }
 public:
     int numRollsToTarget(int n, int k, int target) {
         memset(dp,-1,sizeof dp);
         return recursion(n,k,target);
     }
 };