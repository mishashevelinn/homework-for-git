//
// Created by tal5s on 05/05/2020.
//

#include "Team.h"
#include "Match.h"
#include "League.h"
#include <string.h>
#include "sort-league.h"

/***************************************************************************************
 *Dynamically allocating the memory according to data structure League, and initialize its
 * fields which are pointers to two arrays of pointers: firs array - pointers to Teams,
 * second array - pointer to matches. Reads data from text files while checking format of input.
 * calculates some football league data. Provides memory cleaner. Prints table of football league statistics
 ***************************************************************************************/
//dynamically allocating memory for League struct type, alarming if fails
League *LeagueCreate() {
    League *league;
    league = (League *) malloc(sizeof(League));
    if (league == NULL) {
        printf("Failed to allocate %lu bytes\n", sizeof(League));
        exit(1);
    }
    return league;   //returns pointer to League
}
//garbage cleaner fot League type object, takes pointer to league and cleans its fields which are arrays in loop
void LeagueDestroy(League *league) {
    Team *team;
    int i;
    for (i = 0; i < league->num_teams; i++)//destroy teams in league
    {
        team = league->teams[i];
        TeamDestroy(team);                      //using native Team cleaner --see Team.c
    }
    Match *match;                               //also in line 42
    for (i = 0; i < league->num_matches; i++)//destroy matches in league
    {
        match = league->matches[i];
        MatchDestroy(match);                    //native Match cleaner --see Match.c
    }
    free(league);//destroy league itself
}//reads team names from text file and initializes memory allocated for teams->Team
void read_teams(League *league, const char *file_name) {
    league->teams = NULL;    //first we want to nullify all pointers and values
    league->num_teams = 0;
    char *line = NULL;
    size_t size = 0;
    ssize_t len = 0;
    FILE *fp = fopen(file_name, "r");   //read from file
    if (!fp) {
        fprintf(stderr, "error in line %d, failed to open a file\n", __LINE__);
        exit(-1);
    }
    //getline() allocates a memory for the line and returns a pointer to it!
    while ((len = getline(&line, &size, fp)) != EOF) {
        line[len - 1] = 0;  //get rid of \n
        league->teams = (Team **) realloc(league->teams, sizeof(Team) * (league->num_teams + 1));
        league->teams[league->num_teams] = TeamCreate(line);
        league->num_teams++;
    }
    //line still occupies a memory allocated
    free(line);
    fclose(fp);
}

void read_matches(League *league, const char *file_name) {
    league->matches = NULL;
    league->num_matches = 0;
    FILE *fp = fopen(file_name, "r");
    if (!fp) {
        fprintf(stderr, "error in line %d, failed to open a file\n", __LINE__);
        exit(-1);
    }
    size_t len = 0;
    char ptrH[10];
    char ptrG[10];
    int goalH = -1;
    int goalG = -1;
    while ((len = (size_t) fscanf(fp, "%s\t%s\t%d\t%d", ptrH, ptrG, &goalH, &goalG)) != EOF) {
        if (len != 4) {
            printf("line %d in file %s is not in expected format\n", league->num_matches + 1, file_name);
            exit(1);
        }
        league->matches = (Match **) realloc(league->matches, sizeof(Match) * league->num_matches);
        Team *teamH = NULL;
        Team *teamG = NULL;
        int i;
        for (i = 0; i < league->num_teams; i++) {
            if (!strcmp((league->teams[i]->TeamName), ptrH)) {
                teamH = league->teams[i];
            } else if (!strcmp((league->teams[i]->TeamName), ptrG)) {
                teamG = league->teams[i];
            }
            if (teamH != NULL && teamG != NULL) {
                break;
            }
        }
        league->matches[league->num_matches] = MatchCreate(teamH, teamG, goalH, goalG);
        league->num_matches++;
    }
    fclose(fp);
}

int num_wins(const League *league, const Team *t) {
    int counter = 0;
    int i;
    for (i = 0; i < league->num_matches; ++i) {
        if (team_participated(league->matches[i], t) && team_won(league->matches[i], t)) {
            counter++;
        }
    }
    return counter;
}

int num_draws(const League *league, const Team *t) {
    int counter = 0;
    int i;
    for (i = 0; i < league->num_matches; ++i) {
        if (team_participated(league->matches[i], t) && match_tied(league->matches[i])) {
            counter++;
        }
    }
    return counter;
}

int num_losses(const League *league, const Team *t) {
    int counter = 0;
    int i;
    for (i = 0; i < league->num_matches; ++i) {
        if (team_participated(league->matches[i], t) && team_lost(league->matches[i], t)) {
            counter++;
        }
    }
    return counter;
}

int num_matches(const League *league, const Team *team) {
    int counter = 0;
    int i;
    for (i = 0; i < league->num_matches; ++i) {
        if (team_participated(league->matches[i], team)) {
            counter++;
        }
    }
    return counter;

}

int num_GF(const League *league, const Team *t) {
    int counter = 0;
    int i;
    for (i = 0; i < league->num_matches; ++i) {
        if (team_participated(league->matches[i], t)) {
            counter += GF(league->matches[i], t);
        }
    }
    return counter;
}

int num_GA(const League *league, const Team *t) {
    int counter = 0;
    int i;
    for (i = 0; i < league->num_matches; ++i) {
        if (team_participated(league->matches[i], t)) {
            counter += GA(league->matches[i], t);
        }
    }
    return counter;
}

void print_table(const League *league) {
    printf("Team\t\t\tGames\t\tWins\t\tTies\t\tLosses\t\tGF\t\tGA\t\tPoints\n");
    int j;
    for (j = 0; j < league->num_teams; ++j) {
        printf("%-10s\t\t%-10d\t%-10d\t%-10d\t%-10d\t%-10d\t%-10d\t%-10d\n", league->teams[j]->TeamName,
               num_matches(league, league->teams[j]),
               num_wins(league, league->teams[j]), num_draws(league, league->teams[j]),
               num_losses(league, league->teams[j]),
               num_GF(league, league->teams[j]), num_GA(league, league->teams[j]),
               num_wins(league, league->teams[j]) * PTS_FOR_WIN
               + num_draws(league, league->teams[j]) * PTS_FOR_DRAW +
               num_losses(league, league->teams[j]) * PTS_FOR_LOSS);

    }
}


