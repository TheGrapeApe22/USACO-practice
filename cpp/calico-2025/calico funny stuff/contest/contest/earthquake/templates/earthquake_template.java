import java.io.*;
import java.util.*;

class Solution {
    /**
     * Return a tuple with 4 values denoting the floor and ceil bounds of the
     * epicenter of the earthquake: floor_xE, floor_yE, ceil_xE, ceil_yE
     *
     * N: the number of persons
     * persons: a list of N persons, each represented as (Xi, Yi, Si, Ri)
     */
    static int[] solve(int N, List<Person> persons) {
        // YOUR CODE HERE
        return new int[]{0, 0, 1, 1};
    }

    static class Person {
        double X, Y, S;
        String R;
        Person(double X, double Y, double S, String R) {
            this.X = X;
            this.Y = Y;
            this.S = S;
            this.R = R;
        }
    }

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(in.readLine());
        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(in.readLine());
            List<Person> persons = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                String[] parts = in.readLine().split(" ");
                double Xi = Double.parseDouble(parts[0]);
                double Yi = Double.parseDouble(parts[1]);
                double Si = Double.parseDouble(parts[2]);
                String Ri = parts[3];
                persons.add(new Person(Xi, Yi, Si, Ri));
            }

            int[] ans = solve(N, persons);
            out.println(ans[0] + " " + ans[1] + " " + ans[2] + " " + ans[3]);
        }
        out.flush();
    }
}
