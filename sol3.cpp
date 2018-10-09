If you had extra space to do it, the problem will be very easy. 
Store a copy of Arr in B.

And then for every element, do Arr[i] = B[B[i]]

Lets restate what we just said for extra space :

If we could somehow store 2 numbers in every index ( that is, Arr[i] can contain the old value and the new value somehow ), then the problem becomes very easy. 
NewValue of Arr[i] = OldValue of Arr[OldValue of Arr[i]]

Now, we will do a slight trick to encode 2 numbers in one index. 
This problem assumes that N * N does not overflow.


Solution:

  #include <bits/stdc++.h>
   using namespace std;

 void arrange(vector<int> &Vec) {
        int N = Vec.size();
        for(int i = 0; i < N; ++i) {
            Vec[i] = Vec[i] + (Vec[Vec[i]]%N) * N;
        }

        for(int i = 0; i < N; ++i) {
            Vec[i] = Vec[i] / N;
        }
    }
 int main(){
   int n,val;
   cin>>n;
   vector<int>v;
   for(int i=0;i<n;i++){
      cin>>val;
      v.push_back(val);
   }
   arrange(v);
   for(int i:v){
   cout<<i<<" ";
   }
   return 0;
 }