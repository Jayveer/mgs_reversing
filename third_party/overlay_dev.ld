__heap_base = __bss_end;
SECTIONS {		
	OVERLAY 0x80200000 : NOCROSSREFS SUBALIGN(4)
	{
		.ovlyload
        {
            load_all_overlays_here = .;
        }
		
		.dev
		{
			KEEP(../obj_psx_dev/src/overlays/*.o(.text))
			__select1_ctor = .;
			KEEP(../obj_psx_dev/src/overlays/*.o(.rodata*))
			KEEP(../obj_psx_dev/src/overlays/*.o(.text.startup._GLOBAL__*))
			KEEP(../obj_psx_dev/src/overlays/*.o(.text.*))
            KEEP(../obj_psx_dev/src/overlays/*.o(.sdata*))
			KEEP(../obj_psx_dev/src/overlays/*.o(.data*))
            KEEP(../obj_psx_dev/src/overlays/*.o(.sbss*))
			KEEP(../obj_psx_dev/src/overlays/*.o(.bss*))
			KEEP(../obj_psx_dev/src/overlays/*.o(.ctors))
			
			. = ALIGN(4);
			__dev_end = .;				
		}
	}
}