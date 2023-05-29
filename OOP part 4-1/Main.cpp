#include <iostream>
#include <vector>
// UTF-8
// Принципы SOLID

// S - Single-responsibility principe - принцип единой ответственности.
/* Класс, который выполняет только одну функцию
class ClientServer
{
public:
	void ShowCLients(std::vector<Client*>clients)
	{
		for (const auto& it : clients)
			it->Pay();
	}
};
*/

// O - open-closed principle - функция открыта для расширения, но закрыта для модификации
/*
class Animal
{
private:
	std::string _type;
public:
	Animal(std::string type) : _type(type) { }
	virtual std::string GetSound() = 0; //const {
	//	return _type;
	//}
};

class Cow : public Animal
{
public:
	Cow() : Animal ("Cow"){ }
	std::string GetSound() override
	{
		return "MYMMYM";
	}
};

class Cat : public Animal
{
public:
	Cat() : Animal("Cat") { }
	std::string GetSound() override 
	{
		return "MEOW";
	}
};

class Dog : public Animal
{
public:
	Dog() : Animal("Dog") { }
	std::string GetSound() override 
	{
		return "GAV";
	}
};


void AnimalSound(Animal& animal) 
{
	std::cout << animal.GetSound() << "\n\n"; // правильно
//	 Это противоречит принципу
//	if (animal.GetType() == "Lion")
//		std::cout << "RRRRR";
//	else if (animal.GetType() == "Cat")
//		std::cout << "MRRR";
//	else if (animal.GetType() == "Dog")
//		std::cout << "GAV";
//	else if (animal.GetType() == "Cow")
//		std::cout << "MYMYMYM";
		
}
*/

class Vector
{
private:
	int _size;
	int* _massivPtr;
public:
	Vector()
	{
		_size = 0;
		_massivPtr = nullptr;
	}

	void Push_back(int element)
	{
		_size++;
		int *newMassiv = new int[_size];
		if (_massivPtr == nullptr)
		{
			newMassiv[0] = element;
			_massivPtr = newMassiv;
			return;
		}
		
		for (int i{}; i < _size - 1; ++i)
			newMassiv[i] = _massivPtr[i];

		newMassiv[_size - 1] = element;

		delete[]_massivPtr;
		//int* temp = _massivPtr;
		_massivPtr = newMassiv;
			 
	}

	void ShowElements()
	{
		for (int i = 0; i < _size; i++)
			std::cout << i << " элемент: " << _massivPtr[i] << '\n';
	}
};


int main() {

	setlocale(LC_ALL, "Russian");

	Vector* vector = new Vector();
	vector->Push_back(20);
	vector->Push_back(223);
	vector->Push_back(123);
	vector->Push_back(77);
	vector->Push_back(90);
	vector->ShowElements();

	// Пример с принципом О
	/*Cat* cat = new Cat();
	Dog* dog = new Dog();
	Cow* cow = new Cow();
	AnimalSound(*cat);
	AnimalSound(*dog);
	AnimalSound(*cow);*/


	return 0;
}