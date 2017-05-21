#include "extmem.h"
#include "operation.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define log

char *rrel = "R", *rcol1 = "A", *rcol2 = "B";
char *srel = "S", *scol1 = "C", *scol2 = "D";

void generate_data()
{
    printf("Try to create data for R...\n");
    int r = create_data(rrel, rcol1, 1, 40, rcol2, 1, 1000, 2);
    printf("Try to create data for S...\n");
    int s = create_data(srel, scol1, 20, 60, scol2, 1, 1000, 4);
    printf("Done!\n");
}
void l_search()
{
    printf("Liner search for R.A = 40 or S.C = 60\n");
    int line_s_r = liner_search(rrel, rcol1, EQ, 40);
    int line_s_s = liner_search(srel, scol1, EQ, 60);
    int addr_merge = link_addr(line_s_r, line_s_s);
    printf("Result is :\n");
    read_data(addr_merge);
    printf("Done!\n");
}
void b_search()
{
    printf("Binary search for R.A = 40 or S.C = 60\n");
    int b1 = binary_search(rrel, rcol1, EQ, 40);
    int b2 = binary_search(srel, scol1, EQ, 60);
    int addr_merge = link_addr(b1, b2);
    printf("Result is: \n");
    read_data(addr_merge);
    printf("Done!\n");
}
void p_action()
{
    printf("Project for R.A\n");
    int addr = project(rrel, rcol1);
    printf("Result is: \n");
    read_data(addr);
    printf("Done!\n");
}
void union_action()
{
    int r1[2], r2[2];
    get_start_addr_from_file(rrel, rcol1, r1);
    get_start_addr_from_file(srel, scol1, r2);
    combine(r1[0], r2[0]);
}
void print_menu()
{
    printf("|----------------------- Menu ------------------------|\n");
    printf("| 1. Create Data                                      |\n");
    printf("| 2. Look Data                                        |\n");
    printf("| 3. Liner Search                                     |\n");
    printf("| 4. Binary Search                                    |\n");
    printf("| 5. Project                                          |\n");
    printf("| 6. union                                            |\n");
    printf("| 0. END                                              |\n");
    printf("|-----------------------------------------------------|\n");
    printf("Input You Choice Now: ");
}
int main(int argc, char** argv)
{
    init();
    int option;
    int addr_saver[2];

    // n_merge_sort(s, 0);
    int finished = 0;
    while (!finished) {
        print_menu();
        if (scanf("%d", &option) != 1) {
            while ((getchar()) != '\n') {
                printf("Input Error Try Again!\n");
                scanf("%d", &option);
            }
        }
        fflush(stdin);
        switch (option) {
        case 1:
            generate_data();
            break;
        case 2:
            get_start_addr_from_file(rrel, rcol1, addr_saver);
            read_data(addr_saver[0]);
            break;
        case 3:
            l_search();
            break;
        case 4:
            b_search();
            break;
        case 5:
            p_action();
            break;
        case 6:
            union_action();
            break;
        case 0:
            finished
                = 1;
            break;
        default:
            printf("Bad Option!\n");
        }
    }
    return 0;
}
