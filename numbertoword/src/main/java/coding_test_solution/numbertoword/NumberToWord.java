package coding_test_solution.numbertoword;

import java.util.Scanner;

public class NumberToWord {
	ConvertNumberLessThanOneThousand convertLessThanOneThousand = new ConvertNumberLessThanOneThousand();

	public String convert(int number) {

		if (number == 0) {
			return "zero";
		}

		String prefix = "";
	
		String current = "";
		int place = 0;

		do {
			int n = number % 1000;
			if (n != 0) {
				String s = convertLessThanOneThousand.convertLessThanOneThousands(n);
				current = s + NumericConstants.specialNames.get(place) + current;
			}
			place++;
			number /= 1000;
		} while (number > 0);

		return (prefix + current).trim();
	}

	public static void main(String[] args) {
		NumberToWord obj = new NumberToWord();
		try {
			int number = Integer.parseInt(args[0]);
			if (number >= 0  && number <= 999999999) {
				System.out.println(obj.convert(number));
			}
			else {
				System.out.println("Numbers less than 0 or greater than 999999999 not supported");
			}
		} catch (NumberFormatException e) {
			System.out.println("Enter numbers only! for example : 12345");
			e.printStackTrace();
		}catch (Exception e) {			
			e.printStackTrace();
		}
	}
}
