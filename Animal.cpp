#include<iostream>
#include<string>

using namespace std;

class Animal
{
protected:
	int id;
public:
	Animal()
	{
		id = 0;
		cout << "Animal Default Constructor" << endl;
	}

	Animal(int id_0)
	{
		this->id = id_0;
		cout << "Animal Parametrized constrcutor" << endl;
	}
	~Animal()
	{
		cout << "Animal Destructor" << endl;
	}

	void setid(int id_1)
	{
		id = id_1;
	}

	int getid()
	{
		return id;
	}

	void tellAboutSelf()
	{
		cout << "Animal's Object" << endl;
	}

	void speak()
	{
		cout << "I am Animal, I can’t speak…" << endl;
	}
};

class Reptile : public Animal
{
public:
	Reptile()
	{
		id = 1;
		cout << "Reptile default Constructor" << endl;
	}

	Reptile(int id_2) : Animal(id_2)
	{
		cout << "Reptile parameterized Constructor" << endl;
	}

	~Reptile()
	{
		cout << "Reptile destructor" << endl;
	}

	void tellAboutSelf()
	{
		cout << "Reptile's Object" << endl;
	}

	void speak()
	{
		cout << "Family of Reptiles…" << endl;
	}
};

class Bird : public Animal
{
public:
	Bird()
	{
		id = 2;
	}

	Bird(int id_3) : Animal(id_3)
	{
		cout << "Bird parameterized Constructor" << endl;
	}

	~Bird()
	{
		cout << "Bird destructor" << endl;
	}

	void tellAboutSelf()
	{
		cout << "Bird's Object" << endl;
	}

	void speak()
	{
		cout << "Family of Birds…" << endl;
	}

};

class Mammal : public Animal
{
public:
	Mammal()
	{
		id = 3;
	}

	Mammal(int id_4) : Animal(id_4)
	{
		cout << "Bird parameterized Constructor" << endl;
	}

	~Mammal()
	{
		cout << "Bird destructor" << endl;
	}

	void tellAboutSelf()
	{
		cout << "Mammal's Object" << endl;
	}

	void speak()
	{
		cout << "Family of Mammals…" << endl;
	}
};

class Snake : public Reptile
{
public:
	int getFamily()
	{
		return Animal::getid();
	}

	void speak()
	{
		cout << "Shhhh…" << endl;
	}
};

class Parrot : public Bird
{
public:
	int getFamily()
	{
		return Animal::getid();
	}

	void speak()
	{
		cout << "Trrrrrr…" << endl;
	}
};

class Horse : public Mammal
{
public:
	int getFamily()
	{
		return Animal::getid();
	}

	void speak()
	{
		cout << "Hurrrrrrr…" << endl;
	}
};


int main()
{
	Animal objA;
	Reptile objR;
	Bird objB;
	Mammal objM;
	Snake objS;
	Parrot objP;
	Horse objH;

	cout << endl;

	cout << objA.getid() << endl;
	cout << objR.getid() << endl;
	cout << objB.getid() << endl;
	cout << objM.getid() << endl;
	cout << objS.getid() << endl;
	cout << objP.getid() << endl;
	cout << objH.getid() << endl;

	cout << endl;


	objA.speak();
	objR.speak();
	objB.speak();
	objM.speak();
	objS.speak();
	objP.speak();
	objH.speak();

	cout << endl;

	objA.tellAboutSelf();
	objR.tellAboutSelf();
	objB.tellAboutSelf();
	objM.tellAboutSelf();

	cout << endl;


	return EXIT_SUCCESS;
}
