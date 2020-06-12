/*
Students: Alina Kozhamberdina 991509979
Date: 9/19/2019
Program Description: This program executes algorithm for
the prefix averages problem. It computes every element of A separately
 */
//package com.company;
import java.security.SecureRandom;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        // write your code here
        long start = System.currentTimeMillis();
        int[] ArrIn = new int[3000];
        SecureRandom r = new SecureRandom();

        for (int i=0; i<ArrIn.length; i++){
            int a = r.nextInt();
            a = ArrIn[i];
            for(int j=0; j<ArrIn.length; j++){
                a = a + ArrIn[j];

            }
            double b = ArrIn[i] = a / (i+1);
        }
        //time difference in seconds
        long end = System.currentTimeMillis();
        float sec = (end - start);
        System.out.println(sec + " milliseconds");}// end of main

}//end of Main
