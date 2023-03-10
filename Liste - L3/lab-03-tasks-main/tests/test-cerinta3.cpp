#include "test-utils.hpp"

TEST_CASE("Cerinta 3: Jocul lui Joseph cu p = 2")
{
    std::vector<childNode> data = beforeGame(TASK3_TEST_FILENAME);
    std::vector<childNode> reversedData(data.rbegin(), data.rend());
    childNode *list = studentGameTaskSetup(TASK3_TEST_FILENAME);
    int p = 2;
    REQUIRE(isNotNull(list));

    SECTION("Lista are numarul corect de elemente ?")
    {
        list = playJosephGame(list, p);
        unsigned int len = 0;
        while (isNotNull(list))
        {
            len++;
            list = list->next;
        }
        REQUIRE(len == reversedData.size());
    }

    SECTION("Copii au fost eliminati in ordinea corecta ?")
    {
        list = playJosephGame(list, p);
        int step = 0;
        std::vector<childNode> childs;
        std::list<childNode> childList(reversedData.begin(), reversedData.end());

        for (auto it = childList.begin(); it != childList.end();)
        {
            step++;
            if (step == p)
            {
                childs.push_back(*it);
                it = childList.erase(it);
                step = 0;
            }
            else
            {
                ++it;
            }
            if (childList.size() != 1 && it == childList.end())
            {
                it = childList.begin();
            }
            else if (childList.size() == 1)
            {
                childs.push_back(*childList.begin());
                break;
            }
        }
        for (auto it = childs.rbegin(); it != childs.rend(); ++it)
        {
            std::cout << "found: " << list->name << " - expected:  " << it->name << std::endl;
            REQUIRE(strcmp(it->name, list->name) == 0);
            list = list->next;
        }
    }
}