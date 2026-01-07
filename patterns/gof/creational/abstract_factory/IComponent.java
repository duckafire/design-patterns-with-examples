package gof.creational.abstract_factory;

/*   It is recommended to create an interface to each
 * product, but since it is just an example, I will
 * use only one class. This also will easily the
 * understanding of this pattern.
 *   The implemtantations of this interface will have
 * a MINIMAL code - because this is just an example.
 * */
public interface IComponent
{
	void update();
	void draw();
}
