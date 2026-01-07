package gof.creational.factory_method;

// Concrete creator.
public class PizzaCook extends Cook
{
	@Override
	protected IFood cooking()
	{
		return new Pizza();
	}
}
