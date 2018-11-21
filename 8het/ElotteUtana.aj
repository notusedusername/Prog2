package aop;

import aop.LZWBinFa.Csomopont;

public aspect ElotteUtana {
	public pointcut fgvHivas(): call(public void LZWBinFa.Csomopont.kiir());
	before(): fgvHivas() {
		System.out.println("ElotteUtana> Alma");
	}

	after(): fgvHivas() {
		System.out.println("ElotteUtana> Korte");
	}
}