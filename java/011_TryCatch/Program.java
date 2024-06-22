public class Program
{
	static void handlingException()
	{
		try
		{
			throw new Exception();
		}
		catch (Exception e)
		{
			System.out.println("Exception handled by called method");
		}
	}

	static void handlingException2() throws Exception
	{
		throw new Exception();
	}
	public static void main(String[] args)
	{
		try
		{
			handlingException();
			handlingException2();
		}
		catch (Exception e)
		{
			System.out.println("Exception handled by main method");
		}
	}
}