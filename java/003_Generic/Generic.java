import java.util.*;

class LandAnimal
{
	public void crying()
	{
		System.out.println("LandAnimal");
	}
}

class Cat extends LandAnimal
{
	public void crying()
	{
		System.out.println("Meow");
	}
}

class Dog extends LandAnimal
{
	public void crying()
	{
		System.out.println("Bow");
	}
}

class Sparrow
{
	public void crying()
	{
		System.out.println("Twit");
	}
}

//class AnimalList<T extends LandAnimal>
class AnimalList<T>
{
	ArrayList<T> arrl = new ArrayList<T>();

	public static void cryingAnimalList(AnimalList<? extends LandAnimal> arrl)
	{
		LandAnimal lanimal = arrl.get(0);
		lanimal.crying();
	}

	void add(T animal) { arrl.add(animal); }
	T get(int index){return arrl.get(index);}
	boolean remove(T animal){ return arrl.remove(animal);}
	int size() { return arrl.size();}
}

public class Generic
{
	public static void main(String[] args)
	{
		AnimalList<LandAnimal> landAnimal = new AnimalList<>();

		landAnimal.add(new LandAnimal());
		landAnimal.add(new Cat());
		landAnimal.add(new Dog());

		for(int i=0; i<landAnimal.size(); i++)
		{
			landAnimal.get(i).crying();
		}

		AnimalList<Cat> catList = new AnimalList<Cat>();
		catList.add(new Cat());
		AnimalList<Dog> dogList = new AnimalList<Dog>();
		dogList.add(new Dog());

		AnimalList.cryingAnimalList(catList);
		AnimalList.cryingAnimalList(dogList);

	}
}
