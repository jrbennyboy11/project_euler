import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;

/**
 * Created by bbarnett on 1/11/2017.
 */
public class Problem69 {
    public static void main(String[] args)
    {
        int i;
        int j;
        final int MAX_NUMBER = 1000000; //Maximum number to go up to for problem 69
        int max_solution_n = 0; //n with maximum solution to problem69 under MAX_NUMBER
        double max_solution = 0.0; //Maximum solution to problem69 under MAX_NUMBER
        ArrayList<ArrayList<Integer>> factors = new ArrayList<ArrayList<Integer>>();

        //Generate the factors for all numbers 2 - MAX_NUMBER
        for(i=2;i<=MAX_NUMBER; i++)
        {
            ArrayList<Integer> factorsOfCurrentNumber = new ArrayList<Integer>();

            for(j=2;j<=i/2;j++)
                if(i%j==0)
                    factorsOfCurrentNumber.add(j);

            factorsOfCurrentNumber.add(i);

            factors.add(factorsOfCurrentNumber);
        }

        /*
        for(i=0;i<factors.size();i++)
        {
            System.out.print(i+2 + ": ");
            ArrayList<Integer> facts = factors.get(i);

            for(j=0;j<facts.size();j++)
                System.out.print(facts.get(j) + " ");

            System.out.println();
        }
        System.out.println("------");
        */

        for(i=0;i<factors.size();i++)
        {
            if((i+2)%100000 == 0)
                System.out.println("Completed up to " + i);

            ArrayList<Integer> currNumFacts = factors.get(i);
            double n = 1.0 * (i+2);
            double phi_n = 1.0;

            //System.out.print(i+2 + ": ");
            for(j=i-1;j>=0;j--)
            {
                ArrayList<Integer> prevNumFacts = factors.get(j);
                if(Collections.disjoint(currNumFacts, prevNumFacts))
                {
                    //System.out.print(j+2 + " ");
                    phi_n += 1.0;
                }
            }
            //System.out.println();
            double current_solution = n / phi_n;
            if (current_solution > max_solution)
            {
                max_solution = current_solution;
                max_solution_n = i + 2;
            }
        }

        System.out.println("Max ratio <= " + MAX_NUMBER + ": " + max_solution_n + " | " + max_solution);
    }
}
