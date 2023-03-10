#include "test-utils.hpp"

std::vector<int> beforeEach(const char *test_task_data)
{
	std::ifstream file(test_task_data);
	std::vector<int> listData;
	int cdata;
	while (file >> cdata)
	{
		int length = listData.size();
		if (length > 0 && listData[length - 1] <= cdata)
		{
			listData.push_back(cdata);
		}
		else if (length == 0)
		{
			listData.push_back(cdata);
		}
	}

	return listData;
}

node *studentTaskSetUp(const char *test_task_data)
{
	FILE *f = openFile(test_task_data, READ_MODE);
	REQUIRE(isNotNull(f));
	node *list = makeList(f);
	REQUIRE(isNotNull(list));
	return list;
}

childNode *studentGameTaskSetup(const char *test_task_data)
{
	FILE *f = openFile(test_task_data, READ_MODE);
	REQUIRE(isNotNull(f));
	childNode *list = makeCircularList(f);
	REQUIRE(isNotNull(list));
	return list;
}

std::vector<childNode> beforeGame(const char *test_task_data)
{
	std::ifstream file(test_task_data);
	std::vector<childNode> listData;
	int nr;
	std::string name;
	while (file >> nr >> name)
	{
		childNode child;
		child.name = strdup(name.c_str());
		child.number = nr;
		listData.push_back(child);
	}

	return listData;
}