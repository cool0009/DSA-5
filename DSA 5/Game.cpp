 class Solution{
     int ans1=0,ans2=0;
     int dp[1005][1005][2];
     long long recursion(int arr[], int i ,int j, int turn){
         if(i>j){
             return 0;
         }
         if(dp[i][j][turn] !=-1){
             return dp[i][j][turn];
         }
         if(turn){
             return dp[i][j][turn] = max(arr[i] + recursion(arr,i+1,j,0),arr[j]+recursion(arr,i,j-1,0));
         }else{
             return dp[i][j][turn] = min(recursion(arr,i+1,j,1),recursion(arr,i,j-1,1));
         }        
     }
     public:
     long long maximumAmount(int arr[], int n){
         memset(dp,-1,sizeof dp);
         return recursion(arr,0,n-1,1);
     }
 };