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

/*******************************************************************************
* constants
*******************************************************************************/
constexpr int NUM_ELEMENTS = 4;
constexpr int RANDINT_LOW = 10;
constexpr int RANDINT_HIGH = 20;
constexpr char RANDCHAR_LOW = 'a';
constexpr char RANDCHAR_HIGH = 'z';

/*******************************************************************************
* local function prototype
*******************************************************************************/
template <typename T>
void countOccurrences(T low, T high, size_t nElements);

/*******************************************************************************
* entry point
*******************************************************************************/
int main()
{
    /*******************************************************************************
    *random number generator
    *******************************************************************************/
    srand(static_cast<unsigned int>(time(0)));

    countOccurrences(RANDINT_LOW, RANDINT_HIGH, NUM_ELEMENTS);

    /*******************************************************************************
    * after converting countOccurrences() to a template function,
    * and after testing the template function with the call above
    * with type int, tests the template function with type char
    *******************************************************************************/
    countOccurrences(RANDCHAR_LOW, RANDCHAR_HIGH, NUM_ELEMENTS);

    return 0;
}

/*******************************************************************************
* generates random numbers and displays count of each
*******************************************************************************/
template <typename T>
void countOccurrences(T low, T high, size_t nElements)
{
    /*******************************************************************************
    * data vector with nElements elements all set to 0
    *******************************************************************************/
    std::vector<T> vData(nElements, 0);

    /*******************************************************************************
    * range for random numbers is between low and high
    *******************************************************************************/
    int modBy = high + 1 - low;

    /*******************************************************************************
    * fill data vector with random elements of type T between (low, high)
    *******************************************************************************/
    for (size_t i = 0; i < nElements; i++)
    {
        T rando = static_cast<T>(rand() % modBy + low);
        vData.at(i) = rando;
    }

    /*******************************************************************************
    * count vector with nElements elements all set to 0
    *******************************************************************************/
    std::vector<size_t> vCounts(nElements, 0);

    /*******************************************************************************
    * count occurrences of each vector element
    *******************************************************************************/
    for (size_t i = 0; i < nElements; i++)
    {
        /*******************************************************************************
        * value to search vData for
        *******************************************************************************/
        T element = vData.at(i);

        for (size_t k = 0; k < nElements; k++)
        {
            if (vData.at(k) == element)
                vCounts.at(k)++;
        }
    }

    /*******************************************************************************
    * display each vector element and how many times it occurs in vector
    *******************************************************************************/
    for (size_t i = 0; i < nElements; i++)
    {
        std::cout << "Element: " << vData.at(i)
            << " occurs " << vCounts.at(i) << " times\n";
    }
}