//
//  342_power_of_four.cpp
//  leetcode_bit_manipulation
//
//  Created by Hadley on 07.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        for(int i=0;i<32;i++){
            if(n==1<<i){
                if(!(n&1<<31)){
                    if(!i%2){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
