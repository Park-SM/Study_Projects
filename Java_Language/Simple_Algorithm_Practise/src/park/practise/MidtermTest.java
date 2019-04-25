package park.practise;

public class MidtermTest {
	public static void main(String[] args) {
		
		if (args.length != 4) System.out.println("> Parameter error");
		else {
			int uFrom = Integer.parseInt(args[0]);
			int uTo = Integer.parseInt(args[1]);
			String uMsg = args[2];
			int uValue = Integer.parseInt(args[3]);
			
			if (uMsg.equals("row")) {
				int tMod = (uFrom - uTo + 1) % uValue;
				uValue = (uFrom - uTo + 1) / uValue;
				if (tMod != 0) uValue++;	
			}
			
			for (int Dan = uFrom; Dan >= uTo; Dan-=uValue) {
				for (int Row = 1; Row < 20; Row++) {
					for (int tDan = Dan; tDan > Dan - uValue && tDan >= uTo; tDan--)
						System.out.printf("%2d x %-2d = %d\t", tDan, Row, tDan * Row);
					System.out.println();
				}
				System.out.println();
			}
			
		}
		
	}
}
