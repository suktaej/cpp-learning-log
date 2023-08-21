import java.util.*;

public class Program
{
	public static void main(String[] args)
	{
		HashSet<String> hs01 = new HashSet<String>();
		HashSet<String> hs02 = new HashSet<String>();

		hs01.add("Kim");
		hs01.add("Lee");
		System.out.println(hs01.add("Park"));
		System.out.println(hs01.add("Park"));

		for(String e : hs01)
		{
			System.out.print(e+" ");
		}
		System.out.println();

		hs02.add("A");
		hs02.add("B");
		hs02.add("C");

		Iterator<String> iter02 = hs02.iterator();

		while(iter02.hasNext())
		{
			System.out.print(iter02.next()+" ");
		}
		System.out.println();

		System.out.println("Set size:"+hs02.size());
	}
}
