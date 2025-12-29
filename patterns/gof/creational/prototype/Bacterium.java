package gof.creational.prototype;

public class Bacterium implements IClone
{
	private String type;
	private String specie;
	private boolean alive;

	public Bacterium(String type, String specie)
	{
		this.type   = type;
		this.specie = specie;
		this.alive  = true;
	}

	public void info()
	{
		System.out.printf("Bacterium:\n  Type:   %s\n  Specie: %s\n  Health: %s\n", this.type, this.specie, (this.alive ? "OK" : "Dead"));
	}

	@Override
	public IClone clone()
	{
		/* It is possible because Bacterium
		 * implements IClone.
		 * To store the returned instance in
		 * variables of hte type Bacterium
		 * it is necessary use "casting".
		 * */
		return new Bacterium(this.type, this.specie);
	}
}
