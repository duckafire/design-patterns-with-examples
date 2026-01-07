import gof.creational.abstract_factory.EOpeSys;
import gof.creational.abstract_factory.IComponent;
import gof.creational.abstract_factory.IComponentsFactory;
import gof.creational.abstract_factory.DebianComponentsFactory;
import gof.creational.abstract_factory.ArchLinuxComponentsFactory;

class AbstractFactory
{
	private static IComponentsFactory GUIFactory;
	private static IComponent button;
	private static IComponent checkbox;
	private static IComponent input;

	public static void main(String[] args)
	{
		GUIFactory = getFactory();

		button   = GUIFactory.createButton();
		checkbox = GUIFactory.createCheckbox();
		input    = GUIFactory.createInput();

		button.draw();
		checkbox.draw();
		input.draw();
	}

	private static IComponentsFactory getFactory()
	{
		switch( getOS() )
		{
			case DEBIAN:     return new DebianComponentsFactory();
			case ARCH_LINUX: return new ArchLinuxComponentsFactory();
		}

		// This line circumvents a compilation-time
		// error - "Missing `return`".
		return null;
	}

	private static EOpeSys getOS()
	{
		return ((int)(Math.random() * 2)) == 0
			? EOpeSys.DEBIAN
			: EOpeSys.ARCH_LINUX;
	}
}
