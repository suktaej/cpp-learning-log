import java.io.*;

public class Program
{
	public static String readFile(String filePath) throws IOException
	{
		BufferedReader br = new BufferedReader(new FileReader(filePath));
		try
		{
			return br.readLine();
		}
		finally {
			if(br!=null) br.close();
		}
	}
	public static String readFile2(String filePath) throws IOException
	{
		try(BufferedReader br = new BufferedReader(new FileReader(filePath)))
		{
			return br.readLine();
		}
	}

	public static void main(String[] args) throws IOException
	{
//		byte[] fileByte = new byte[16];
//		FileInputStream inp = new FileInputStream("input.txt");
//		inp.read(fileByte);

		System.out.println(readFile("input.txt"));
		System.out.println(readFile2("input.txt"));
	}
}