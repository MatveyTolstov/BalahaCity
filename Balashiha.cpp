// Balashiha.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;
class Human
{
public:

	

	Human(string name, int age, string addres)
	{
		this->name = name;
		this->age = age;
		this->addres = addres;

	}

	~Human()
	{
	}
	string getName() {
		return name;
	}
	int getAge() {
		return age;
	 }
	string getAddress() {
		return addres;
	}
private:
	string name;
	int age;
	string addres;
};
class Balashiha
{
public:
	void createHuman(string name, int age, string addres) {
		try
		{
			
			humanBalaha.push_back(Human(name, age, addres));

			cout << "New person is create!" << endl;
			readHuman();
		}
		catch (const std::exception& e)
		{
			cout << e.what();
		}
		
		
	}

	void deleteHuman(int index) {
		if (index >= 0 && index <= humanBalaha.size())
		{
			humanBalaha.erase(humanBalaha.begin() + index);

			cout << "This person is delete!" << endl;
		}
		else
		{
			cout << "Wrong index!" << endl;
		}
	}
	void updateHuman(string name, int age, string addres, int index) {
		if (index >= 0 && index < humanBalaha.size())
		{
			humanBalaha[index] = { name, age, addres };

			cout << "This person is update!";

		}
		else
		{
			cout << "Wrong index!" << endl;
		}
	}

	void readHuman() {
		for (auto human : humanBalaha)
		{
			cout << "Name:" << human.getName() << endl;
		}
	}

	void sortHumanbyAge() {
		sort(humanBalaha.begin(), humanBalaha.end(), [](Human& a, Human& b) {
			return a.getAge() < b.getAge();
			});
	}

	void sotrHumanbiName() {
		sort(humanBalaha.begin(), humanBalaha.end(), [](Human& a, Human& b) {
			return a.getName() < b.getName();
			});
	}

	void searchHumanByName(string name) {
		bool found = false;

		for (auto& human : humanBalaha) {
			if (human.getName() == name) {
				cout << "Person found:" << endl;
				cout << "Name: " << human.getName() << endl;
				cout << "Age: " << human.getAge() << endl;
				cout << "Address: " << human.getAddress() << endl;
				found = true;
			}
		}

		if (!found) {
			cout << "Person with name '" << name << "' not found." << endl;
		}
	}
	
private:
	vector<Human> humanBalaha;
};

void Interface() {
	string go;
	cin >> go;
	do
	{
		system("cls");
		string name;
		int age;
		string address;
		int index;
		Balashiha balahacity;
		cout << "Select actions" << endl;
		cout << "1.Create new Person\n2.Delete Person\n3.Update Person\n4.Read all Person\n5.Sort by age\n6.Sort by name\n7.Search by name" << endl;
		int choice;

		cin >> choice;
		if (choice == 1)
		{
			cout << "Enter person's name" << endl;
			cin >> name;
			cout << "Enter person's age" << endl;
			cin >> age;
			cout << "Enter person's address" << endl;
			cin >> address;

			balahacity.createHuman(name, age, address);
			cin >> go;
		}
		else if (choice == 2) {
			cout << "Enter person's index" << endl;
			cin >> index;
			balahacity.deleteHuman(index);
		}
		else if (choice == 3) {
			cout << "Enter new person's name" << endl;
			cin >> name;
			cout << "Enter new person's age" << endl;
			cin >> age;
			cout << "Enter new person's address" << endl;
			cin >> address;
			cout << "Enter person's index" << endl;
			cin >> index;
			balahacity.updateHuman(name, age, address, index);
		}
		else if (choice == 4) {
			balahacity.readHuman();
		}
		else if (choice == 5)
		{
			balahacity.sortHumanbyAge();

		}
		else if (choice == 6)
		{
			balahacity.sotrHumanbiName();
		}
		else if (choice == 7) {
			string name;
			cout << "Enter person's name" << endl;
			cin >> name;
			balahacity.searchHumanByName(name);
		}
	} while (go == "go");
}

int main()
{
	Interface();
}

