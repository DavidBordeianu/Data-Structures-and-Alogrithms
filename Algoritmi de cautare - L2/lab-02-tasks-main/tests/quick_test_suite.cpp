#include "catch.hpp"
#include "utils.h"
#include "test-utils.hpp"
#include "quick.h"

TEST_CASE("Quick Sort - Test 1: 10 elemente")
{
    FILE *file = openFile(TEST1_FILENAME, READ_MODE);
    int size = 0;
    int *arr = readArray(file, &size);

    quicksort(arr, 0, size - 1);

    for (int i = 0; i < size - 1; i++) {
        REQUIRE(arr[i] <= arr[i + 1]);
    }
}

TEST_CASE("Quick Sort - Test 2: 100 elemente")
{
    FILE *file = openFile(TEST2_FILENAME, READ_MODE);
    int size = 0;
    int *arr = readArray(file, &size);

    quicksort(arr, 0, size - 1);

    for (int i = 0; i < size - 1; i++) {
        REQUIRE(arr[i] <= arr[i + 1]);
    }
}

TEST_CASE("Quick Sort - Test 3: 1000 elemente")
{
    FILE *file = openFile(TEST3_FILENAME, READ_MODE);
    int size = 0;
    int *arr = readArray(file, &size);

    quicksort(arr, 0, size - 1);

    for (int i = 0; i < size - 1; i++) {
        REQUIRE(arr[i] <= arr[i + 1]);
    }
}