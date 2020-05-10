
#include <stdio.h>
#include <wchar.h>
#include "sort-league.h"
#include "Team.h"
#include "Match.h"
#include "League.h"


int main() {
    League *liga1 = LeagueCreate();
    read_teams(liga1, "teams.txt");
    read_matches(liga1, "matches.txt");
    sort_league(liga1);
    print_table(liga1);
    LeagueDestroy(liga1);
    printf("%d", liga1->num_matches);


    return 0;
}
