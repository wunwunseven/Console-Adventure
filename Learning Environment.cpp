//fully annotate this program so when i come back to it. I fully understand each process.

//Inventory System 

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

std::string createRandomItem();
void pickUp(std::vector<std::string> &inventory);
std::string getInputMenu(std::string &input);
void inputLogic(std::string input, std::vector<std::string> &inventory);
void dropItem(std::vector<std::string> &inventory);

int main()
{
	srand(time(NULL));
	std::string input = " ";
	std::vector<std::string> playerInventory;

	while (playerInventory.size() < 10)
	{
		inputLogic(getInputMenu(input), playerInventory);
	}
	
	system("cls");
	std::cout << "You maxed your inventory!\n";
	return 0;
}

std::string createRandomItem()
{
	std::vector<std::string> itemList;
	itemList.push_back("sword"); itemList.push_back("spear");
	itemList.push_back("maul"); itemList.push_back("dagger");
	itemList.push_back("shield"); itemList.push_back("potion");
	itemList.push_back("armor"); itemList.push_back("helmet");

	return itemList[rand() % itemList.size()];
}
void pickUp(std::vector<std::string> &inventory)
{
	inventory.push_back(createRandomItem());
	std::cout << "You picked up a " << inventory[inventory.size() - 1] << "! \n";
}
std::string getInputMenu(std::string &input)
{
	system("cls");
	std::cout << "What do you want to do: \n";
	std::cout << "Pick up item / Show inventory / Drop an item\n";
	getline(std::cin, input);

	return input;
}
void inputLogic(std::string input, std::vector<std::string> &inventory)
{
	if (input == "Pick up item")
	{
		system("cls");
		pickUp(inventory);
		system("pause");
	}
	else if (input == "Show inventory")
	{
		system("cls");
		std::cout << "Your current items are: \n";
		for (auto &a : inventory)
		{
			std::cout << a << "\n";
		}
		system("pause");
	}
	else if (input == "Drop an item")
	{
		dropItem(inventory);
	}

}
void dropItem(std::vector<std::string> &inventory)
{
	std::string itemName;
	system("cls");
	std::cout << "What item do you want to drop? \n";
	getline(std::cin, itemName);

	int itemFound = false;

	for (auto &a : inventory)
	{
		int count = 0;
		if (itemName == a)
		{
			system("cls");
			itemFound = true;
			std::cout << a << " removed! \n";
			inventory.erase(inventory.begin() + count);
			system("pause");
		}
		count++;
	}
	if (!itemFound)
	{
		std::cout << "You don't have that item!\n";
		system("pause");
	}
	
	


}