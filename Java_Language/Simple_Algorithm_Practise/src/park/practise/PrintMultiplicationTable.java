package park.practise;

public class PrintMultiplicationTable {
	public static void main(String[] args) {
			MultiplicationTable mt = new MultiplicationTable(19, 6);
			mt.PrintMulTable();
	}
}

class MultiplicationTable {
	private int MaxDan;
	private int Column;
	
	public MultiplicationTable(int uMaxDan, int uColumn) {
		this.MaxDan = uMaxDan;
		this.Column = uColumn;
	}
	
	public void PrintMulTable() {
		System.out.println("::: " + this.MaxDan + "th Multiplication Table :::\n");
		for (int Dan = 2; Dan <= this.MaxDan; Dan+=Column) {
			for (int Row = 1; Row <= this.MaxDan; Row++) {
				for (int tDan = Dan; tDan < Dan + Column && tDan <= this.MaxDan; tDan++) {
					System.out.print(tDan + " X " + Row + " = " + (tDan * Row) + "\t");
				}
				System.out.println();
			}
			System.out.println();
		}
	}
}