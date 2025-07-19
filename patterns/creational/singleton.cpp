/*

SINGLETON: class responsible for managing and making available GLOBALLY its single
instance.

It is useful for algorithms that need only one instance, like those responsible for
access to data banks, logs or similar.

This type of class can be (re)started easily way, just when necessary, unlike classes
100% static.

It is worth highlighting that the use of it is strongly discouraged, because of all
the problems that it has. For more information about it, see:

https://softwareengineering.stackexchange.com/questions/40373/so-singletons-are-bad-then-what#40610
https://www.davidtanzer.net/david's%20blog/2016/03/14/6-reasons-why-you-should-avoid-singletons.html
https://www.baeldung.com/java-patterns-singleton-cons

*/

#include <iostream>

// singleton class
class FantasyDB final { // Data Bank
protected:
	FantasyDB(void){
		// it must be private
	}

public:
	static FantasyDB* instance(void){
		// it will be freed when the program is finished
		static FantasyDB *inst = new FantasyDB();
		return inst;
	}

	void query(std::string code){
		// ~ magic ~ //
		std::cout << "Data bank query:\n\t" << code << std::endl;
	}
};

int main(void){
	FantasyDB::instance()->query("SELECT * FROM foo_table;");

	return 0;
}
