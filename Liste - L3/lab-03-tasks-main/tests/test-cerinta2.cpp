#include "test-utils.hpp"



TEST_CASE("Cerinta 2: Creati o metoda ce elimina duplicatele din lista. - fara duplicat la sfarsitul listei")
{
	std::vector<int> data = beforeEach(TASK2_TEST_FILENAME1);
	std::set<int> uniques(data.begin(),data.end());
	node *list = studentTaskSetUp(TASK2_TEST_FILENAME1);
	list = removeDuplicates(list);

	SECTION("Sa eliminat numarul corect de elemente duplicate ?")
	{
		unsigned int len = 0;
		while (isNotNull(list))
		{
			list = list->next;
			len++;
		}
		REQUIRE(len == uniques.size());
	}

	SECTION("Se elimina elementele corecte ?") {
		for(auto elem = uniques.rbegin(); elem != uniques.rend(); elem++){
			REQUIRE(*elem == list->data);
			list = list->next;
		}
	}
}

TEST_CASE("Cerinta 2: Creati o metoda ce elimina duplicatele din lista. - cu duplicat la sfarsitul listei")
{
	std::vector<int> data = beforeEach(TASK2_TEST_FILENAME2);
	std::set<int> uniques(data.begin(),data.end());
	node *list = studentTaskSetUp(TASK2_TEST_FILENAME2);
	list = removeDuplicates(list);

	SECTION("Sa eliminat numarul corect de elemente duplicate ?")
	{
		unsigned int len = 0;
		while (isNotNull(list))
		{
			list = list->next;
			len++;
		}
		REQUIRE(len == uniques.size());
	}

	SECTION("Se elimina elementele corecte ?") {
		for(auto elem = uniques.rbegin(); elem != uniques.rend(); elem++){
			REQUIRE(*elem == list->data);
			list = list->next;
		}
	}
}
