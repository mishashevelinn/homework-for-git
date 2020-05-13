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

} Match;

Match * MatchCreate(Team* teamH, Team* teamG, int goalH, int goalG);

void MatchDestroy(Match * match);

bool team_participated(const Match *match, const Team *team);

bool match_tied(const Match *match);

bool team_won(const Match *match, const Team *team);

bool team_lost(const Match *match, const Team *team);

int GF(const Match *match, const Team *team);

int GA(const Match *match, const Team *team);

#endif //EX4_MATCH_H
