import java.util.HashSet;
import java.util.Iterator;

/**
 * Created by bbarnett on 1/17/2017.
 */
public class Problem125 {
    public static void main(String[] args)
    {
        final int LIMIT = 100000000;
        int max_i;
        int sum;
        long sum_consec_palindromes;
        int i;
        int j;
        int k;
        HashSet<Integer> palindromes = new HashSet();
        Iterator<Integer> hsitt;

        int max_digits = String.valueOf(LIMIT-1).length();

        for(i=0;i<LIMIT;i++)
            if(i==reverse(i))
                palindromes.add(i);

        for(max_i=0;max_i*max_i<LIMIT;max_i++);
        sum_consec_palindromes = 0;

        for(i=0;i<=max_i;i++)
        {
            sum = 0;
            for(j=i;j<=max_i && sum<LIMIT;j++) {
                boolean skip = false;
                if(sum == 0)
                    skip = true;

                sum += j * j;
                if(!skip && palindromes.contains(sum)) {
                    sum_consec_palindromes += sum;
                    palindromes.remove(sum);
                }
            }

        }

        //System.out.println("There are " + palindromes.size() + " palindromes under " + LIMIT);
        System.out.println("Problem 125 Solution: " + sum_consec_palindromes);
    }

    public static int reverse( int number ) {
        int result = 0;
        while ( number > 0 ) {
            result = result * 10 + (number % 10);
            number = number / 10;
        }
        return result;
    }
}
