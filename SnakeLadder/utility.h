#pragma once
#include<iostream>
#include<random>
using namespace std;

int randomNumber(int min, int max){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribution(min, max);
    return distribution(gen);
}