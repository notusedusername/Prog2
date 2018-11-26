package aop;

import aop.LZWBinFa.Csomopont;

public aspect ElotteUtana {
	public pointcut fgvHivas(): call(public void LZWBinFa.Csomopont.kiir());
	int bef = 0;
	int aft = 0;
	before(): fgvHivas() {
		bef++;
		System.out.println("ElotteUtana> LZWBinFa.Csomopont.kiir() indul");
	}

	after(): fgvHivas() {
		aft++;
		System.out.println("ElotteUtana> LZWBinFa.Csomopont.kiir() fv lefutott");
	}
}
