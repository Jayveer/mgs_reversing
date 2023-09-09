#include "linker.h"
#include "menuman.h"
#include "radio.h"
#include "psyq.h"

extern int gRadioCodecIdx_800AB770;
int        gRadioCodecIdx_800AB770;

extern RadioMemory gRadioMemory_800BDB38[RADIO_MEMORY_COUNT];

void menu_InitRadioMemory_8004E0EC(void)
{
    RadioMemory *contact;
    int          i;

    contact = &gRadioMemory_800BDB38[0];
    for (i = RADIO_MEMORY_COUNT - 1; i >= 0; i--)
    {
        contact->frequency = 0;
        contact++;
    }
}

void menu_SetRadioMemory_8004E110(int frequency, const char *name)
{
    RadioMemory *contact;

    if (!(contact = menu_radio_table_find_8004D380(frequency)))
    {
        contact = menu_radio_table_next_free_8004D3B8();
    }

    if (!strcmp(name, "clear"))
    {
        gRadioCodecIdx_800AB770 = 0;
        contact->frequency = 0;
    }
    else
    {
        contact->frequency = frequency;
        strcpy(contact->name, name);
    }

    menu_radio_compact_free_vars_8004D3D8();
}
