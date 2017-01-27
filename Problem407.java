/**
 * Created by bbarnett on 1/20/2017.
 */
public class Problem407 {
    public static void main(String[] args)
    {
        final int MAX = 10000000;
        long sum = 0;

        for(int n=1;n<=MAX;n++) {
            //System.out.println("M(" + n + ") = " + m(n));
            sum += m(n);
        }

        System.out.println("P407 Solution: " + sum);
    }

    public static int m(int n)
    {
        int max = 0;
        int a_max = n/2+1;

        for(long a=0;a<a_max;a++) {
            //System.out.println(a + ": " + ((a * a) % n));
            if (a == (a * a) % n)
                if (a > max)
                    max = (int)a;
        }

        return max;
    }
}
