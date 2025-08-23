/*

BUILDER: implementation that allows instantiate a complex object, step by step.

It can be divided in:

* Builder Interface: define common methods for Concrete Builders.

* Product: class used to create the product of the Concrete Builder.

* Concrete Builder: create (step by step) and return a speficic product
(when it is required, otherwise return itself).

* Director: contains set ones of instructios to create specific Products,
base in a specific Concrete Builder.

*/

#include <cstdio>

// Builder "interface"
class Builder
{
protected:
	virtual void new_product(void) = 0;
	virtual void delete_product(void) = 0;
	virtual void reset_product(void) = 0;

	// Implement manually in derived classes:
	// <product> build(void);
	// void reset(void); // optional
};

// Product
class Entity
{
	friend class EntityBuilder;

private:
	int x, y;
	int width, height;
	short speed, minspeed, maxspeed;
	short hp, maxhp;

public:
	// Explicit empty constructor
	Entity(void)
	{}

	// This is needed for this
	// Builder implementation
	Entity(const Entity &other) = default;

	void info(void) const
	{
		printf("Positions: %d, %d\nDimensions: %dx%d\nSpeed (%d-%d): %d\nHP (max: %d): %d\n\n", this->x, this->y, this->width, this->height, this->minspeed, this->maxspeed, this->speed, this->maxhp, this->hp);
	}
};

// Concrete builder
class EntityBuilder final: protected Builder
{
private:
	Entity *product;

protected:
	void new_product(void) override
	{
		this->product = new Entity();
	}

	void delete_product(void) override
	{
		delete this->product;
	}

	void reset_product(void) override
	{
		this->delete_product();
		this->new_product();
	}

public:
	EntityBuilder(void)
	{
		this->new_product();
	}

	// For this Builder implementation,
	// destructors are illegal.
	// ~EntityBuilder(void)
	// {}
	
	Entity* build(void)
	{
		Entity *tmp = new Entity( *(this->product) );
		this->delete_product(); // destructor be like

		// This is safe, see:
		// https://isocpp.org/wiki/faq/freestore-mgmt#delete-this
		delete this;

		return tmp;
	}

	void reset(void)
	{
		this->reset_product();
	}

	EntityBuilder* set_position(int x, int y)
	{
		this->product->x = x;
		this->product->y = y;
		return this;
	}

	EntityBuilder* set_dimensions(int w, int h)
	{
		this->product->width  = w;
		this->product->height = h;
		return this;
	}

	EntityBuilder* set_speed(short normal, short min, short max)
	{
		this->product->speed    = normal;
		this->product->minspeed = min;
		this->product->maxspeed = max;
		return this;
	}

	EntityBuilder* set_hp(short max)
	{
		this->product->hp    = max;
		this->product->maxhp = max;
		return this;
	}
};

// Director
class EntityDirector final
{
public:
	static Entity* slime(void)
	{
		return (new EntityBuilder())
			->set_position(0, 0)
			->set_dimensions(50, 35)
			->set_speed(15, 2, 30)
			->set_hp(10)
			->build();
	}

	static Entity* zombie(void)
	{
		return (new EntityBuilder())
			->set_position(0, 0)
			->set_dimensions(55, 80)
			->set_speed(20, 5, 50)
			->set_hp(30)
			->build();
	}
};

// Client code
int main(void){
	Entity *player = (new EntityBuilder)
		->set_hp(100)
		->set_position(0, 0)
		->set_speed(45, 1, 150)
		->set_dimensions(55, 80)
		->build();

	Entity *zombie = EntityDirector::zombie();

	player->info();
	zombie->info();

	delete player, zombie;
	return 0;
}
