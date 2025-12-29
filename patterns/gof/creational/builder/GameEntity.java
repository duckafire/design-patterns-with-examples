package gof.creational.builder;

// Product.
public class GameEntity
{
	// Using "default" access modifier
	// to allow Builder access these
	// properties.
	int x, y;
	int width, height;
	int speed, minSpeed, maxSpeed;
	int hp, maxHp;

	public GameEntity()
	{}

	public void info()
	{
		System.out.printf("POSITION: %d %d\n", this.x, this.y);
		System.out.printf("DIMENSIONS: %d %d\n", this.width, this.height);
		System.out.printf("SPEEDS: %d %d %d\n", this.speed, this.minSpeed, this.maxSpeed);
		System.out.printf("HP: %d %d\n\n", this.hp, this.maxHp);
	}

	// "Friend class".
	public static final class Builder implements IBuilder
	{
		// NOTE: add default value to the properties
		// or add a validation to the methods, to check
		// if the object was full mounted and to avoid
		// to create an incompleted object. This
		// implementation do not have nothing of these
		// things - what it is a bad idea.
		private GameEntity product;

		public Builder()
		{
			this.resetProduct();
		}

		@Override
		public void resetProduct()
		{
			this.product = new GameEntity();
		}

		@Override
		public GameEntity build()
		{
			GameEntity tmp = this.product;
			this.resetProduct();
			return tmp;
		}

		public Builder position(int xy)
		{
			return this.position(xy, xy);
		}

		public Builder position(int x, int y)
		{
			this.product.x = x;
			this.product.y = y;
			return this;
		}

		public Builder dimensions(int d)
		{
			return this.dimensions(d, d);
		}

		public Builder dimensions(int w, int h)
		{
			this.product.width  = w;
			this.product.height = h;
			return this;
		}

		public Builder speed(int s)
		{
			return this.speed(s, s, s);
		}

		public Builder speed(int cur, int min, int max)
		{
			this.product.speed = cur;
			this.product.minSpeed = min;
			this.product.maxSpeed = max;
			return this;
		}

		public Builder hp(int hp)
		{
			return this.hp(hp, hp);
		}

		public Builder hp(int hp, int maxHp)
		{
			this.product.hp    = hp;
			this.product.maxHp = maxHp;
			return this;
		}
	}
}
