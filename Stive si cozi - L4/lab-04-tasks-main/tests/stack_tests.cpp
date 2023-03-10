#include "catch.hpp"
#include "stack.h"
#include "utils.h"
#include "test-utils.hpp"

TEST_CASE("STACK TEST: PUSH, POP & ISEMPTYSTACK FUNCTION WITH A FRAGMENT OF TEXT")
{
    Stack *stack;
    std::stack<char> test_stack;
    std::string word;
    std::string fragment = make_input_from(TASK_TEST_FILENAME);
    std::stringstream ss(fragment);


    createStack(&stack);

    while (ss >> word) {
        if (word != "stop"){
            for(char letter: word) {
                push(stack, letter);
                test_stack.push(letter);
                compare(stack, test_stack);
            }
        } 
    }

}