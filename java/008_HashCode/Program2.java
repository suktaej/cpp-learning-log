import java.util.HashSet;

class Animal{
    String species;
    String habitat;

    Animal(String species, String habitat)
    {
        this.species = species;
        this.habitat = habitat;
    }

    public int hashCode() { return (species + habitat).hashCode(); }
    public boolean equals (Object obj)
    {
        if(obj instanceof Animal)
        {
            Animal temp =  (Animal) obj;
            return species.equals(temp.species)&&habitat.equals(temp.habitat);
        } else
        {
            return false;
        }
    }
}

public class Program2
{
    public static void main(String[] args)
    {
        HashSet<Animal> hs = new HashSet<Animal>();

        hs.add(new Animal("cat","land"));
        hs.add(new Animal("dog","land"));
        hs.add(new Animal("cat","land"));

        System.out.println(hs.size());
    }
}
