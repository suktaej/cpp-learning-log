import java.util.*;

class Car implements Comparable<Car>
{
	private String modelName;
	private int modelYear;
	private String color;

	Car(String mn, int my, String c)
	{
		this.modelName = mn;
		this.modelYear = my;
		this.color = c;
	}

	public String getMode1() {return this.modelYear + "Model year" + this.modelName + " " + this.color;}
	public int compareTo(Car obj)
	{
		if (this.modelYear==obj.modelYear) { return 0; }
		else if(this.modelYear < obj.modelYear) { return -1; }
		else { return 1; }
	}
}

class DescendingOrder implements Comparator<Integer>
{
	public int compare(Integer o1,Integer o2)
	{
		if(o1 instanceof Comparable && o2 instanceof Comparable)
		{
			Integer c1 = (Integer)o1;
			Integer c2 = (Integer)o2;
			return c2.compareTo(c1);
		}
		return -1;
	}
}
public class Program
{
	public static void main(String[] args)
	{
		Car car01 = new Car("Avante",16,"Yellow");
		Car car02 = new Car("Sonata",10,"White");

		TreeSet<Integer> ts = new TreeSet<Integer>(new DescendingOrder());
		ts.add(30);
		ts.add(40);
		ts.add(10);
		ts.add(20);

		System.out.println(car01.compareTo(car02));

		Iterator<Integer> iter = ts.iterator();
		while(iter.hasNext())
		{
			System.out.println(iter.next());
		}
	}
}