import java.util.Scanner;
import java.math.BigDecimal;

public class Main {

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		BigDecimal a,b;
		String sum;
		int t,n; 
		t = input.nextInt();
		while(t != 0)
		{
			t--;
			a = input.nextBigDecimal();
			b = input.nextBigDecimal();
			sum  = a.add(b).toString();
			n = sum.length() - 1;
			if(sum.charAt(n) == '0')
			{
				for(int i = n ; i >= 0 ; i--)
				{
					if(sum.charAt(i) != '0') 
					{
						n = i;
						break;
					}
				}
				if(sum.charAt(n) == '.') n++;
				
				for(int i = 0 ; i <= n ; i++) System.out.printf("%c",sum.charAt(i));
				System.out.println();
			}
			else System.out.println(sum);
						
		}
	}
}