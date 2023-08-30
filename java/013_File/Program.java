import java.io.File;

public class Program
{
	public static void main(String[] args)
	{
		File dir = new File("./");
		File file = new File(dir,"input.txt");

		if(!file.exists())
		{
			System.out.println("File not exist");
			System.exit(0);
		}
		System.out.println(file.getPath());
		System.out.println(file.length());
	}
}