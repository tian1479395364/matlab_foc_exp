#include <stddef.h>
#include <stdio.h>
#include "FOC_CURRENTLOOP_DOUBLE.h"

void rt_OneStep(void);
void rt_OneStep(void)
{
    static boolean_T OverrunFlag = false;
    if (OverrunFlag) {
        return;
    }

    OverrunFlag = true;
    FOC_CURRENTLOOP_DOUBLE_step();
    OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
    (void)(argc);
    (void)(argv);
    FOC_CURRENTLOOP_DOUBLE_initialize();
    printf("Warning: The simulation will run forever. "
           "Generated ERT main won't simulate model step behavior. "
           "To change this behavior select the 'MAT-file logging' option.\n");
    fflush((NULL));
    while (1) {
    }

    return 0;
}
