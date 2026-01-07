package gof.creational.abstract_factory;

import gof.creational.abstract_factory.IComponentsFactory;
import gof.creational.abstract_factory.DebianButton;
import gof.creational.abstract_factory.DebianCheckbox;
import gof.creational.abstract_factory.DebianInput;

public class DebianComponentsFactory implements IComponentsFactory
{
	@Override
	public IComponent createButton()
	{
		return new DebianButton();
	}

	@Override
	public IComponent createCheckbox()
	{
		return new DebianCheckbox();
	}

	@Override
	public IComponent createInput()
	{
		return new DebianInput();
	}
}
