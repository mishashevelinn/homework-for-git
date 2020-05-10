//
// Created by tal5s on 05/05/2020.
//
#include <stdio.h>
#include <stdlib.h>
#ifndef EX4_TEAM_H
#define EX4_TEAM_H


typedef struct {
    const char* TeamName;
} Team;
Team * TeamCreate (const char* name);

void TeamDestroy ( Team *team);

#endif //EX4_TEAM_H
