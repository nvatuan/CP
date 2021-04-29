import java.io.*;
import java.util.ArrayList;
import java.util.InputMismatchException;

/**
 * Import down here
 */

public class CF_1315B {
    /**
     * ------------------ WRITE YOUR SOLUTION HERE ------------------------
     */
    static class Solution {
        // Constructor
        public Solution() {
        }

        int t, a, b, p;
        String s;

        // Do your input, process, output here
        boolean check(int x) {
            long cost = 0;
            while (x + 1 < s.length()) {
                if (s.charAt(x) == 'A')
                    cost += a;
                else
                    cost += b;
                char remember = s.charAt(x);
                while (x < s.length() && s.charAt(x) == remember)
                    x++;
            }
            return (cost <= p);
        }

        public void solve(FastIO io) throws Exception {
            t = io.nextInt();
            while (t-- > 0) {
                a = io.nextInt();
                b = io.nextInt();
                p = io.nextInt();
                s = io.next();

                int l = 0, r = s.length() - 1;
                int ans = 0;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (check(mid)) {
                        ans = mid;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                io.print(ans + 1 + "\n");
            }
        }
    }

    /**
     * --------------------------------------------------------------------
     */
    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            try {
                FastIO io = new FastIO();
                Solution sol = new Solution();
                sol.solve(io);
                io.close();
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        }
    }

    public static void main(String[] args) throws Exception {
        int RECURSION_STACK_DEPTH = 1 << 29;
        Thread thread = new Thread(null, new TaskAdapter(), "", RECURSION_STACK_DEPTH);
        thread.start();
        thread.join();
    }
}

class FastIO {
    String inputFile, outputFile;
    FastReader in;
    FastWriter out;

    public FastIO() throws FileNotFoundException, IOException {
        this(null, null);
    }

    public FastIO(String x, String y) throws FileNotFoundException, IOException {
        inputFile = x;
        outputFile = y;

        if (x != null)
            in = new FastReader(inputFile);
        else
            in = new FastReader();

        if (y != null)
            out = new FastWriter(outputFile);
        else
            out = new FastWriter();
    }

    /**
     * Reading methods - FastReader object
     */
    public String readLine() throws IOException {
        return in.readLine();
    }

    public String next() throws IOException {
        return in.next();
    }

    public int nextInt() throws IOException {
        return in.nextInt();
    }

    public double nextDouble() throws IOException {
        return in.nextDouble();
    }

    public long nextLong() throws IOException {
        return in.nextLong();
    }

    public char nextChar() throws IOException {
        return in.nextChar();
    }

    public byte nextByte() throws IOException {
        return in.nextByte();
    }

    /**
     * Writing methods - FastWriter object
     */
    public void print(Object o) throws IOException {
        out.print(o);
    }

    public void println(Object o) throws IOException {
        out.println(o);
    }

    public void print(double x, int decPlace) throws IOException {
        out.print(x, decPlace);
    }

    public void println(double x, int decPlace) throws IOException {
        out.println(x, decPlace);
    }

    /**
     * Closing streams. Out needs to be flushed in its close() method.
     */
    public void close() throws IOException {
        in.close();
        out.close();
    }
}

class FastReader {
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;

    public FastReader() {
        din = new DataInputStream(System.in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public FastReader(String fileName) throws IOException {
        din = new DataInputStream(new FileInputStream(fileName));
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    /**
     * @return Return a string that is read until a '\n' character is found. The
     *         last character is ensured not to be a newline character. This string
     *         could be empty.
     * @throws IOException
     */
    public String readLine() throws IOException {
        ArrayList<Byte> buf = new ArrayList<Byte>(64);
        int c;
        while ((c = read()) != -1) {
            if (c == '\n')
                break;
            buf.add((byte) (c));
        }
        byte[] byteArr = new byte[buf.size()];
        for (int i = 0; i < buf.size(); i++)
            byteArr[i] = buf.get(i);
        return new String(byteArr, 0, byteArr.length);
    }

    public String next() throws IOException {
        StringBuilder s = new StringBuilder();
        byte c = firstMeaningfulByte();

        do {
            s.append((char) (c));
        } while ((c = read()) > ' ');
        return s.toString();
    }

    public int nextInt() throws IOException {
        int ret = 0;
        byte c = firstMeaningfulByte();
        boolean neg = (c == '-');
        if (neg)
            c = read();
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');

        if (neg)
            return -ret;
        return ret;
    }

    public long nextLong() throws IOException {
        long ret = 0;
        byte c = firstMeaningfulByte();
        boolean neg = (c == '-');
        if (neg)
            c = read();
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');
        if (neg)
            return -ret;
        return ret;
    }

    public double nextDouble() throws IOException {
        double ret = 0, div = 1;
        byte c = firstMeaningfulByte();

        boolean neg = (c == '-');
        if (neg)
            c = read();

        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');

        if (c == '.') {
            while ((c = read()) >= '0' && c <= '9') {
                ret += (c - '0') / (div *= 10);
            }
        }

        if (neg)
            return -ret;
        return ret;
    }

    /**
     * Returned char is following ISO-8859-1 standard, using 1 byte encoding.
     * Therefore, here, a char is considered to be a byte.
     * 
     * @return A single char that has ascii value greater than ' '
     * @throws IOException
     */
    public char nextChar() throws IOException {
        byte c = firstMeaningfulByte();
        return (char) c;
    }

    /**
     * Consume bytes with ascii value equals or smaller than Whitespace char in the
     * buffer
     * 
     * @return A single byte that ascii value is greater than whitespace
     */
    private byte firstMeaningfulByte() throws IOException {
        byte c = read();
        while (c <= ' ')
            c = read();
        return c;
    }

    /**
     * Does not ignore any byte.
     * 
     * @return The next byte in the buffer
     */
    public byte nextByte() throws IOException {
        byte c = read();
        return c;
    }

    public void close() throws IOException {
        if (din == null)
            return;
        din.close();
    }

    private byte read() throws IOException {
        if (bufferPointer == bytesRead)
            fillBuffer();
        if (buffer[0] == -1)
            throw new IOException("Input buffer is empty.");
        return buffer[bufferPointer++];
    }

    private void fillBuffer() throws IOException {
        bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
        if (bytesRead == -1)
            buffer[0] = -1;
    }

}

class FastWriter {
    private PrintWriter writer;

    public FastWriter() throws IOException {
        writer = new PrintWriter(System.out, false);
    }

    public FastWriter(String outFile) throws IOException {
        writer = new PrintWriter(new BufferedWriter(new FileWriter(outFile)), false);
    }

    public void print(double x, int num_digits) throws IOException {
        writer.printf("%." + num_digits + "f", x);
    }

    public void println(double x, int num_digits) throws IOException {
        writer.printf("%." + num_digits + "f\n", x);
        flush();
    }

    public void print(Object o) throws IOException {
        writer.print(o.toString());
    }

    public void println(Object o) throws IOException {
        writer.println(o.toString());
        flush();
    }

    public void flush() {
        writer.flush();
    }

    public void close() {
        flush();
        writer.close();
    }
}
