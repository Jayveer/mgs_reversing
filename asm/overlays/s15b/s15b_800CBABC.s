	opt	c+, at+, e+, n-
	section overlay.text

	xdef s15b_800CBABC
s15b_800CBABC:
	dw 0x8FB20018 ; 800CBABC
	dw 0x8FB10014 ; 800CBAC0
	dw 0x8FB00010 ; 800CBAC4
	dw 0x03E00008 ; 800CBAC8
	dw 0x27BD0020 ; 800CBACC
