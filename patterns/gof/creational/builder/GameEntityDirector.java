package gof.creational.builder;

public final class GameEntityDirector
{
	// Optional; to avoid instances.
	private GameEntityDirector()
	{}

	public static GameEntity slime()
	{
		return new GameEntity.Builder()
			.position(0)
			.dimensions(5)
			.speed(150)
			.hp(25)
			.build();
	}

	public static GameEntity zombie()
	{
		return new GameEntity.Builder()
			.position(0)
			.dimensions(10, 25)
			.speed(75, 50, 150)
			.hp(80)
			.build();
	}
}
