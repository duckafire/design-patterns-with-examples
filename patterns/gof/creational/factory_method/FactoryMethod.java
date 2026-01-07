import gof.creational.factory_method.Cook;
import gof.creational.factory_method.PieCook;
import gof.creational.factory_method.PizzaCook;
import gof.creational.factory_method.IFood;

class FactoryMethod
{
	public static void main(String[] args)
	{
		Cook cook = ((int)(Math.random() * 2) == 0
			? new PieCook()
			: new PizzaCook());

		System.out.println("Cooking a new RANDOM food...");
		cook.deliever();
	}
}
