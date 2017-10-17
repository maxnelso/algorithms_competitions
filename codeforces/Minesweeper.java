import java.util.*;
import java.math.*;
import java.io.*;
import java.awt.geom.*;

public class Minesweeper {

  public static int getCount(String[] mines, int i, int j, int n, int m) {
    int[][] deltas = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
    int count = 0;
    for (int index = 0; index < deltas.length; index++) {
      int first = deltas[index][0] + i;
      int second = deltas[index][1] + j;
      if (first < 0 || first >= n) {
        continue;
      }
      if (second < 0 || second >= m) {
        continue;
      }
      count += mines[first].charAt(second) == '*' ? 1 : 0;
    }
    return count;
  }

  public static void main(String[] args) throws Exception {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    String[] result = new String[n];
    String[] mines = new String[n];
    String[] moves = new String[n];
    int m = 0;
    for (int i = 0; i < n; i++) {
      String line = scanner.next();
      m = line.length();
      StringBuilder builder = new StringBuilder();
      for (int j = 0; j < m; j++) {
        builder.append(line.charAt(j));
      }
      mines[i] = builder.toString();
    }
    for (int i = 0; i < n; i++) {
      String line = scanner.next();
      StringBuilder builder = new StringBuilder();
      for (int j = 0; j < m; j++) {
        builder.append(line.charAt(j));
      }
      moves[i] = builder.toString();
    }
    for (int i = 0; i < n; i++) {
      StringBuilder builder = new StringBuilder();
      for (int j = 0; j < m; j++) {
        if (moves[i].charAt(j) == 'x') {
          builder.append(getCount(mines, i, j, n, m));
        } else {
          builder.append('.');
        }
      }
      result[i] = builder.toString();
    }
    for (int i = 0; i < n; i++) {
      System.out.println(result[i]);
    }
  }
}
