/*
Students: Alina Kozhamberdina 991509979
Date: 9/19/2019
Program Description: This program executes algorithm for
the prefix averages problem more efficiently. Here we use prefix sum
which is S to calculate prefix average.
 */

import java.security.SecureRandom;
import java.util.Arrays;

public class Main {

    static int Arr[] = new int[600];


    public static void main(String[] args){
        long start = System.currentTimeMillis();
        SecureRandom r  = new SecureRandom();
        int s = r.nextInt(100);

        for (int i = 0; i < Arr.length; i++){
            double c;
            s = s + Arr[i];
            Arr[i] = s / (i + 1);
            c = Arr[i];

        }


        long end = System.currentTimeMillis();
        float sec = (end - start);
        System.out.println(sec + " milliseconds");
    }//end of main

}//end of Main
