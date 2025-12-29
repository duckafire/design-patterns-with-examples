### Singleton

It manages and makes available a **GLOBAL single** object instance of a class.

It can be useful for algorithms that need only of one instance, like data bank clients
and the window of a GUI.

> [!CAUTION]
> * It breanks the *Single Responsability Principle* from **S**OLID:
> * It can render the debugging process most hard - because it is hard isolate it.
> * It can render hard manage its state - because it is global.

> [!TIP]
> **Remember**: *"It all Singleton is a single-instance class, but not every*
> *single-instance class is a Singleton."*
