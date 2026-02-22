 #include<bits/stdc++.h>
 using namespace std;
 #define int long long
  
  
  
 //Ye Question kyu nhi ho paya && uska future solution kya rakhoge
 /*
  
  
  
  
 */
 // Problem Statement
 
 //Question aasan hi hota hai bass uska ishara samajha 
 
 /*
 you are given a number n with a length no more than 10^5 
 you have to perform some operation any no of time : 
 

 choose one of its digit square it and replace the original digit with the  result , the result must be a digit like if you choose x then the value of x^2 must be less than 10 

 is it possible to obtain a number that is divisible by 9 through these operations ? 
 
 */
  
 // Small Observatins
 /*
 
 
 
 */
  
  
 //Your attacks
 /*
  divisibility by 9 ,if the sum of the number is divisible by 9 then it is divisible by 9;
  to pahale to sum calculate kar lenge ; if sum is divisible then its ok , it not then we have to check something : 
  what no we can choose is 2, 3 
  on choosing 2 we can have increase in the sum by 2 
  and by choosing 3 we can have increase in the number by 6

  // what would be the possible value of sum % 9
  1 2 3 4 5 6 7 8 
  9 9 9 9 9 9 9 9 
  required 
  8 7 6 5 4 3 2 1 
  so if the required is odd we cant do anything 
  but if even is required we can do something ,
  if it is 8 then we need 4 two's or 1 six and 1 two 
  if it is 6 then we need 1 six or 3 twos 
  4: 2 tows 
  2 : 1tows 


 */
  
  
 // Hints From Code 
 /*  
 
 
  
 */
  
  
 // Learn form question
 /*
 
 
 
 */
  
  
 void Chal_Ja_Plz(){
    string s; cin>>s; 
    int sum =0;
    for(int i=0;i<s.size();i++)sum+=s[i]-'0';
    int two=count (s.begin() , s.end(),'2');
    int three=count (s.begin() , s.end(),'3');
    for(int i =0;i<=two;i++){
      for(int j=0;j<=three;j++){
        if((sum +i*2+j*6)%9==0){
          cout<<"YES\n";return;
        }
      }
    }
    cout<<"NO\n";

 }
  
 int32_t main(){
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
  
     int t; cin >> t;
     while (t--) Chal_Ja_Plz();
     return 0;
 }