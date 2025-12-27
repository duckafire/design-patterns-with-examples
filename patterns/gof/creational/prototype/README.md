### Prototye

It allows to create a copy of an object instance in a easy way.

It is useful to create multiple objects which require a lot of data. It is commonly
implemented as a method named as `clone`, or `copy`.

This pattern do not specific the **type** of the copy, so you are free to decide what
to use. The **types** available are:

* Shallow: properties values are shared between original and clone object instance, in
  other words, properties of both objects will point to some memory address.

* Deep: properties values are cloned too, so, they will point to equal values, they
  are store in different memory address.

* Mixed: a mix between shallow and deep clones.
