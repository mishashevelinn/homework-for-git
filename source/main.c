
#include <stdio.h>
#include "sort-league.h"
#include "Team.h"
#include "Match.h"
#include "League.h"


int main(int argc, const char *argv[]) {
    switch (argc) { // check if the given arguments are correct (need 2 file's names) 
        case 1: fprintf(stderr, "Program takes 2 parameters: (char* file_name1, char* file_name2). No parameters given\n");
            exit(-1); // given only 1 parameter (file's names not given)
        case 2: fprintf(stderr, "Program takes 2 parameters:(char* file_name1, char* file_name2). 1 parameter given\n");
            exit(-1); // given 2 parameter (only 1 file name given, 1 missed)

    }
    League *liga1 = LeagueCreate(); // create new League
    read_teams(liga1, argv[1]); // read from file "team.txt" the teams for league
    read_matches(liga1, argv[2]); // read from file "matches.txt" the matches for league
    sort_league(liga1); // sort the league table by the points of each team
    print_table(liga1); // print the league table
    LeagueDestroy(liga1); // free all the memory of league, teams, matches

    return 0;
}



