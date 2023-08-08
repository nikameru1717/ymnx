#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <trackdl.hpp>
#include <switch.h>

int main(int argc, char *argv[])
{
    consoleInit(NULL);

    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    PadState pad;
    padInitializeDefault(&pad);

    socketInitializeDefault();
    nxlinkStdio();

    yandex_request();

    printf("\e[32mExit.\e[0m");

    while (appletMainLoop())
    {
        padUpdate(&pad);

        u64 kDown = padGetButtonsDown(&pad);

        if (kDown & HidNpadButton_Plus)
            break;

        consoleUpdate(NULL);
    }

    socketExit();
    consoleExit(NULL);
    return 0;
}