	opt	c+, at+, e+, n-
	section .text

	xdef SetRotMatrix_80093218
SetRotMatrix_80093218:
	dw 0x8C880000 ; 0x80093218
	dw 0x8C890004 ; 0x8009321C
	dw 0x8C8A0008 ; 0x80093220
	dw 0x8C8B000C ; 0x80093224
	dw 0x8C8C0010 ; 0x80093228
	dw 0x48C80000 ; 0x8009322C
	dw 0x48C90800 ; 0x80093230
	dw 0x48CA1000 ; 0x80093234
	dw 0x48CB1800 ; 0x80093238
	dw 0x48CC2000 ; 0x8009323C
	dw 0x03E00008 ; 0x80093240
	dw 0x00000000 ; 0x80093244