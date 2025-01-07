// I think this object was originally implemented in assembly.
//
// mask.obj in 5thMix's MTS builds have no source filename (as GCC inserts
// a .file directive in the assembly output) and PSY-Q object parsers usually
// complain about an unknown record type or some other bullshit.

void SetExMask()
{
#ifndef PSX_DEV_EXE
    // unknown psyq-specific debug function ?
    __asm__("break 1030");
#endif
}

void *mts_get_bss_tail(void)
{
#ifdef PSX_DEV_EXE
    // linker-defined symbol
    extern unsigned char __bss_end[];

    return (void *)__bss_end;
#else
    // linker-defined symbol
    extern unsigned char _bss_orgend[];

    return (void *)_bss_orgend;
#endif
}
