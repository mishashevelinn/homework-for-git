//
// Created by tal5s on 05/05/2020.
//

#include "Team.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Team * TeamCreate (const char *name){
    Team *t;
    t = (Team *) malloc(sizeof(Team));
    if(t == NULL) {
        printf("Failed to allocate %lu bytes\n", sizeof(Team));
        exit(1);
    }

    t->TeamName = strdup(name);
    return t;
}

void TeamDestroy ( Team *team){
    free(team);
}