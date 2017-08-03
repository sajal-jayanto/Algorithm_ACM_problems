import java.util.Scanner;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int a,b;   
        while(input.hasNext())
        {
            a = input.nextInt();
            b = input.nextInt();
            BigInteger sum = BigInteger.ZERO;
            for(int i = 1 ; i <= a ; i++)
            {
                sum = sum.add(BigInteger.valueOf(i).multiply(BigInteger.valueOf(b).pow(i)));
            }
            System.out.println(sum);
        }
    }
}
