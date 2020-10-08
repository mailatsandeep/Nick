// UniquePtrExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "memory"
#include "vector"
using namespace std;

// Use of unique_ptr
class Person
{
public:
	char* m_chName;
	int m_nAge;
public:
	Person(char* name, int age) : m_chName(name), m_nAge(age){
		cout << "constructor" << endl;
	}
	void Display(){
		cout << "Now the name is --> " << m_chName << endl << "and age is --> " << m_nAge << endl;
	}
	virtual ~Person(){
	}
};
unique_ptr<Person> MakeUniquePersonFunction(char* personName, int age){
	// Implicit move operation into the variable that stores the result.
	return make_unique<Person>(personName, age);
}
void fun(Person & obj){
	obj.Display();
}
int main(){
	auto uniquePtr = make_unique<Person>((char*)"Saanvi", 6);
	auto uniquePtr1 = MakeUniquePersonFunction("SethaLal", 6);
	unique_ptr<Person> uniquePtr2 = make_unique<Person>((char*)"Bantu", 36);
	// use of unique_ptr
	uniquePtr->Display();
	uniquePtr1->Display();
	uniquePtr2->Display();
	// asign the ownership
	{
		auto newOwner = std::move(uniquePtr);
		newOwner->Display();
		//uniquePtr->Display(); will give error now because ownership is transferred
		vector<unique_ptr<Person>> personVector;
		//personVector.push_back(std::move(newOwner));
		personVector.push_back(std::move(uniquePtr1));
		personVector.push_back(make_unique<Person>((char*)"Jyoti", 32));
		personVector.push_back(std::move(uniquePtr2));
		for (auto& personobj : personVector) {
			personobj->Display();
		}
		fun(*newOwner);
	}
	return 0;
}