//
//  364_nested_list_weight_sum_2.cpp
//  leetcode_dfs
//
//  Created by Hadley on 27.08.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <cstring>
#include <queue>
#include <functional>
#include <numeric>
#include <map>
#include <filesystem>
#include <dirent.h>
using namespace std;


  // This is the interface that allows for creating nested lists.
  // You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

     // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const;
 
      // Set this NestedInteger to hold a single integer.
      void setInteger(int value);
 
      // Set this NestedInteger to hold a nested list and adds a nested integer to it.
      void add(const NestedInteger &ni);

      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    int depthSum(NestedInteger nestedElement, int depth){
        if(nestedElement.isInteger()){
            return depth*nestedElement.getInteger();
        }else{
            int sum=0;
            for(auto x:nestedElement.getList()){
                sum+=depthSum(x, depth-1);
            }
            return sum;
        }
    }
    int depth(const vector<NestedInteger>& nestedList){
        int d=1;
        for(auto x:nestedList){
            if(x.isInteger()){
                d=max(d,1);
            }else{
                d=max(d,depth(x.getList())+1);
            }
        }
        return d;
    }

    int depthSumInverse(vector<NestedInteger>& nestedList) {
            int d=depth(nestedList);
            int sum=0;
            for(auto x:nestedList){
                sum+=depthSum(x, d);
            }
            return sum;
    }
};

class Solution2 {
public:
        //pair.first return current nestedlist depth, pair second return current sum value of nested list
        void dfs(const vector<NestedInteger>& nestedList, int depth){
            for(auto x:nestedList){
                if(x.isInteger()){
                    m[depth]+=x.getInteger();
                }else{
                    dfs(x.getList(), depth+1);
                }
            }
        }

        int depthSumInverse(vector<NestedInteger>& nestedList) {
            dfs(nestedList, 1);
            if(m.empty())return 0;
            int sum=0;
            int depth=m.rbegin()->first;
            for(auto x:m){
                sum+=x.second*(depth-x.first+1);
            }
            return sum;
        }
    private:
        map<int, int>m;
};
