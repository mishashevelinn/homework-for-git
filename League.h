//
// Created by tal5s on 05/05/2020.
//
#include "Team.h"
#include "Match.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef EX4_LEAGUE_H
#define EX4_LEAGUE_H


typedef struct {
    int num_matches, num_teams;
    Team **teams;
    Match **matches;
} League;

League *LeagueCreate();

void LeagueDestroy(League *league);

void read_teams(League *league, const char *file_name);

void read_matches(League *league, const char *file_name);

int num_wins(League *league, Team *t);

int num_draws(League *league, Team *t);

int num_losses(League *league, Team *t);
//returns number of matches given team participated in
int num_matches(League *league, Team *t);

int num_GF(League *league, Team *t);

int num_GA(League *league, Team *t);

void print_table(League *league); //HW4_LEAGUE_H

#endif //EX4_LEAGUE_H
