import java.io.*;
import java.util.StringTokenizer;

public class Brokenizer extends BufferedReader {
    public StringTokenizer st;

    public Brokenizer (InputStream in) throws IOException {
        super(new InputStreamReader(in));
    }
    public Brokenizer () throws IOException {
        this(System.in);
    }
    public Brokenizer (String filename) throws FileNotFoundException {
        super(new java.io.FileReader(filename));
    }

    public String nextLine() throws IOException {
        st = null;
        return readLine();
    }
    public String nextToken() throws IOException {
        if (st == null) st = new StringTokenizer(readLine());
        // when current line has no more tokens
        while (!st.hasMoreTokens()) {
            // keep jumping to next lines
            st = new StringTokenizer(readLine());
        }
        return st.nextToken();
    }

    public int nextInt() throws IOException { return Integer.parseInt(nextToken()); }
    public double nextDouble() throws IOException { return Double.parseDouble(nextToken()); }
    public long nextLong() throws IOException { return Long.parseLong(nextToken()); }
}
