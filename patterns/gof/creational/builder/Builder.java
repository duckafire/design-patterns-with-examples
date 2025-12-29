import gof.creational.builder.GameEntity;
import gof.creational.builder.GameEntityDirector;

class Builder
{
	public static void main(String[] args)
	{
		GameEntity player = new GameEntity.Builder()
			.position(0)
			.dimensions(10, 25)
			.speed(500)
			.hp(100, 999)
			.build();

		GameEntity slime  = GameEntityDirector.slime();
		GameEntity zombie = GameEntityDirector.zombie();

		player.info();
		slime.info();
		zombie.info();
	}
}
