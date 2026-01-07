package gof.creational.abstract_factory;

import gof.creational.abstract_factory.IComponent;

public interface IComponentsFactory
{
	IComponent createButton();
	IComponent createCheckbox();
	IComponent createInput();
}
