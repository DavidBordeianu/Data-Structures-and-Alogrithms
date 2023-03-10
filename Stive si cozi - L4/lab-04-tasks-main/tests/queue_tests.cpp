#include "catch.hpp"
#include "queue.h"
#include "utils.h"
#include "test-utils.hpp"


TEST_CASE("QUEUE TEST: EN, DE & ISEMPTYQUEUE FUNCTION WITH A FRAGMENT OF TEXT")
{
    Queue *queue;
    std::queue<std::string> test_queue;
    std::string word;
    std::string fragment = make_input_from(TASK_TEST_FILENAME);
    std::stringstream ss(fragment);


    createQueue(&queue);

    while (ss >> word) {
        if (word != "stop") {
            en(queue, const_cast<char *>(word.c_str()));
            test_queue.push(word);
        }
    }
    compare(queue,test_queue);

}