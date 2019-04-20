package park.practise;

public class PrintShapeOfStar {
	public static void main(String[] args) {
		ShapeOfStar sos = new ShapeOfStar(11);
		System.out.println("::: Triangle - Right :::");
		sos.PrintTriangle("right");
		
		System.out.println("\n::: Triangle - Left :::");
		sos.PrintTriangle("left");
		
		System.out.println("\n::: Triangle - Center:::");
		sos.PrintTriangle("");
		
		System.out.println("\n::: Diamond :::");
		sos.PrintDiamond();
		
		System.out.println("\n::: Fish :::");
		sos.PrintFish();
	}
}

class ShapeOfStar {
	public int height;
	
	public ShapeOfStar (int uHight) {
		this.height = uHight;
	}
	
	public void PrintTriangle(String alignStr) {
		if (alignStr.equals("left")) {
			for (int Row = 1; Row <= this.height; Row++) {
				for (int Column = 0; Column < Row; Column++) System.out.print("*");
				System.out.println();
			}
		} else if (alignStr.equals("right")) {
			for (int Row = 1; Row <= this.height; Row++) {
				for (int Column = Row; Column < this.height; Column++) System.out.print(" ");
				for (int Column = 0; Column < Row; Column++) System.out.print("*");
				System.out.println();
			}
		} else {
			for (int Row = 0; Row < this.height; Row++) {
				for (int Column = Row; Column < this.height - 1; Column++) System.out.print(" ");
				for (int Column = 0; Column < (2 * Row + 1); Column++) System.out.print("*");
				System.out.println();
			}
		}
	}
	
	public void PrintDiamond() {
		if (this.height % 2 == 0) {
			for (int Row = 0; Row < (this.height / 2); Row++) {
				for (int Column = Row; Column < (this.height / 2 - 1); Column++) System.out.print(" ");
				for (int Column = 0; Column < (2 * Row + 1); Column++) System.out.print("*");
				System.out.println();
			}
			for (int Row = (this.height / 2 - 1); Row >= 0; Row--) {
				for (int Column = (this.height / 2 - 1); Column > Row; Column--) System.out.print(" ");
				for (int Column = 0; Column < (2 * Row + 1); Column++) System.out.print("*");
				System.out.println();
			}
		} else {
			for (int Row = 0; Row < (this.height / 2 + 1); Row++) {
				for (int Column = Row; Column < (this.height / 2); Column++) System.out.print(" ");
				for (int Column = 0; Column < (2 * Row + 1); Column++) System.out.print("*");
				System.out.println();
			}
			for (int Row = (this.height / 2) - 1; Row >= 0; Row--) {
				for (int Column = (this.height / 2 - 1); Column >= Row; Column--) System.out.print(" ");
				for (int Column = 0; Column < (2 * Row + 1); Column++) System.out.print("*");
				System.out.println();
			}
		}
	}
	
	public void PrintFish() {
		PrintDiamond();
		if (this.height % 2 == 0) {
			for (int Row = 1; Row < (this.height / 2); Row++) {
				for (int Column = Row; Column < (this.height / 2 - 1); Column++) System.out.print(" ");
				for (int Column = 0; Column < (2 * Row + 1); Column++) System.out.print("*");
				System.out.println();
			}
		} else {
			for (int Row = 1; Row < (this.height / 2 + 1); Row++) {
				for (int Column = Row; Column < (this.height / 2); Column++) System.out.print(" ");
				for (int Column = 0; Column < (2 * Row + 1); Column++) System.out.print("*");
				System.out.println();
			}
		}
	}
}