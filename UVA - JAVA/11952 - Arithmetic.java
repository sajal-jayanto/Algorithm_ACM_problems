import java.util.*;
import java.math.*;

public class Main
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		int t;
		t = input.nextInt();
		while(t-->0)
		{
			int  a , b , c ;
			String d;
			a = input.nextInt();
			d = input.next();
			b = input.nextInt();
			d = input.next();
			c = input.nextInt();
			if(a == 1 && b == 1)
			{
				if(c == 11) System.out.println("1");
				else System.out.println("0");
				continue;
			}	
			String x = "" + a;
			String y = "" + b;
			String z = "" + c;
			int f = 0;
			for(int i = 2 ; i < 19 ; i++)
			{
				try {
				BigInteger m = new BigInteger(x , i);
				BigInteger n = new BigInteger(y , i);
				BigInteger o = new BigInteger(z , i);
				m = m.add(n);
				if(m.compareTo(o) == 0) 
				{
					System.out.println(i);
					f = 1;
					break;
				} } catch(NumberFormatException e){}
			}
			if(f == 0) System.out.println("0");
		}	
	}
}