	opt	c+, at+, e+, n-
	section overlay.text

	xdef s02c_camshake_800E1F0C
s02c_camshake_800E1F0C:
	dw 0x27BDFFE0 ; 800E1F0C
	dw 0xAFB10014 ; 800E1F10
	dw 0x00808821 ; 800E1F14
	dw 0xAFB20018 ; 800E1F18
	dw 0x00A09021 ; 800E1F1C
	dw 0x24040005 ; 800E1F20
	dw 0x24050048 ; 800E1F24
	dw 0xAFBF001C ; 800E1F28
	dw 0x0C005439 ; 800E1F2C
	dw 0xAFB00010 ; 800E1F30
	dw 0x00408021 ; 800E1F34
	dw 0x12000012 ; 800E1F38
	dw 0x02002021 ; 800E1F3C
	dw 0x3C05800E ; 800E1F40
	dw 0x24A51D18 ; 800E1F44
	dw 0x3C06800E ; 800E1F48
	dw 0x24C61E94 ; 800E1F4C
	dw 0x3C07800E ; 800E1F50
	dw 0x0C005453 ; 800E1F54
	dw 0x24E73A2C ; 800E1F58
	dw 0x02002021 ; 800E1F5C
	dw 0x02202821 ; 800E1F60
	dw 0x0C0387A7 ; 800E1F64
	dw 0x02403021 ; 800E1F68
	dw 0x04410006 ; 800E1F6C
	dw 0x02001021 ; 800E1F70
	dw 0x0C005472 ; 800E1F74
	dw 0x02002021 ; 800E1F78
	dw 0x080387E2 ; 800E1F7C
	dw 0x00001021 ; 800E1F80
	dw 0x02001021 ; 800E1F84
	dw 0x8FBF001C ; 800E1F88
	dw 0x8FB20018 ; 800E1F8C
	dw 0x8FB10014 ; 800E1F90
	dw 0x8FB00010 ; 800E1F94
	dw 0x03E00008 ; 800E1F98
	dw 0x27BD0020 ; 800E1F9C