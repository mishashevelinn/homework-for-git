
#include <stdio.h>
#include "sort-league.h"
#include "Team.h"
#include "Match.h"
#include "League.h"


int main(int argc, const char *argv[]) {
    switch (argc) {
        case 1: fprintf(stderr, "Program takes 2 parameters: (char* file_name1, char* file_name2). No parameters given\n");
            exit(-1);
        case 2: fprintf(stderr, "Program takes 2 parameters:(char* file_name1, char* file_name2). 1 parameter given\n");
            exit(-1);

    }
    League *liga1 = LeagueCreate();
    read_teams(liga1, argv[1]);
    read_matches(liga1, argv[2]);
    sort_league(liga1);
    print_table(liga1);
    LeagueDestroy(liga1);

    return 0;
}



