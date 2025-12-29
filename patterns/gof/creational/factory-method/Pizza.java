package gof.creational.factory_method;

// Concrete product.
class Pizza implements IFood
{
	@Override
	public void announce()
	{
		System.out.println("Pizza was cooked!");
	}
}
