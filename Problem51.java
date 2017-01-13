import java.io.*;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;

/**
 * Created by Ben Barnett on 1/11/2017.
 * https://projecteuler.net/problem=51
 */

public class Problem51 {
    public static void main(String[] args) throws IOException
    {
        final int MIN_PRIME = 100000000;
        final int MAX_PRIME = 1000000000; //Max is 10000000000
        final int PATTERN_SIZE = 8;
        Scanner scanner = new Scanner(new File("C://Users/bbarnett/Desktop/project_euler/src/primes_to_10_billion.txt"));
        Integer p;
        int prime;
        int i;
        int j;
        int k;

        /*
            Each list HastSet object is a HashSet containing all the primes between
            MIN_PRIME and MAX_PRIME that have a repeating digit. list 0 is for repeating 0s,
            list1 is for repeating 1s, etc.
         */

        HashSet<Integer> list0 = new HashSet<>();
        HashSet<Integer> list1 = new HashSet<>();
        HashSet<Integer> list2 = new HashSet<>();
        HashSet<Integer> list3 = new HashSet<>();
        HashSet<Integer> list4 = new HashSet<>();
        HashSet<Integer> list5 = new HashSet<>();
        HashSet<Integer> list6 = new HashSet<>();
        HashSet<Integer> list7 = new HashSet<>();
        HashSet<Integer> list8 = new HashSet<>();
        HashSet<Integer> list9 = new HashSet<>();
        HashSet<Integer> the_pattern = new HashSet<>();
        Iterator<Integer> hsitt;

        System.out.println("Loading into memory all primes with a repeating digit between "+ MIN_PRIME + " & " + MAX_PRIME);

        while(scanner.hasNextInt() && (prime = scanner.nextInt()) <= MAX_PRIME)
        {
            if(prime >= MIN_PRIME)
            {
                String prime_string = "" + prime;

                //Checking if there are more at least 2 0s in the prime number
                if(prime_string.length() - prime_string.replaceAll("0","").length() >= 2)
                    list0.add(prime);
                //Checking if there are 2 1s in the prime number and etc for the rest of these statements
                if(prime_string.length() - prime_string.replaceAll("1","").length() >= 2)
                    list1.add(prime);
                if(prime_string.length() - prime_string.replaceAll("2","").length() >= 2)
                    list2.add(prime);
                if(prime_string.length() - prime_string.replaceAll("3","").length() >= 2)
                    list3.add(prime);
                if(prime_string.length() - prime_string.replaceAll("4","").length() >= 2)
                    list4.add(prime);
                if(prime_string.length() - prime_string.replaceAll("5","").length() >= 2)
                    list5.add(prime);
                if(prime_string.length() - prime_string.replaceAll("6","").length() >= 2)
                    list6.add(prime);
                if(prime_string.length() - prime_string.replaceAll("7","").length() >= 2)
                    list7.add(prime);
                if(prime_string.length() - prime_string.replaceAll("8","").length() >= 2)
                    list8.add(prime);
                if(prime_string.length() - prime_string.replaceAll("9","").length() >= 2)
                    list9.add(prime);
            }
        }
        scanner.close();

        System.out.println("Finished loading into memory and filtering all primes between " + MIN_PRIME + " & " + MAX_PRIME);
        System.out.println("Beginning " + PATTERN_SIZE + " prime pattern search...");
        System.out.println();

        int num_digits = String.valueOf(MIN_PRIME).length();

        //The following 2 for loops check every combination of 2 digit locations
        for(i=0;i<num_digits;i++)
        {
            for(j = i + 1; j < num_digits; j++)
            {
                HashSet<Integer> pattern0 = new HashSet<>();
                HashSet<Integer> pattern1 = new HashSet<>();
                HashSet<Integer> pattern2 = new HashSet<>();
                HashSet<Integer> pattern3 = new HashSet<>();
                HashSet<Integer> pattern4 = new HashSet<>();
                HashSet<Integer> pattern5 = new HashSet<>();
                HashSet<Integer> pattern6 = new HashSet<>();
                HashSet<Integer> pattern7 = new HashSet<>();
                HashSet<Integer> pattern8 = new HashSet<>();
                HashSet<Integer> pattern9 = new HashSet<>();

                //Checks if there are any primes with 2 0s where the 0s are at i & j
                hsitt = list0.iterator();
                while(hsitt.hasNext())
                {
                    p = hsitt.next();
                    if (String.valueOf(p).charAt(i) == '0' && String.valueOf(p).charAt(j) == '0')
                        pattern0.add(p);
                }
                //Checks if there are any primes with 2 1s where the 1s are at i & j. Same thing for the rest of these while statements
                hsitt = list1.iterator();
                while(hsitt.hasNext())
                {
                    p = hsitt.next();
                    if (String.valueOf(p).charAt(i) == '1' && String.valueOf(p).charAt(j) == '1')
                        pattern1.add(p);
                }
                hsitt = list2.iterator();
                while(hsitt.hasNext())
                {
                    p = hsitt.next();
                    if (String.valueOf(p).charAt(i) == '2' && String.valueOf(p).charAt(j) == '2')
                        pattern2.add(p);
                }
                hsitt = list3.iterator();
                while(hsitt.hasNext())
                {
                    p = hsitt.next();
                    if (String.valueOf(p).charAt(i) == '3' && String.valueOf(p).charAt(j) == '3')
                        pattern3.add(p);
                }
                hsitt = list4.iterator();
                while(hsitt.hasNext())
                {
                    p = hsitt.next();
                    if (String.valueOf(p).charAt(i) == '4' && String.valueOf(p).charAt(j) == '4')
                        pattern4.add(p);
                }
                hsitt = list5.iterator();
                while(hsitt.hasNext())
                {
                    p = hsitt.next();
                    if (String.valueOf(p).charAt(i) == '5' && String.valueOf(p).charAt(j) == '5')
                        pattern5.add(p);
                }
                hsitt = list6.iterator();
                while(hsitt.hasNext())
                {
                    p = hsitt.next();
                    if (String.valueOf(p).charAt(i) == '6' && String.valueOf(p).charAt(j) == '6')
                        pattern6.add(p);
                }
                hsitt = list7.iterator();
                while(hsitt.hasNext())
                {
                    p = hsitt.next();
                    if (String.valueOf(p).charAt(i) == '7' && String.valueOf(p).charAt(j) == '7')
                        pattern7.add(p);
                }
                hsitt = list8.iterator();
                while(hsitt.hasNext())
                {
                    p = hsitt.next();
                    if (String.valueOf(p).charAt(i) == '8' && String.valueOf(p).charAt(j) == '8')
                        pattern8.add(p);
                }
                hsitt = list9.iterator();
                while(hsitt.hasNext())
                {
                    p = hsitt.next();
                    if (String.valueOf(p).charAt(i) == '9' && String.valueOf(p).charAt(j) == '9')
                        pattern9.add(p);
                }

                //Checks to see if there is at least 1 number that has a 0 at both i & j, a 1 at both i & j, etc
                int patternSize = 0;
                if(pattern0.size() > 0)
                    patternSize++;
                if(pattern1.size() > 0)
                    patternSize++;
                if(pattern2.size() > 0)
                    patternSize++;
                if(pattern3.size() > 0)
                    patternSize++;
                if(pattern4.size() > 0)
                    patternSize++;
                if(pattern5.size() > 0)
                    patternSize++;
                if(pattern6.size() > 0)
                    patternSize++;
                if(pattern7.size() > 0)
                    patternSize++;
                if(pattern8.size() > 0)
                    patternSize++;
                if(pattern9.size() > 0)
                    patternSize++;

                //If there is at least 1 number that has a 0 at both i & j, a 1 at both i & j, etc such that
                //The there is a possible pattern of size PATERN_SIZE
                if(patternSize >= PATTERN_SIZE)
                {
                    System.out.println("Possible " + PATTERN_SIZE + " prime pattern found by replacing digits " + i + " & " + j);

                    int patternNum1 = 1;
                    int patternNum2 = 1;

                    for(k=0;k<num_digits-(i+1);k++, patternNum1 *= 10);
                    for(k=0;k<num_digits-(j+1);k++, patternNum2 *= 10);

                    int pattern = patternNum1 + patternNum2;

                    System.out.println("Checking " + pattern0.size() + ", " + num_digits + " digit primes containing at least 2 0s");

                    //Checks to see if it can make a PATTERN_SIZE sized pattern with any of the numbers with a 0
                    //at its i & j index
                    hsitt = pattern0.iterator();
                    while(hsitt.hasNext())
                    {
                        the_pattern.clear();
                        p = hsitt.next();
                        the_pattern.add(p);

                        if (the_pattern.size() >= (PATTERN_SIZE-9) && pattern1.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-8) && pattern2.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-7) && pattern3.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-6) && pattern4.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-5) && pattern5.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-4) && pattern6.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-3) && pattern7.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-2) && pattern8.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-1) && pattern9.contains(p + pattern))
                            the_pattern.add(p + pattern);

                        if (the_pattern.size() >= PATTERN_SIZE) {
                            System.out.println("Found " + PATTERN_SIZE + " prime pattern: ");
                            System.out.println();
                            hsitt = the_pattern.iterator();
                            while(hsitt.hasNext())
                                System.out.println(hsitt.next());
                            System.exit(0);
                        }
                    }

                    System.out.println("Checking " + pattern1.size() + ", " + num_digits + " digit primes containing at least 2 1s");

                    //Checks to see if it can make a PATTERN_SIZE sized pattern with any of the numbers with a 1
                    //at its i & j index
                    hsitt = pattern1.iterator();
                    while(hsitt.hasNext())
                    {
                        the_pattern.clear();
                        p = hsitt.next();
                        the_pattern.add(p);

                        if (the_pattern.size() >= (PATTERN_SIZE-8) && pattern2.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-7) && pattern3.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-6) && pattern4.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-5) && pattern5.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-4) && pattern6.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-3) && pattern7.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-2) && pattern8.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-1) && pattern9.contains(p + pattern))
                            the_pattern.add(p + pattern);

                        if (the_pattern.size() >= PATTERN_SIZE) {
                            System.out.println("Found " + PATTERN_SIZE + " prime pattern: ");
                            System.out.println();
                            hsitt = the_pattern.iterator();
                            while(hsitt.hasNext())
                                System.out.println(hsitt.next());
                            System.exit(0);
                        }
                    }

                    System.out.println("Checking " + pattern2.size() + ", " + num_digits + " digit primes containing at least 2 2s");

                    //Checks to see if it can make a PATTERN_SIZE sized pattern with any of the numbers with a 0
                    //at its i & j index. Doesn't go beyond this because it's impossible to have an 8 number pattern
                    //with only 3,4,5,6,7,8,9
                    hsitt = pattern2.iterator();
                    while(hsitt.hasNext())
                    {
                        the_pattern.clear();
                        p = hsitt.next();
                        the_pattern.add(p);

                        if (the_pattern.size() >= (PATTERN_SIZE-7) && pattern3.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-6) && pattern4.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-5) && pattern5.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-4) && pattern6.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-3) && pattern7.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-2) && pattern8.contains(p + pattern))
                            the_pattern.add(p + pattern);
                        if (the_pattern.size() >= (PATTERN_SIZE-1) && pattern9.contains(p + pattern))
                            the_pattern.add(p + pattern);

                        if (the_pattern.size() >= PATTERN_SIZE) {
                            System.out.println("Found " + PATTERN_SIZE + " prime pattern: ");
                            System.out.println();
                            hsitt = the_pattern.iterator();
                            while(hsitt.hasNext())
                                System.out.println(hsitt.next());
                            System.exit(0);
                        }
                    }

                    System.out.println("No " + PATTERN_SIZE + " prime patterns found by replacing digits " + i + " & " + j);
                    System.out.println();
                }
            }
        }

        System.out.println("Pattern of size " + PATTERN_SIZE + " not found between " + MIN_PRIME + " & " + MAX_PRIME);
    }
}
