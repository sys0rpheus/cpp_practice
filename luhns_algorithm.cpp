//so this is the second ever algo that im implementing in C++, it's a very crude implementation of Luhn's algorithm in 16 digit long integers
//it first cleaves the the whole number to to it's constituting integers, saves the same integers in the vec vector, goes through steps 2 and 3
//of the algorithm, adds up the summs from steps 2 and 3, if the output is not divisible by 10 returns back "incorrect", otherwise correct;


//learnt how to stringify an integer, how to push a stringified integer into a vector of integers and lots of other cool stuff.

#include <iostream>
#include <vector>
#include <format>

int main () {
    long long num = 6219861802369560;
    std::vector<int> vec;
    std::vector<int> vec2;
    std::string string_num = std::to_string(num);
    
    for (int i=0; i<string_num.length(); i++){
        vec.push_back(string_num[i] - '0');
    }

    for (int i=0; i<vec.size(); i++) {
        if (i % 2 == 0) {
            vec2.push_back(vec[i] * 2);
        }
    }
    for (int i=0; i<vec2.size(); i++) {
        if (vec2[i]  >= 10) { 
            int total = vec2[i];
            int leftover = total%10;
            int decimal = (total - leftover)/10;
            int temp;
            vec2[i] = decimal;
            vec2.insert(vec2.begin() + i + 1, leftover);
        }
    }
    int sum1 = 0;
    int sum2 = 0; 
    for (int i: vec2) {
        sum1 += i;
    }
    for (int i=1; i<vec.size(); i++){
        if (i%2 == 1) {
            sum2 += vec[i];
        }
    }
    int sum3 = sum1 + sum2;
    if (sum3 % 10 == 0) {
        std::cout << "correct";
    } else {
        std::cout << "incorrect";
    }
}