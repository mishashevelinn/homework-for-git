
#include <stdio.h>
#include <wchar.h>
#include "sort-league.h"
#include "Team.h"
#include "Match.h"
#include "League.h"


int main(int argc, char *argv[]) {
    if (argc != 3){
        printf("program needs two parameters input");
    }
    League *liga1 = LeagueCreate();
    read_teams(liga1, argv[1]);
    read_matches(liga1, argv[2]);
    sort_league(liga1);
    print_table(liga1);
    LeagueDestroy(liga1);

    return 0;
}



