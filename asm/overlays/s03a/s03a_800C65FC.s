	opt	c+, at+, e+, n-
	section overlay.text

	xdef s03a_800C65FC
s03a_800C65FC:
	dw 0x00A4102A ; 800C65FC
	dw 0x10400003 ; 800C6600
	dw 0x00C5102A ; 800C6604
	dw 0x00802821 ; 800C6608
	dw 0x00C5102A ; 800C660C
	dw 0x10400002 ; 800C6610
	dw 0x00000000 ; 800C6614
	dw 0x00A03021 ; 800C6618
	dw 0x03E00008 ; 800C661C
	dw 0x00C01021 ; 800C6620
