// https://usaco.org/index.php?page=viewproblem2&cpid=891

import java.io.*;

public class ShellGame {

    public static void main(String[] args) throws IOException {
        Brokenizer sc;
        try {sc = new Brokenizer("shell.in");}
        catch (FileNotFoundException e) {sc = new Brokenizer(System.in);}

        int n = sc.nextInt();
        int[] shells = {0, 1, 2};
        int[] guesses = {0, 0, 0};
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            int g = sc.nextInt();
            
            // swap
            int temp = shells[a];
            shells[a] = shells[b];
            shells[b] = temp;

            guesses[shells[g-1]]++;
        }
        PrintWriter pw = new PrintWriter("shell.out");
        pw.println(Math.max(Math.max(guesses[0],guesses[1]),guesses[2]));
        pw.flush();
        pw.close();
        sc.close();
    }
}
