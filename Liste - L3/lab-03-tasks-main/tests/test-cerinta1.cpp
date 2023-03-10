#include "test-utils.hpp"


TEST_CASE("Cerinta 1: Creati o lista - direct in forma ordonata! ")
{
	std::vector<int> data = beforeEach(TASK1_TEST_FILENAME);
	node *list = studentTaskSetUp(TASK1_TEST_FILENAME);

	SECTION("Aceeasi dimensiune ?")
	{
		unsigned int len = 0;
		while (isNotNull(list))
		{
			list = list->next;
			len++;
		}
		REQUIRE(len == data.size());
	}

	SECTION("Elementele se afla in ordinea buna ?")
	{
		for (auto elem = data.rbegin(); elem != data.rend(); elem++)
		{
			REQUIRE(*elem == list->data);
			list = list->next;
		}
	}
}


