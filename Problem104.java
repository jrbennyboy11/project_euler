import java.math.BigInteger;

/**
 * Created by bbarnett on 2/3/2017.
 */
public class Problem104 {
    public static void main(String[] args)
    {
        BigInteger fib1 = new BigInteger("1");
        BigInteger fib2 = new BigInteger("1");
        BigInteger fib3 = new BigInteger("1");
        long numDigits = 0;
        long i = 2;

        while(fib3.toString().length() < 18)
        {
            fib1 = new BigInteger(fib2.toString());
            fib2 = new BigInteger(fib3.toString());
            fib3 = fib3.add(fib1);
            i++;
        }

        while(!(pandigitalStart(fib3.toString()) && pandigitalEnd(fib3.toString())))
        {
            fib1 = new BigInteger(fib2.toString());
            fib2 = new BigInteger(fib3.toString());
            fib3 = fib3.add(fib1);

            if(fib3.toString().length() > numDigits)
            {
                numDigits = fib3.toString().length();
                System.out.println("Num Digits: " + numDigits);
            }

            i++;
        }

        System.out.println("F" + i + ": " + fib3.toString());
    }

    public static boolean pandigitalStart(String num)
    {
        String start = num.substring(0,9);
        return isPandigital(start);
    }

    public static boolean pandigitalEnd(String num)
    {
        String end = num.substring(num.length()-9,num.length());
        return isPandigital(end);
    }

    public static boolean isPandigital(String num)
    {
        boolean[] digits = {false, false, false, false, false, false, false, false, false};
        int i;

        if(num.length() != 9)
        {
            System.out.println("You fucked up");
            return false;
        }

        for(i=0;i<9;i++)
        {
            int charVal = num.charAt(i) - '0';

            if(charVal == 0 || digits[charVal-1] == true)
                return false;
            digits[charVal-1] = true;
        }

        return true;
    }
}
