#include "catch.hpp"
#include "utils.h"
#include "test-utils.hpp"
#include "counting.h"

TEST_CASE("BONUS: Counting Sort - Test")
{
    FILE *file = openFile(BONUS_FILENAME, READ_MODE);
    int size = 0;
    int *arr = readArray(file, &size);

    int *vf = NULL;
    vf = countingSort(arr, size);

    SECTION("Sortarea crescatoare a vectorului") {
        for (int i = 0; i < size - 1; i++) {
            REQUIRE(arr[i] <= arr[i + 1]);
        }
    }
    
    SECTION("Validitatea vectorului de frecventa") {
        map<int, int> M;

        for (int i = 0; i < arr[i]; i++) {
            if (M.find(arr[i]) == M.end()) {
                M[arr[i]] = 1;
            }
            else {
                M[arr[i]]++;
            }
        }

        for (auto& it : M) {
            REQUIRE(vf[it.first] == it.second);
        }
    }
}