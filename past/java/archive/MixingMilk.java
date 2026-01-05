// https://usaco.org/index.php?page=viewproblem2&cpid=855
import java.io.*;

public class MixingMilk {
    public static void main(String[] args) throws IOException {
        Brokenizer sc = new Brokenizer("mixmilk.in");
        
        int[] capacities = new int[3];
        int[] amounts = new int[3];
        
        for (int i = 0; i < 3; i++) {
            capacities[i] = sc.nextInt();
            amounts[i] = sc.nextInt();
        }

        int current = 0;
        for (int i = 0; i < 100; i++) {
            int next = (current + 1) % 3;
            amounts[next] += amounts[current];
            amounts[current] = 0;
            if (amounts[next] > capacities[next]) {
                amounts[current] += amounts[next] - capacities[next];
                amounts[next] = capacities[next];
            }
            current = next;
        }

        PrintWriter out = new PrintWriter("mixmilk.out");
        for (int i : amounts) {
            out.println(i);
        }
        sc.close();
        out.close();
    }
}
