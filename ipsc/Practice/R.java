public class R {
  static boolean magic(int x) {
    int foo = 0;
    while (x > 1)
      for (int y=2; ; ++y) {
        if (y==x) return foo<=0;
        if (magic(y) && x%y==0) { x/=y; ++foo; break; }
      }
    return true;
  }
  public static void main(String[] argv) {
    int where = 1;
    int step = -1;
    int best = where;
    while (step != 0) {
      System.out.println(where + " " + step + " " + best);
      where += step;
      if (where < best) { best=where; System.out.println("*"); }
      if (!magic(where)) break;
    }
  }
}
