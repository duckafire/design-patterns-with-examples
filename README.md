[gof-book]: https://www.amazon.com/Design-Patterns-Elements-Reusable-Object-Oriented/dp/0201633612 "Link to Amazon Store"
[erich]:    https://en.wikipedia.org/wiki/Erich_Gamma "His Wikipedia page"
[richard]:  https://en.wikipedia.org/wiki/Richard_Helm "His Wikipedia page"
[ralph]:    https://en.wikipedia.org/wiki/Ralph_Johnson_(computer_scientist) "His Wikipedia page"
[john]:     https://en.wikipedia.org/wiki/John_Vlissides "His Wikipedia page"

# Design patterns with examples

In summary, Design Patterns are solutions, based OOP, already tested to recurrent
problems in programming, that aim to facilitate the maintenance and understanding of
a project.

The purpose of this project is to introduce the main types of Design
Pattern in programming, in a simple, easy and didactic way.

The patterns are separated in distinct directories, being formed by a short README and
by compilable files (that formed the pattern). The concept of the code can be adapted
to a lot of programming languages.

> [!WARNING]
> It is worth remembering, even though it is useful, these patterns will not
> fit perfectly in all types of project and programming languages, so it is
> up to you to analyze and decide what it should be used and what should not
> be used.

## Gang of Four (GoF)

It is a group of authors of the book
[Design Patterns: Elements of Reusable Object-Oriented Software][gof-book],
formed by [Erich Gamma][erich], [Richard Helm][richard], [Ralph Johnson][ralph]
and [John Vlissibes][jhon]. Their book is a catalog of Design Pattern, with
usage instructions, descriptions, and tips related to the patterns in this section.

* Creational:
	* Abstract Factory
	* [Builder](./patterns/gof/creational/builder)
	* [Factory Method](./patterns/gof/creational/factory_method)
	* [Prototype](./patterns/gof/creational/prototype)
	* [Singleton](./patterns/gof/creational/singleton)
* Structural:
	* Adapter
	* Bridge
	* Composite
	* Decorator
	* Facade
	* Flyweight
	* Proxy
* Behavioral:
	* Chain of Responsibility
	* Command
	* Interpreter
	* Iterator
	* Mediator
	* Memento
	* Observer
	* State
	* Strategy
	* Template Method
	* Visitor

