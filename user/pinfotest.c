#include "kernel/types.h"
#include "kernel/pinfo.h"
#include "user/user.h"

int main() {
    struct pinfo info[64];
    int n = getpinfo(info, 64);
    if (n < 0) {
        fprintf(2, "getpinfo failed\n");
        exit(1);
    }

    printf("PID\tSTATE\tLEVEL\tRUNTICKS\tNSCHED\tCTIME\tNAME\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%s\n",
            info[i].pid,
            info[i].state,
            info[i].level,
            info[i].runticks,
            info[i].nsched,
            info[i].ctime,
            info[i].name);
    }
    exit(0);
}