import gof.creational.singleton.CacheMan;

class Singleton
{
	public static void main(String[] args)
	{
		CacheMan.instance().addPair("foo", "bar");

		System.out.println(
			CacheMan.instance().getValueOf("foo")
		);
	}
}
