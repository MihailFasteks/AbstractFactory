#include <iostream>
using namespace std;

/*
Абстрактная фабрика - порождающий паттерн проектирования,
который предоставляет интерфейс для создания семейств взаимосвязанных или взаимозависимых объектов,
не специфицируя их конкретных классов.

Применимость
- система не должна зависеть от того, как создаются, компонуются и представляются входящие в нее объекты;
- входящие в семейство взаимосвязанные объекты должны использоваться вместе и необходимо обеспечить выполнение этого ограничения;
- система должна конфигурироваться одним из семейств составляющих ее объектов;
- необходимо предоставить библиотеку объектов, раскрывая только их интерфейсы, но не реализацию.

Паттерн абстрактная фабрика обладает следующими плюсами и минусами:
 * изолирует конкретные классы.
 * упрощает замену семейств продуктов.
 * гарантирует сочетаемость продуктов.
 * поддержать новый вид продуктов трудно.
*/

// AbstractProductA(Weapon) - объявляет интерфейс(абстрактный класс) для типа объекта-продукта
// абстрактный класс - оружие
class Herbivore abstract
{
protected:
	int weight;
	bool isAlive;
public:
	 virtual void EatGrass() abstract;
	 virtual int GetWeight() abstract;
};

// ConcreteProductA1(Arbalet)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
// класс арбалет
class Wildebeest : public Herbivore
{
public:
	Wildebeest(int w) {
		weight = w;
		isAlive = true;
	}
	~Wildebeest() {
		isAlive = false;
	}
	void EatGrass() override
	{
		cout << this->weight << endl;
		this->weight+=10;
	
		cout << "Herbivore weight+10"<<endl;
		cout << this->weight << endl;
	
	}
	int GetWeight()override {
		return weight;
	 }
};

// ConcreteProductA2(Sword)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
// класс меч
class Bison : public Herbivore
{
public:
	Bison(int w) {
		weight = w;
		isAlive = true;
	}
	~Bison() {
		isAlive = false;
	}
	void EatGrass() override
	{
		cout << this->weight << endl;
		this->weight += 10;
		
		cout << "Herbivore weight+10" << endl;
		cout << this->weight << endl;
	}
	int GetWeight()override {
		return weight;
	}
};
class Elk : public Herbivore
{
public:
	Elk(int w) {
		weight = w;
		isAlive = true;
	}
	~Elk() {
		isAlive = false;
	}
	void EatGrass() override
	{
		cout << this->weight << endl;
		this->weight += 10;
		
		cout << "Herbivore weight+10"<<endl;
		cout << this->weight << endl;
	}
	int GetWeight()override {
		return weight;
	}
};

// AbstractProductB(Movement) - объявляет интерфейс(абстрактный класс) для типа объекта-продукта
// абстрактный класс движение
class Carnivore abstract
{
protected:
	int power;
public:
	virtual void Eat(Herbivore *h) abstract;
};

// ConcreteProductB1(FlyMovement)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
// полет
class Lion : public Carnivore
{
public:
	Lion(int w) {
		this->power = w;
	
	}
	
	void Eat(Herbivore *h) override
	{
		if ((this->power) < h->GetWeight()) {
			this->power =- 10;
		}
		else {
			this->power =+ 10;
		}
	}
};

// ConcreteProductB2(RunMovement)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
// бег
class Wolf : public Carnivore
{
public:
	Wolf(int w) {
		this->power = w;

	}

	void Eat(Herbivore* h) override
	{
		if ((this->power) < h->GetWeight()) {
			this->power =- 10;
		}
		else {
			this->power =+ 10;
		}
	}
};
class Tiger : public Carnivore
{
public:
	Tiger(int w) {
		this->power = w;

	}

	void Eat(Herbivore* h) override
	{
		if ((this->power) < h->GetWeight()) {
			this->power =- 10;
		}
		else {
			this->power =+ 10;
		}
	}
};

/* 
AbstractFactory(HeroFactory) - объявляет интерфейс для операций, создающих абстрактные объекты-продукты
*/

// класс абстрактной фабрики
class Continent abstract
{
public:
	virtual Carnivore* CreateCarnivore(int w) abstract;
	virtual  Herbivore* CreateHerbivore(int w) abstract;
};

/* 
ConcreteFactory1(ElfFactory) - реализует операции, создающие конкретные объекты-продукты
 */
// Фабрика создания летящего героя с арбалетом
class Africa : public Continent
{
public:
	Carnivore* CreateCarnivore(int w) override
	{
		return new Lion(w);
	}
	Herbivore* CreateHerbivore(int w) override
	{
		return new Wildebeest(w);
	}
};

/* ConcreteFactory2(WarriorFactory) - реализует операции, создающие конкретные объекты-продукты
 */
// Фабрика создания бегущего героя с мечом
class NorthAmerica : public Continent
{
public:
	Carnivore* CreateCarnivore(int w) override
	{
		return new Wolf(w);
	}
	Herbivore* CreateHerbivore(int w) override
	{
		return new Bison(w);
	}
};

class Eurasia : public Continent
{
public:
	Carnivore* CreateCarnivore(int w) override
	{
		return new Tiger(w);
	}
	Herbivore* CreateHerbivore(int w) override
	{
		return new Elk(w);
	}
};

// Cистема не должна зависеть от того, как создаются, компонуются и представляются входящие в нее объекты
// клиент - сам супергерой
class WorldOFAnimals
{
	Herbivore* herbivore;
	Carnivore* carnivore;
public:
	WorldOFAnimals(Continent* continent, int herbW, int carnW)
	{
		herbivore = continent->CreateHerbivore(herbW);
		carnivore = continent->CreateCarnivore(carnW);
	}
	void CarnivoreEat()
	{
		carnivore->Eat(herbivore);
	}
	void HerbivoreEat()
	{
		herbivore->EatGrass();
	}
};

void main()
{
	Continent* continent = new Africa();
	WorldOFAnimals *worldOfAnimals = new WorldOFAnimals(continent, 120, 140);
	worldOfAnimals->CarnivoreEat();
	worldOfAnimals->HerbivoreEat();
	delete continent;
	delete worldOfAnimals;

	continent = new NorthAmerica();
	worldOfAnimals = new WorldOFAnimals(continent, 110, 120);
	worldOfAnimals->CarnivoreEat();
	worldOfAnimals->HerbivoreEat();
	delete continent;
	delete worldOfAnimals;

	continent = new Eurasia();
	worldOfAnimals = new WorldOFAnimals(continent, 90, 100);
	worldOfAnimals->CarnivoreEat();
	worldOfAnimals->HerbivoreEat();
	delete continent;
	delete worldOfAnimals;

	system("pause");
}
