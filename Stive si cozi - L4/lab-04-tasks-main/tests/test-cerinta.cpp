#include "catch.hpp"
#include "test-utils.hpp"
#include "functions.h"

TEST_CASE("Test the string processing using the implemented functions")
{
    Queue *queue;
    Stack *results;
    FILE *file = NULL;
    std::string input;
    std::stack<char> test_stack;

    SECTION("Easy input!")
    {
        createQueue(&queue);
        createStack(&results);
        input = make_input_from(TEST1_FILE);
        test_stack = process(input);
        std::stack<char> stk =  reverse(test_stack);
        file = openFile(TEST1_FILE, READ_MODE);
        REQUIRE(isEmptyQueue(queue) == true);
        readInputIn(queue, file);
        REQUIRE(isEmptyQueue(queue) == false);
        processInput(queue, results);
        compare(results, test_stack);
    }
    SECTION("Hard input!")
    {
        createQueue(&queue);
        createStack(&results);
        input = make_input_from(TEST2_FILE);
        test_stack = process(input);
        std::stack<char> stk =  reverse(test_stack);
        file = openFile(TEST2_FILE, READ_MODE);
        REQUIRE(isEmptyQueue(queue) == true);
        readInputIn(queue, file);
        REQUIRE(isEmptyQueue(queue) == false);
        processInput(queue, results);
        compare(results, test_stack);
    }
}