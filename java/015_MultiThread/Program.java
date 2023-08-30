class ThreadWithRunnable implements Runnable
{
	public void run()
	{
		try
		{
			Thread.sleep(10);
		}catch (InterruptedException e)
		{
			e.printStackTrace();
		}
	}
}

public class Program
{
	public static void main(String[] args)
	{
		Thread thread0 = new Thread(new ThreadWithRunnable());
		thread0.start();
		System.out.println(thread0.getThreadGroup());

		ThreadGroup tGroup = new ThreadGroup("myThread");
		tGroup.setMaxPriority(7);

		Thread thread1 = new Thread(tGroup,new ThreadWithRunnable());
		thread1.start();
		System.out.println(thread1.getThreadGroup());
	}
}