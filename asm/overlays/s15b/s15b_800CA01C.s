	opt	c+, at+, e+, n-
	section overlay.text

	xdef s15b_800CA01C
s15b_800CA01C:
	dw 0x27BDFFD0 ; 800CA01C
	dw 0x24020001 ; 800CA020
	dw 0xA7A40010 ; 800CA024
	dw 0x27A40010 ; 800CA028
	dw 0xAFBF0028 ; 800CA02C
	dw 0xA7A20012 ; 800CA030
	dw 0x0C005941 ; 800CA034
	dw 0xA7A50014 ; 800CA038
	dw 0x8FBF0028 ; 800CA03C
	dw 0x00000000 ; 800CA040
	dw 0x03E00008 ; 800CA044
	dw 0x27BD0030 ; 800CA048
