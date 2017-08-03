import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		while(t != 0)
		{
			t--;
			BigInteger num = input.nextBigInteger();
			num = sqrt(num);
			System.out.println(num);
			if(t != 0) System.out.println();
		}
		
	}
	public static BigInteger sqrt(BigInteger A) 
	{
		BigInteger temp = A.shiftRight(BigInteger.valueOf(A.bitLength()).shiftRight(1).intValue()), result = null;
		while(true)
		{
			result = temp.add(A.divide(temp)).shiftRight(1);
			if (!temp.equals(result)) temp = result;
			else break ;
		}
		return result;
	}
}
/*4
4.12345678900000000005
-0.00000000012
0
-1300.1
1300.123456789
0.0000000012345678912345
0
1500.61345975
-202.004285
-8.60917475
0
-218.302869584
200.0000123456789
0*/