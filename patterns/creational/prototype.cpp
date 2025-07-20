/*

PROTOTYPE: allows to create a copy (shallow or deep) of a instantiated object, in
an easy way.

It is useful to create multiple "expensive" objects.

It is commonly implemented as a method named as "clone" or "copy".

For more information about the shallow and deep copy, see:
https://stackoverflow.com/questions/184710/what-is-the-difference-between-a-deep-copy-and-a-shallow-copy?page=1&tab=scoredesc#tab-top

*/

#include <iostream>

#define PRINT(txt, attr, pre) \
	std::cout << txt ": \t" << attr << " \t" << pre (attr) << std::endl

#define END \
	std::cout << std::endl;

class PetInfo {
public:
	virtual void get_info(void) const = 0;
};

// SHALLOW COPY:
// all properties of the copy POINTS TO the SAME value ADDRESS.
class Dog: public PetInfo {
private:
	const char *name;
	const char *age;
	const char *breed;

public:
	Dog(const char *_name, const char *_age, const char *_breed):
		name(_name),
		age(_age),
		breed(_breed) {
	}

	// copy constructor
	Dog(const Dog &other) = default;

	Dog* clone(void) const {
		return new Dog(*this);
	}

	void get_info(void) const override {
		PRINT("Name",  this->name,  (void*));
		PRINT("Age",   this->age,   (void*));
		PRINT("Breed", this->breed, (void*));
		END;
	}
};

// DEEP COPY:
// all properties of the copy POINTS TO a DIFFERENT value ADDRESS.
class Cat: public PetInfo {
private:
	std::string name;
	std::string age;
	std::string breed;

public:
	Cat(std::string _name, std::string _age, std::string _breed):
		name(_name),
		age(_age),
		breed(_breed) {
	}

	// copy constructor
	Cat(const Cat &other) = default;

	Cat* clone(void) const {
		return new Cat(*this);
	}

	void get_info(void) const override {
		PRINT("Name",  this->name,  &);
		PRINT("Age",   this->age,   &);
		PRINT("Breed", this->breed, &);
		END;
	}
};

int main(void){
	Dog *dog       = new Dog("Rex", "2", "Boxer");
	Dog *clonedDog = dog->clone();

	Cat *cat       = new Cat("Milly", "5", "Bombay");
	Cat *clonedCat = cat->clone();

	dog->get_info();
	clonedDog->get_info();

	cat->get_info();
	clonedCat->get_info();

	delete dog, clonedDog, cat, clonedCat;
	return 0;
}
