package gof.creational.abstract_factory;

import gof.creational.abstract_factory.IComponent;

public class ArchLinuxCheckbox implements IComponent
{
	@Override
	public void update()
	{}

	@Override
	public void draw()
	{
		System.out.println("Drawing a ArchLinux checkbox...!");
	}
}

