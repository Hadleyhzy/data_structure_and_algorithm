//
//  40_combiantion_sum_2.cpp
//  leetcode_array
//
//  Created by Hadley on 03.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/stdc++.h"
using namespace std;

class Solution {
public:
    void sum(vector<int> &candidates, int target, int cur, int index, vector<int> &r){
                for(int i=index;i<candidates.size();i++){
                    while(i<candidates.size()&&i>index&&candidates[i]==candidates[i-1])i++;
                    if(i>=candidates.size())break;
                    cur+=candidates[i];
                    r.push_back(candidates[i]);
                    if(cur<target){
                       sum(candidates,target,cur,i+1,r);
                    }else if(cur==target){
                        res.push_back(r);
                    }
                    r.pop_back();
                    cur-=candidates[i];
                }
            }
            vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
                sort(candidates.begin(),candidates.end());
                vector<int>subset;
                sum(candidates,target,0,0,subset);
                return res;
            }
    private:
            vector<vector<int>>res;
};
