/*

BUILDER: special class, created to instantiate a complex object (step by step).

This design pattern can be divided into:

* Builder Interface: interface or abstract class created to set common
methods for Concrete Builders.

* Product: object that will be instantiated by a Concrete Builder.

* Concrete Builder: a class that extends the Builder Interface and can
create (step by step) and return a Product instance.

* Builder Director: contains sets of instructions (inside specific methods)
to create pre-defined objects, based on methods of a Concrete Builder

*/

#include <iostream>

// builder "interface/abstract class" (optional)
template<typename TBuilder>
class Builder {
private:
	TBuilder *_product;

protected:
	void new_product(void){
		if(this->_product != nullptr)
			return;

		this->_product = new TBuilder();
	}

	void del_product(void){
		if(this->_product == nullptr)
			return;

		delete this->_product;
		this->_product = nullptr;
	}

	TBuilder* product(void){
		return this->_product;
	}

public:
	~Builder(void){
		this->del_product();
	}

	TBuilder* build(void){
		TBuilder *tmp;
		tmp = new TBuilder(this->_product);

		// it is safe; see: https://isocpp.org/wiki/faq/freestore-mgmt#delete-this
		delete this;
		return tmp;
	}
};

// product
class Player {
public:
	int x, y;
	bool isRunning, isFalling;
	short hp, speed, gravity;
	unsigned short width, height;

	Player(void){
		// necessary to instance an empty "product"
	}

	Player(const Player *builderProduct){
		this->x         = builderProduct->x;
		this->y         = builderProduct->y;
		this->width     = builderProduct->width;
		this->height    = builderProduct->height;
		this->hp        = builderProduct->hp;
		this->speed     = builderProduct->speed;
		this->gravity   = builderProduct->gravity;
		this->isRunning = builderProduct->isRunning;
		this->isFalling = builderProduct->isFalling;
	}

	void display_status(void){
		std::cout << "X: "          << this->x         << std::endl;
		std::cout << "Y: "          << this->y         << std::endl;
		std::cout << "Is running: " << this->isRunning << std::endl;
		std::cout << "Is falling: " << this->isFalling << std::endl;
		std::cout << "Hp: "         << this->hp        << std::endl;
		std::cout << "Speed: "      << this->speed     << std::endl;
		std::cout << "Gravity: "    << this->gravity   << std::endl;
		std::cout << "Width: "      << this->width     << std::endl;
		std::cout << "Height: "     << this->height    << std::endl;
		std::cout << std::endl;
	}
};

// builder
class PlayerBuilder: public Builder<Player> {
public:
	PlayerBuilder(void){
		this->new_product();
	}

	PlayerBuilder* set_position(int x, int y){
		this->product()->x = x;
		this->product()->y = y;
		return this;
	}

	PlayerBuilder* set_dimensions(unsigned short width, unsigned short height){
		this->product()->width  = width;
		this->product()->height = height;
		return this;
	}

	PlayerBuilder* set_hp(short quantity){
		this->product()->hp = quantity;
		return this;
	}

	PlayerBuilder* set_physics(short speed, short gravity){
		this->product()->speed   = speed;
		this->product()->gravity = gravity;
		return this;
	}

	PlayerBuilder* is_running(bool state){
		this->product()->isRunning = state;
		return this;
	}

	PlayerBuilder* is_falling(bool state){
		this->product()->isFalling = state;
		return this;
	}
};

// director (optional)
class PlayerDirector {
public:
	Player* tank(void){
		return (new PlayerBuilder())
			->set_position(0, 0)
			->set_dimensions(100, 225)
			->set_hp(400)
			->set_physics(25, 1)
			->is_running(false)
			->is_falling(false)
			->build();
	}


	Player* shooter(void){
		return (new PlayerBuilder())
			->set_position(0, 0)
			->set_dimensions(80, 150)
			->set_hp(120)
			->set_physics(45, 1)
			->is_running(true)
			->is_falling(false)
			->build();
	}
};

// client code ("optional")
int main(void){
	PlayerDirector *director;
	Player *melee, *shooter;

	director = new PlayerDirector();

	melee = (new PlayerBuilder())
		->set_hp(250)
		->is_running(true)
		->set_position(25, 25)
		->set_physics(40, 1)
		->is_falling(false)
		->set_dimensions(110, 170)
		->build();

	shooter = director->shooter();

	melee->display_status();
	shooter->display_status();

	delete melee, shooter;
	return 0;
}
