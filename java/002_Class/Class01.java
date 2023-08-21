class Car
{
	private int currentSpeed;
	private int accelerationTime;

	public void accelerate(int speed, int second)
	{
		System.out.println((speed/second) + " Accelerate");
	}
}

public class Class01
{
	public static void main(String[] args)
	{
		Car car = new Car();
		car.accelerate(60,3);
	}
}
