/**
 * @brief in this file are defined all the common functions used in the
 * 		  test suite
 * @author Rusu Gabriel
 * 
 */
#include "catch.hpp"
#include "test-utils.hpp"

std::string make_input_from(const char *filename)
{
    std::ifstream file(filename);
    std::string line;
    std::string fragment;

    while (std::getline(file, line))
        fragment += line + " ";
    return fragment;
}

void compare(Stack *stack, std::stack<char> &test_stack)
{
    long no_letters = test_stack.size();
    REQUIRE(isEmptyStack(stack) == false);
    while (no_letters--)
    {
        REQUIRE(test_stack.top() == pop(stack));
        test_stack.pop();
    }
}

void compare(Queue *queue, std::queue<std::string> &test_queue)
{
    long no_words = test_queue.size();
    REQUIRE(isEmptyQueue(queue) == false);
    while (no_words--)
    {
        REQUIRE(test_queue.front() == de(queue));
        test_queue.pop();
    }
}

std::stack<char> process(std::string &input)
{
    std::stack<char> stack;
    std::stringstream ss(input);
    std::string word;
    while (ss >> word)
    {
        if(word=="stop")
            break;
        for (char &letter : word) {
            stack.push(letter);
        }
    }
    return stack;
}

std::stack<char> reverse(std::stack<char>& test_stack) {
    std::stack<char> reversed;
    long size = test_stack.size();
    while(size--) {
        char letter = test_stack.top();
        reversed.push(letter);
        test_stack.pop();
    }
    return reversed;
}