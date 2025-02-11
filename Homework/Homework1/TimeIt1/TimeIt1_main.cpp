/*
Program: Homework 1 - Time It
Author: Rebecca Morgan
Date: 24th January 2020
Description: Making a stopwatch. 
*/

#include "TimeIt1.h"

struct SearchResult 
{
    double generate;
    double standard;
    double binary;
    double sort;
    double shuffle;
};

std::random_device r;
std::default_random_engine engine(r());
std::uniform_int_distribution<int> randomDist(INT32_MIN, INT32_MAX);

SearchResult batch(int elements) 
{
    StopWatch timer;
    std::vector<int> target = { randomDist(engine) };
    SearchResult res;

    //Generate numbers.
    std::cout << "Generating dataset of " << elements << " elements.\n" <<
        std::string(15 - std::to_string(elements).size(), ' ');
    timer.start();
    std::vector<int> nums;
    for (int x = 0; x < elements; x++) 
    {
        nums.push_back(randomDist(engine));
    }

    timer.stop();
    res.generate = timer.Milli();
    std::cout << timer.Seconds() << " seconds. (" << timer.Milli() << "ms)" << std::endl;

    //Sort the numbers.
    std::cout << "Sorting dataset.\n";
    timer.start();
    std::sort(nums.begin(), nums.end());
    timer.stop();

    res.sort = timer.Milli();
    std::cout << timer.Seconds() << " seconds. (" << timer.Milli() << "ms)" << std::endl;

    //Standard search.
    std::cout << "Searching numbers with standard search.\n";
    timer.start();
    std::search(nums.begin(), nums.end(), target.begin(), target.end());
    timer.stop();
    res.standard = timer.Milli();
    std::cout << timer.Seconds() << " seconds. (" << timer.Milli() << "ms)" << std::endl;

    //Binary search.
    std::cout << "Searching numbers with binary search.\n";
    timer.start();
    std::binary_search(nums.begin(), nums.end(), target[0]);
    timer.stop();
    res.binary = timer.Milli();
    std::cout << timer.Seconds() << " seconds. (" << timer.Milli() << "ms)" << std::endl;

    // Shuffle the nums
    std::cout << "Shuffling numbers.\n";
    timer.start();
    std::shuffle(nums.begin(), nums.end(), engine);
    timer.stop();
    res.shuffle = timer.Milli();
    std::cout << timer.Seconds() << " seconds. (" << timer.Milli() << "ms\n" << std::endl;

    return res;
}

int main() {
    std::vector<std::vector<SearchResult>> results;
    int numSize = 5;

    int j = 1;
    for (int i = 0; i < numSize; i++) {
        std::vector<SearchResult> trialResults;
        j *= 10;
        for (int trial = 0; trial < 5; trial++) {
            trialResults.push_back(batch(j));
        }
        results.push_back(trialResults);
    }

    int q = 1;
    for (auto set : results) {
        q *= 10;
        std::cout << q << ",,,,\nGenerate, Sort, Standard, Binary, Shuffle\n";
        for (auto result : set) {
            std::cout << result.generate << ',' << result.sort << ',' << result.standard
                << ',' << result.binary << ',' << result.shuffle << '\n';
        }
        std::cout << std::endl;
    }
}