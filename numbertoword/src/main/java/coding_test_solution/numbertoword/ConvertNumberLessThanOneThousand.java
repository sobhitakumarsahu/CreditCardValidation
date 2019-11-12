package coding_test_solution.numbertoword;

public class ConvertNumberLessThanOneThousand {
	private int number;
	public ConvertNumberLessThanOneThousand() {
	}
	public ConvertNumberLessThanOneThousand(int number) {
		super();
		this.number = number;
	}
	public String convertLessThanOneThousands(int number) {
		String current;
        
        if (number % 100 < 20){
            current = NumericConstants.numNames.get(number % 100);
            number /= 100;
        }
        else {
            current = NumericConstants.numNames.get(number % 10);
            number /= 10;
            
            current = NumericConstants.tensNames.get(number % 10) + current;
            number /= 10;
        }
        if (number == 0) return current;
        return NumericConstants.numNames.get(number) + " hundred and" + current;
	}
}
