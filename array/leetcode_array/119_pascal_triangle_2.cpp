//
//  119_pascal_triangle_2.cpp
//  leetcode_array
//
//  Created by Hadley on 17.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
using namespace std;


class Solution119 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> nums{1,1};
        if(rowIndex==0){return vector<int>{1};}
        if(rowIndex==1){return nums;}
        int row = 2;
        while(row<=rowIndex){
            cout<<"size: "<<nums.size()<<endl;
            int length = nums.size();
            for(int col = 1; col<length; col++){
                cout<<nums[col]<<" "<<nums[col-1]<<endl;
                nums.push_back(nums[col]+nums[col-1]);
            }
            nums.push_back(1);
            row++;
            nums.erase(nums.begin()+1, nums.begin()+row-1);
        }
        return nums;
    }
};

class Solution119_2 {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0){return {1};}
         if(rowIndex==1){return {1,1};}

        vector<int> nums{1,1};
         
         for(int i=2;i<=rowIndex;i++){
             for(int j=0;j<nums.size()-1;j++){
                 nums[j]=nums[j]+nums[j+1];
             }
             nums.insert(nums.begin(), 1);
             // for(auto &x:nums){
             //     cout<<x<<" ";
             // }
             // cout<<endl;
         }
         return nums;
    }
};


