package gof.creational.factory_method;

// Creator.
public abstract class Cook
{
	// It can have a default
	// implementation.
	abstract protected IFood cooking();

	// Extra logical things related
	// with the "Factory Method".
	public void deliever()
	{
		IFood food = this.cooking();
		food.announce();
	}
}
