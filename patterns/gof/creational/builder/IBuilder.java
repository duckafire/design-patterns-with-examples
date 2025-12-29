package gof.creational.builder;

interface IBuilder
{
	void resetProduct();

	// This return type will
	// be overrided.
	Object build();
}
