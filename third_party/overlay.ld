__heap_base = MAX(__select1_end, __s00a_end);
SECTIONS {		
	OVERLAY __bss_end : NOCROSSREFS SUBALIGN(4)
	{
		.ovlyload
        {
            load_all_overlays_here = .;
        }
		
		.select1
        {			
			KEEP(objs/source/overlays/select1/*.o(.text))
			__select1_ctor = .;
			KEEP(objs/source/overlays/select1/*.o(.rodata*))
			KEEP(objs/source/overlays/select1/*.o(.text.startup._GLOBAL__*))
			KEEP(objs/source/overlays/select1/*.o(.text.*))
            KEEP(objs/source/overlays/select1/*.o(.sdata*))
			KEEP(objs/source/overlays/select1/*.o(.data*))
            KEEP(objs/source/overlays/select1/*.o(.sbss*))
			KEEP(objs/source/overlays/select1/*.o(.bss*))
			KEEP(objs/source/overlays/select1/*.o(.ctors))
			
			. = ALIGN(4);
			__select1_end = .;			
		}

        .s00a
        {
			KEEP(objs/source/overlays/s00a/*.o(.text))
			__s00a_ctor = .;
			KEEP(objs/source/overlays/s00a/*.o(.rodata*))
			KEEP(objs/source/overlays/s00a/*.o(.text.startup._GLOBAL__*))
			KEEP(objs/source/overlays/s00a/*.o(.text.*))
            KEEP(objs/source/overlays/s00a/*.o(.sdata*))
			KEEP(objs/source/overlays/s00a/*.o(.data*))
            KEEP(objs/source/overlays/s00a/*.o(.sbss*))
			KEEP(objs/source/overlays/s00a/*.o(.bss*))
			KEEP(objs/source/overlays/s00a/*.o(.ctors))
			
			. = ALIGN(4);
			__s00a_end = .;			
		}
	}
}