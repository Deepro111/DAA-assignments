#include<iostream>
#include<vector>
#include<cstdlib>
#include<stdlib.h>
// #include "matplotlibcpp.h"

// namespace plt = matplotlibcpp;
using namespace std;

int linearSearch(vector<int> arr, int key){

    int count = 0;
    for(int i=0; i<arr.size(); i++){
        count++;
        if(arr[i] == key){
            return count;
        }
    }
    return count;
} 

int main(){

    vector<int> sizes, bestCases, worstCases, avgCases;

    cout<< "Size of Array" << " " << "bestCase" << " " << "worstCase"<<" "<<"avgcase"<<endl;
    for(int n=10; n<=100; n+=5){
        vector<int> arr(n);
        vector<int> keys(n+1);
        for(int i=0; i<n; i++){
            arr[i] = keys[i] = (1+(rand()%100));
            // keys[i] = (1+(rand()%100));
        }
        keys[n]=(101);

        // cout<<"arr elements are : ";
        // for(int i=0; i<arr.size(); i++){
        //     cout<<arr[i]<<" ";
        // }cout<<endl;
        // cout<<"key elements are : ";
        // for(int i=0; i<keys.size(); i++){
        //     cout<<keys[i]<<" ";
        // }cout<<endl;


        // int bestCase = linearSearch(arr, keys[0]);
        int bestCase = INT_MAX;
        int worstCase = INT_MIN;

        int avgcase = 0;
        for(int i=0; i<keys.size(); i++){
            int comparison = linearSearch(arr, keys[i]);
            bestCase=min(bestCase, comparison);
            worstCase=max(worstCase, comparison);
            avgcase+=comparison;
        }
        avgcase=avgcase/(keys.size()-1);

        cout<< n << " " << bestCase << " " << worstCase<<" "<<avgcase<<endl;

        // sizes.push_back(n);
        // bestCases.push_back(bestCase);
        // worstCases.push_back(worstCase);
        // avgCases.push_back(avgcase);
    }

    // plt::named_plot("Best Case", sizes, bestCases, "r-");
    // plt::named_plot("Worst Case", sizes, worstCases, "b-");
    // plt::named_plot("Average Case", sizes, avgCases, "g-");

    // plt::xlabel("Array Size");
    // plt::ylabel("Number of Comparisons");
    // plt::legend();
    // plt::title("Linear Search Complexity");
    // plt::show();
    
    return 0;
}