package gof.creational.factory_method;

// Concrete product.
class Pie implements IFood
{
	@Override
	public void announce()
	{
		System.out.println("Pie was cooked!");
	}
}
