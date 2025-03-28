#include<bits/stdc++.h>
#define ld   long double
using namespace std;
double bruteGasStations(vector<int>&arr,int k)
{
    int n = arr.size();
    vector<int>howMany(n-1,0);
    ld sectionLength = -1;
    for(int gas = 1; gas <= k; gas++)
    {
       ld maxVal = -1;
       ld maxInd = -1;
        for(int i = 0; i<n-1;i++)
        {
         ld diff = arr[i+1] - arr[i];
         ld sectionLength = diff/(howMany[i] + 1.0L);
         if(maxVal < sectionLength)
         {
             maxVal = sectionLength;
             maxInd = i;
         }
         howMany[maxInd]++;
            
        }
    }
   ld maxAns = -1;
   for(int i = 0;i<n;i++)
   {
       sectionLength = (arr[i-1] - arr[i])/(howMany[i] + 1);
       maxAns = max(maxAns,sectionLength);
   }
    return maxAns;
}
int main()
{ 
    //each arr[i] represents the position of ith Gas station 
    //we have to place k  gas stations 
    //answers  within 1e(-6) of the actual answers will be accepted
    vector<int>arr = {1,2,3,4,5};
    int k = 4; //
    cout<<bruteGasStations(arr,k);
    
}