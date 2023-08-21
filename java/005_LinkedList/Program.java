import java.util.*;

public class Program
{
	public static void main(String[] args)
	{
		LinkedList<String> lnkList = new LinkedList<String>();

		lnkList.add("4");
		lnkList.add("3");
		lnkList.add("2");
		lnkList.add("1");

		for(int i=0;i<lnkList.size();i++)
		{
			System.out.print(lnkList.get(i)+" ");
		}

		lnkList.remove(1);

		System.out.println();
		for(String i : lnkList)
		{
			System.out.print(i+" ");
		}

		lnkList.set(2,"2");

		System.out.println();
		for(String i : lnkList)
		{
			System.out.print(i+" ");
		}
	}
}

