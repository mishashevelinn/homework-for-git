//
// Created by tal5s on 05/05/2020.
//

#include "Team.h"
#include "Match.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

Match * MatchCreate(Team* teamH, Team* teamG, int goalH, int goalG){
    Match *match;
    match = (Match *) malloc(sizeof(Match));
    if(match == NULL) {
        printf("Failed to allocate %lu bytes\n", sizeof(Match));
        exit(1);
    }
    match->teamHost = teamH;
    match->teamGuest = teamG;
    match->goalGuest = goalG;
    match->goalHost = goalH;
    return match;

}

void MatchDestroy(Match * match){
    free(match);
}

bool team_participated(Match *match, Team *team) {
    return ((team->TeamName==match->teamGuest->TeamName) || (team->TeamName == match->teamHost->TeamName));
}

bool match_tied(Match* match){
    return match->goalGuest==match->goalHost;
}
bool team_won(Match* match, Team* team){
    if(!team_participated(match, team)){
        printf("Error in file %s, line %d\n", __FILE__, __LINE__);
        printf("Team %s has not participated in match\n", team->TeamName);
        exit(-1);
    }
    if(match->goalHost==match->goalGuest){
        return false;
    }
    if(match->goalGuest>match->goalHost){
        return match->teamGuest->TeamName==team->TeamName;
        }
    return match->teamHost->TeamName==team->TeamName;
    }


bool team_lost(Match* match, Team* team) {
    if (!team_participated(match, team)) {
        printf("Error in file %s, line %d\n", __FILE__, __LINE__);
        printf("Team %s has not participated in match\n", team->TeamName);
        exit(-1);
    }
    return (!match_tied(match) && !team_won(match, team));

}
int GF(Match* match, Team* team){
    if (!team_participated(match, team)) {
        printf("Error in file %s, line %d\n", __FILE__, __LINE__);
        printf("Team %s has not participated in match\n", team->TeamName);
        exit(-1);
    }
    return (match->teamGuest == team) ? match->goalGuest : match->goalHost;

}
int GA(Match* match, Team* team){
    if (!team_participated(match, team)) {
        printf("Error in file %s, line %d\n", __FILE__, __LINE__);
        printf("Team %s has not participated in match\n", team->TeamName);
        exit(-1);
    }
    return (match->teamGuest == team) ?  match->goalHost : match->goalGuest;


}