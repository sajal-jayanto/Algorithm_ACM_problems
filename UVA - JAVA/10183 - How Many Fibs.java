import java.util.Scanner;
import java.math.BigInteger;

public class Main{

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		int num = 500,count;
		BigInteger frist,second;
		BigInteger [] ar = new BigInteger[num];
		ar[0] = BigInteger.valueOf(1);
		ar[1] = BigInteger.valueOf(2);
		for(int i = 2; i < num ; i++)
		{
			ar[i] = ar[i - 1].add(ar[i - 2]);
		}
		while(input.hasNext())
		{
			frist = input.nextBigInteger();
			second = input.nextBigInteger();
			if(frist.equals(BigInteger.ZERO) && second.equals(BigInteger.ZERO)) break; 
			count = 0;
			for(int i = 0; i < num ; i++)
			{
				if(ar[i].compareTo(frist) >= 0 && ar[i].compareTo(second) <= 0) count++;
				if(ar[i].compareTo(second) > 0) break;
			}
			System.out.println(count);
		}
	}
}