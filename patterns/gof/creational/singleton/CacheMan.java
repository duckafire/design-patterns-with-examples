package gof.creational.singleton;

import java.util.HashMap;

public class CacheMan
{
	private static CacheMan inst = new CacheMan();

	public static CacheMan instance()
	{
		return CacheMan.inst;
	}

	private HashMap<String, String> data = new HashMap<>();

	// Only ONE PRIVATE constructor.
	private CacheMan()
	{}

	public void addPair(String key, String value)
	{
		this.data.put(key, value);
	}

	public String getValueOf(String key)
	{
		return this.data.get(key);
	}
}
