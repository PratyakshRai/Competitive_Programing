#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
    
*/
 
// Small Observatins
/*
    what are lower bounds..
 
    -> a divisor chain to n is a lower bound..
 
    so, if n = (e1, e2, e3.....)
 
    whats the longest divisor chain that u can get?
        ->
            So, sum of exponents is a lowerbound?
 
            cause.
            u can have a divisor chain by reucing it by 1 , some exponent.
 
            so Sum of exponents is the answer -1. is a guess.
 
    none if them in the same layer divide each other..
    -> so if u compare 2. they have a prime thats not in each other..
 
    so.. if each prime is present >= 2 times?
 
    among layers exponent can only drop by 1..
 
    lets have a prime help everyone.. --> which will be present and never decrease..
 
        -> 
            so the answer = exponent till here  + exponent + 1 is always possible..
 
            now the question is , when does exponent - 1 is possible,
 
            exponent 
 
    Sum of exponet is always possible..
 
    now.. the question is for exponent - 1..
 
        -> u know the layers.. and for eadch layer u have to see if theres an odergin.
 
            the layers will get fixed, because of (exponent sum);
        
        Okay, now if u have a series of exponents and primes..
 
        -> u have to answer is there a line possible in here..
 
        look at the last but one.. all the prime factors also should be alone..
 
        so maybe the answer = .
            sum of exponents = 2, has their order.
 
            but when sum of exponents = 1..
                u have p1 p2 p3... pk
 
                all of them will take.. a new thing..
 
                so as long as sum of exponent = 2..
                it comes down..
 
                p1p2 p2p1...
 
                sum, sum -1... 2, number of primes..
 
 
*/
 
 
 
/*
 
*/
 
 
// Claims on algo 
/*  
    any 2 numbers in this chain have gcd > 1..
 
 
*/
 
#define N 1000010
 
int lp[N] = {0}, expo[N] = {0}, uPrimes[N] = {0};
 
void solve(){
    int n; cin >> n;
    cout << expo[n] + uPrimes[n] - 1 << '\n';
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    for (int i = 2; i < N; i++){
        if (lp[i] == 0){
            for (int j = i; j < N; j += i){
                lp[j] = 1;
                uPrimes[j]++;
                int tmp = j;
                while (tmp % i == 0){
                    expo[j]++;
                    tmp /= i;
                }
            }
        }
    }
 
    int t; cin >> t;
    while (t--) solve();
}
 
// Golden Rules
/*
    Solutions are simple.
 
    Proofs are simple.
 
    Implementations are simple.
*/