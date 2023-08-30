import java.util.*;

public class Program
{
	public static void main(String[] args)
	{
		System.out.println("==================");
		HashMap<String, Integer> hm = new HashMap<String,Integer>();

		hm.put("thirty",30);
		hm.put("ten",10);
		hm.put("forty",40);
		hm.put("twenty",20);

		System.out.println("Set of keys saved Map:"+hm.keySet());
		for(String key: hm.keySet())
		{
			System.out.println(String.format("Key:%s, Value:%s",key,hm.get(key)));
		}
		System.out.println("==================");
		hm.remove("forty");

		Iterator<String> keys = hm.keySet().iterator();
		while(keys.hasNext())
		{
			String key = keys.next();
			System.out.println(String.format("Key:%s, Value:%s",key,hm.get(key)));
		}
		System.out.println("Map size:"+hm.size());
	}
}