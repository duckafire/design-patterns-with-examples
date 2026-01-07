package gof.creational.factory_method;

// Concrete creator.
public class PieCook extends Cook
{
	@Override
	protected IFood cooking()
	{
		return new Pie();
	}
}
