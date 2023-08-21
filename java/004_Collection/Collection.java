import java.util.*;

public class Collection
{
	public static void main(String[] args)
	{
		ArrayList<Integer> arrList = new ArrayList<Integer>();

		arrList.add(4);
		arrList.add(3);
		arrList.add(2);
		arrList.add(1);
	
		for(int i=0;i<arrList.size();i++)
		{
			System.out.println(arrList.get(i));
		}

		arrList.remove(1);
		System.out.println();

		for(Integer temp : arrList)
		{
			System.out.println(temp);
		}

		Collections.sort(arrList);
		Iterator<Integer> iter = arrList.iterator();
		
		while(iter.hasNext())
		{
			System.out.print(iter.next()+" ");
		}

		arrList.set(0,20);

		System.out.println();
		for(int e : arrList)
		{
			System.out.print(e+" ");
		}
	}
}
