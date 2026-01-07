package gof.creational.abstract_factory;

import gof.creational.abstract_factory.IComponentsFactory;
import gof.creational.abstract_factory.ArchLinuxButton;
import gof.creational.abstract_factory.ArchLinuxCheckbox;
import gof.creational.abstract_factory.ArchLinuxInput;

public class ArchLinuxComponentsFactory implements IComponentsFactory
{
	@Override
	public IComponent createButton()
	{
		return new ArchLinuxButton();
	}

	@Override
	public IComponent createCheckbox()
	{
		return new ArchLinuxCheckbox();
	}

	@Override
	public IComponent createInput()
	{
		return new ArchLinuxInput();
	}
}
