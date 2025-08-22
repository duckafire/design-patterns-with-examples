/*

PROTOTYPE: allows create a copy of an instantiated object,
in an wasy eay.

It is useful to create multiple "expensive" objects. It is
commonly implemented as a method named as `clone` or `copy`.

This pattern do not specific the type of the copy, so you
are free to decide what use. The types "available" are:

* Shallow: the properties values are shared between the
original and the clone object, in other words, the
properties of both objects will point to some memory
address.

* Deep: the properties values are cloned too. So, the
properties of each object will point to equal values
(until that one is changed), that they are store in
different memory address.

* Mixed: a mix between shallow and deep clones.

*/

#include <cstdio>

// Prototype abstract class
class IClone
{
public:
	// This is necessary to call the derived
	// class destructor after destroy an
	// instance of a derived object that it
	// is stored in a pointer of this (IClone)
	// type.
	virtual ~IClone(){}

	virtual IClone* clone(void) const = 0;
};

// Concrete prototype
class Bacterium: public IClone
{
private:
	const char *type;
	const char *specie;
	bool alive;
	
public:
	Bacterium(const char *_type, const char *_specie):
		type(_type),
		specie(_specie)
	{
		this->alive = true;
	}

	// CLONE CONSTRUCTOR:
	// Create an object which properties
	// will receive the values stored in
	// `other` properties, i.e.:
	// this->alive = other->alive;
	Bacterium(const Bacterium &other) = default; // mixed clone

	// Maybe you prefer use an unique or
	// a shared pointer.
	IClone* clone(void) const override
	{
		return new Bacterium(*this);
	}

	void info(void) const
	{
		printf("Bacterium:\n  Type:   %s\n  Specie: %s\n  Health: %s\n", this->type, this->specie, (this->alive ? "OK" : "Dead"));
	}
};

// Client code
void example_with_middler(void)
{
	Bacterium *origi, *clone;
	IClone *middl;

	origi = new Bacterium("cocci", "vaillonella");
	middl = origi->clone();
	clone = (Bacterium*)middl;

	origi->info();
	clone->info();

	delete origi, clone;
}

void example_without_middler(void)
{
	Bacterium *origi;
	IClone *clone;

	origi = new Bacterium("bacilli", "albus");
	clone = origi->clone();

	origi->info();
	((Bacterium*)clone)->info();

	delete origi, clone;
}

int main(void)
{
	puts("==============================");
	example_with_middler(); // recommended
	puts("==============================");
	example_without_middler();
	puts("==============================");
	return 0;
}
