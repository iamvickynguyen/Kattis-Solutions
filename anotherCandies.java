
//import java.math.BigInteger;
import java.util.Scanner;

class anotherCandies {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int numLine = scanner.nextInt();
		for (int i = 0; i < numLine; i++) {
			long sumCandies = 0;
			long numChildren = scanner.nextLong();
			for (int j = 0; j < numChildren; j++) {
				long tmp = scanner.nextLong();
				sumCandies = ((tmp % numChildren) + (sumCandies % numChildren)) % numChildren;
			}
			if (sumCandies == 0) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
		}
		scanner.close();
	}

	/*
	 * public static void main(String[] args) { Scanner scanner = new
	 * Scanner(System.in); int numLine = scanner.nextInt(); for (int i = 0; i <
	 * numLine; i++) { BigInteger sumCandies = new BigInteger("0"); BigInteger
	 * numChildren = scanner.nextBigInteger(); for (int j = 0; j <
	 * numChildren.intValue(); j++) { BigInteger tmp = scanner.nextBigInteger();
	 * sumCandies =
	 * ((tmp.mod(numChildren)).add(sumCandies.mod(numChildren))).mod(numChildren); }
	 * if (sumCandies.intValue() == 0) { System.out.println("YES"); } else {
	 * System.out.println("NO"); } } scanner.close(); }
	 */
}
