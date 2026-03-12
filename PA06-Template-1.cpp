//------------------------------------------------------------------------------
// PA06-Template-1.cpp
// 
// -Generates random values between passed high and low, inclusive
// -Counts occurrences of each random value
// -Displays values and counts
//------------------------------------------------------------------------------
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int RANDINT_LOW = 10;
constexpr int RANDINT_HIGH = 20;
constexpr char RANDCHAR_LOW = 'a';
constexpr char RANDCHAR_HIGH = 'z';

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void countOccurrences(int low, int high, size_t nElements);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main()
{
    // seed random number generator
    srand(static_cast<unsigned int>(time(0)));

    countOccurrences(10, 20, 4);

    return 0;
}

//------------------------------------------------------------------------------
// generates random numbers and displays occurrence count of each
//------------------------------------------------------------------------------
void countOccurrences(int low, int high, size_t nElements)
{
    // data vector with nElements elements all set to 0
    std::vector<int> vData(nElements, 0);

    int modBy = high + 1 - low;

    // fill data vector with random elements of type T between (low, high)
    for (size_t i = 0; i < nElements; i++)
    {
        int rando = rand() % modBy + low;
        vData.at(i) = rando;
    }

    // count vector with nElements elements all set to 0
    std::vector<size_t> vCounts(nElements, 0);

    // count occurrences of each vector element
    for (size_t i = 0; i < nElements; i++)
    {
        // value to search vData for
        int element = vData.at(i);

        for (size_t k = 0; k < nElements; k++)
        {
            if (vData.at(k) == element)
                vCounts.at(k)++;
        }
    }

    // display each vector element and how many times it occurs in vector
    for (size_t i = 0; i < nElements; i++)
    {
        std::cout << "Element: " << vData.at(i)
            << " occurs " << vCounts.at(i) << " times\n";
    }
}
