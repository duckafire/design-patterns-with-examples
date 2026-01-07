### Factory method

It availables an hierarchy of interface and classes to create specific *products*
without to require user code know who this method to create its *product*.

In other words, this pattern defines that an object instance is responsible to
implementate an method to create a *product* related with itself, without to require
user code know this creation process.

Hierarchy of this pattern is divided in:

* Product Interface: contains methods to Concrete Products.

* Concrete Products: what will be created.

* Creator: abstract class that contains the "Factory Method" (abstract too), and,
optionally, extra logical *things* related with the *main method*.

* Concrete Creator: has an implementation of the "Factory Method" to create a specific
Concrete Product.

> [!NOTE]
> Create do not have to create nothing, it is just the super class of Concrete Creators,
> but it can have a default implementation of the "Factory Method".
