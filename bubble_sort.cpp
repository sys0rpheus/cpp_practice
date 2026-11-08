//hello folks, so Im learning C++ and how I learn these kind of things is through coding a lot, this is a very basic bubble sort algorithm
//implementation in C++, its not complete complete as BS should not check to the very last member of the vector, but rather one less 
//each step (it gets sorted from end to the begining so no need to do so), this code does not do that, dont use it.


#include <iostream>
#include <vector>
#include <format>

//this function checks to see if any unsorted vaue does remain in the vector, returns a boolean value
bool checker (std::vector<int> nums) {
    int sz = nums.size();

    for (int i=0; i<sz-1; i++) {
        if (nums[i] > nums[i+1]) {
            return false;
        }
    }

    return true;
}

//this function returns a string formatted version of the otuput vector, has a comma at the end that shouldn't have which is oops I guess (:
void printer (auto nums) {
    std::cout << "{";
    for (int num : nums){
    std::cout << num << ","; 
    }
    std::cout << "}\n";
}

int main () {
    //main thing here, you can change the nums vector as you like it
    std::vector<int> nums = {2,4,1,3,5};
    int cnt;
    int nxt;
    bool dn = false;
    int sz = nums.size();

    printer(nums);
    //this while loop and the for loop inside it does the main functionality of the sort, its complexity is O(n^2) which is horrible in long
    //vectors, you can write does a simple srand + rand-omized very populated vector and quickly find out why people dont use bubble sort when
    //time is of essence.
    while (dn == false) {
        int count = 0;
        for (int i=0; i<sz-1; i++) {
            cnt = nums[i];
            nxt = nums[i+1];
            if (cnt > nxt) {
                nums[i] = nxt;
                nums[i+1] = cnt;
                printer(nums);

            }
        }
        dn = checker(nums);
    }
}
//and yeah, that's the whole thing, sorry if it's kinda simple, it was the first algorithm that I coded in C++ after years and years of
//suffering under the yoke of JS (I wouldn't call it freedom moving on, but rather under new administration,
//the new one (C++) has AuDHD too ((: )