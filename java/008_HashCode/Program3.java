import java.util.*;

public class Program3
{
	public static void main(String[] args)
	{
		TreeSet<Integer> ts = new TreeSet<Integer>();

		ts.add(20);
		ts.add(30);
		ts.add(10);
		ts.add(40);

		for(int e : ts)
		{
			System.out.print(e+" ");
		}
		System.out.println();

		ts.remove(40);

		Iterator<Integer> iter = ts.iterator();
		while(iter.hasNext())
		{
			System.out.print(iter.next()+" ");
		}
		System.out.println();

		System.out.println("size of binary search tree:"+ts.size());
		System.out.println(ts.subSet(10,30));
		System.out.println(ts.subSet(10,true,20,true));
	}
}