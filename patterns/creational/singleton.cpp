/*

SINGLETON: class responsible for managing and making
available GLOBALLY its single instance. In other words,
this class MUST have only ONE instance (in it all program),
that it will managed by itself class.

It is usefull for algorithms that need only one instance,
like data bank clients.

It is worth highlighting that the use of it is strongly
discouraged, because of all the problems that it has.
The mainly are:

* It break the Single Responsability Principle:
	from SOLID.

* It can render the debug most harder:
	because it is hard isolate it.

* It can render hard manage its state:
	because it is global.

* It can have concurrence problems in multithread sceneries:
	because it is shared.

Remember:
	"It all Singleton is a single-instance class, but
	not every single-instance class is a Singleton."

*/

#include <cstdio>

// Singleton class
class FantasyDB final
{
private:
	// This "cause" a harmless memory leak, because
	// this address is lost only after the program
	// end (when the OS free the memory alloced for
	// the program; when the microcontroller is
	// offed, what free all memory address).
	static FantasyDB *inst;

	// The constructor(s) MUST BE private;
	// try using only one constructor, no
	// parameters.
	FantasyDB(void){
		// ...
	}

public:
	// delete default implementation of the
	// "special constructors"
	FantasyDB(const FantasyDB &other) = delete;
	void operator=(const FantasyDB &other) = delete;

	static const FantasyDB* instance(void)
	{
		return FantasyDB::inst;
	}

	void query(const char *sql) const
	{
		// ...
		printf("Data bank query: \n%s\n\nOK\n\n", sql);
	}
};

// C++ do not allow to attribute a value to a
// static properties during its declaration,
// the only way to do this is outside the
// class environment or inside of a class
// method.
FantasyDB *FantasyDB::inst = new FantasyDB();

// If there is a chance that your program is
// closed before to use this, I recommend to
// attribute a value to this property only
// after the first use of `instance()`, of
// the follow way:
//
// if (FantasyDB::inst == nullpr)
// {
//     FantasyDB::inst = new FantasyDB();
// }
//
// Most people prefer this.

// Maybe you think to declare a static pointer
// inside `instance()`, but it unavailable the
// sharing of the instance between different
// threads.

// Client code
int main(void){
	FantasyDB::instance()->query("SELECT * FROM foo_table;");
	return 0;
}
