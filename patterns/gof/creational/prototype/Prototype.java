import gof.creational.prototype.Bacterium;

class Prototype
{
	public static void main(String[] args)
	{
		Bacterium original = new Bacterium("cocci", "vaillonella");
		Bacterium clone    = (Bacterium)original.clone();

		original.info();
		clone.info();

		/* It also is possible to store the
		 * cloned instance in IClone variables,
		 * but it do not give access to `info()`,
		 * because IClone do not declare it. */
	}
}
