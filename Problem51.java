import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by bbarnett on 1/11/2017.
 */
public class Problem51 {
    public static void main(String[] args) throws FileNotFoundException, IOException
    {
        final int MIN_PRIME = 10000;
        final int MAX_PRIME = 100000;
        final int PATTERN_SIZE = 7;
        Scanner scanner = new Scanner(new File("C://Users/bbarnett/Desktop/project_euler/src/primes_to_10_billion.txt"));
        int prime;
        int i;
        int j;
        int k;

        ArrayList<Integer> list0 = new ArrayList<Integer>();
        ArrayList<Integer> list1 = new ArrayList<Integer>();
        ArrayList<Integer> list2 = new ArrayList<Integer>();
        ArrayList<Integer> list3 = new ArrayList<Integer>();
        ArrayList<Integer> list4 = new ArrayList<Integer>();
        ArrayList<Integer> list5 = new ArrayList<Integer>();
        ArrayList<Integer> list6 = new ArrayList<Integer>();
        ArrayList<Integer> list7 = new ArrayList<Integer>();
        ArrayList<Integer> list8 = new ArrayList<Integer>();
        ArrayList<Integer> list9 = new ArrayList<Integer>();

        while(scanner.hasNextInt() && (prime = scanner.nextInt()) <= MAX_PRIME)
        {
            if(prime >= MIN_PRIME)
            {
                String prime_string = "" + prime;

                if(prime_string.length() - prime_string.replaceAll("0","").length() >= 2)
                    list0.add(prime);
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

        int index0 = -1;
        int index1 = -1;
        int index2 = -1;
        int index3 = -1;
        int index4 = -1;
        int index5 = -1;
        int index6 = -1;
        int index7 = -1;
        int index8 = -1;
        int index9 = -1;

        int num_digits = String.valueOf(MIN_PRIME).length();

        /*
            Need to change this code to instead of finding 1 that matches a pattern, find all in each group that
            match the pattern and then somehow figure out if any of each subset are matching
         */

        for(i=0;i<num_digits;i++) {
            for (j = i + 1; j < num_digits; j++) {
                for (k = 0; k < list0.size() && index0 == -1; k++)
                    if (String.valueOf(list0.get(k)).charAt(i) == '0' && String.valueOf(list0.get(k)).charAt(j) == '0')
                        index0 = k;
                for (k = 0; k < list1.size() && index1 == -1; k++)
                    if (String.valueOf(list1.get(k)).charAt(i) == '1' && String.valueOf(list1.get(k)).charAt(j) == '1')
                        index1 = k;
                for (k = 0; k < list2.size() && index2 == -1; k++)
                    if (String.valueOf(list2.get(k)).charAt(i) == '2' && String.valueOf(list2.get(k)).charAt(j) == '2')
                        index2 = k;
                for (k = 0; k < list3.size() && index3 == -1; k++)
                    if (String.valueOf(list3.get(k)).charAt(i) == '3' && String.valueOf(list3.get(k)).charAt(j) == '3')
                        index3 = k;
                for (k = 0; k < list4.size() && index4 == -1; k++)
                    if (String.valueOf(list4.get(k)).charAt(i) == '4' && String.valueOf(list4.get(k)).charAt(j) == '4')
                        index4 = k;
                for (k = 0; k < list5.size() && index5 == -1; k++)
                    if (String.valueOf(list5.get(k)).charAt(i) == '5' && String.valueOf(list5.get(k)).charAt(j) == '5')
                        index5 = k;
                for (k = 0; k < list6.size() && index6 == -1; k++)
                    if (String.valueOf(list6.get(k)).charAt(i) == '6' && String.valueOf(list6.get(k)).charAt(j) == '6')
                        index6 = k;
                for (k = 0; k < list7.size() && index7 == -1; k++)
                    if (String.valueOf(list7.get(k)).charAt(i) == '7' && String.valueOf(list7.get(k)).charAt(j) == '7')
                        index7 = k;
                for (k = 0; k < list8.size() && index8 == -1; k++)
                    if (String.valueOf(list8.get(k)).charAt(i) == '8' && String.valueOf(list8.get(k)).charAt(j) == '8')
                        index8 = k;
                for (k = 0; k < list9.size() && index9 == -1; k++)
                    if (String.valueOf(list9.get(k)).charAt(i) == '9' && String.valueOf(list9.get(k)).charAt(j) == '9')
                        index9 = k;
            }

            int patternSize = 0;
            if (index0 != -1)
                patternSize++;
            if (index1 != -1)
                patternSize++;
            if (index2 != -1)
                patternSize++;
            if (index3 != -1)
                patternSize++;
            if (index4 != -1)
                patternSize++;
            if (index5 != -1)
                patternSize++;
            if (index6 != -1)
                patternSize++;
            if (index7 != -1)
                patternSize++;
            if (index8 != -1)
                patternSize++;
            if (index9 != -1)
                patternSize++;

            if (patternSize >= PATTERN_SIZE) {
                if (index0 != -1)
                    System.out.println(list0.get(index0));
                if (index1 != -1)
                    System.out.println(list1.get(index1));
                if (index2 != -1)
                    System.out.println(list2.get(index2));
                if (index3 != -1)
                    System.out.println(list3.get(index3));
                if (index4 != -1)
                    System.out.println(list4.get(index4));
                if (index5 != -1)
                    System.out.println(list5.get(index5));
                if (index6 != -1)
                    System.out.println(list6.get(index6));
                if (index7 != -1)
                    System.out.println(list7.get(index7));
                if (index8 != -1)
                    System.out.println(list8.get(index8));
                if (index9 != -1)
                    System.out.println(list9.get(index9));

                System.out.println("-------");
            }

            index0 = -1;
            index1 = -1;
            index2 = -1;
            index3 = -1;
            index4 = -1;
            index5 = -1;
            index6 = -1;
            index7 = -1;
            index8 = -1;
            index9 = -1;
        }
    }
}
