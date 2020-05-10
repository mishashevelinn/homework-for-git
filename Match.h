//
// Created by tal5s on 05/05/2020.
//
#include <stdbool.h>
#include "Team.h"
#ifndef EX4_MATCH_H
#define EX4_MATCH_H

typedef struct{
    Team* teamHost;
    Team* teamGuest;
    int goalHost, goalGuest;

}Match;
Match * MatchCreate(Team* teamH, Team* teamG, int goalH, int goalG);
void MatchDestroy(Match * match);

bool team_participated(Match *match, Team *team);
bool match_tied(Match* match);
bool team_won(Match* match, Team* team);
bool team_lost(Match* match, Team* team);
int GF(Match* match, Team* team);
int GA(Match* match, Team* team);

#endif //EX4_MATCH_H
