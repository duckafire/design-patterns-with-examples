### Builder

It implements a class to create a *complex* object instance, step by step.

It can be divided in:

* Builder Interface: defined common method for Concrete Builders.

* Product: what will be created by Concrete Builder.

* Concrete Builder: creates and returns its product (when it is required, otherwise
it returns itself).

* Director: contains set ones of instructions to create specific Products, based in a
specific Concrete Builder.

> [!TIP]
> Unlike [Abstract Factories](../abstract-factory), Directors are based in a single
> *complex* object, and ti depends of other class (a Concrete Builder).
