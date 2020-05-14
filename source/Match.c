//
// Created by tal5s on 05/05/2020.
//

#include "Team.h"
#include "Match.h"

Match *MatchCreate(Team *teamH, Team *teamG, int goalH, int goalG)
{
    Match *match;
    match = (Match *) malloc(sizeof(Match));
    if (match == NULL)
    {
        printf("Failed to allocate %lu bytes\n", sizeof(Match));
        exit(1);
    }
    match->teamHost = teamH;
    match->teamGuest = teamG;
    match->goalGuest = goalG;
    match->goalHost = goalH;
    return match;

}

void MatchDestroy(Match *match)
{
    TeamDestroy(match->teamGuest);//destroy guest of match
    TeamDestroy(match->teamHost);//destroy host of match
    free(match);//destroy match itself
}

bool team_participated(const Match *match, const Team *team)
{
    return ((team->TeamName == match->teamGuest->TeamName) || (team->TeamName == match->teamHost->TeamName));
}

bool match_tied(const Match *match)
{
    return match->goalGuest == match->goalHost;
}

bool team_won(const Match *match, const Team *team)
{
    if (!team_participated(match, team))
    {
        printf("Error in file %s, line %d\n", __FILE__, __LINE__);
        printf("Team %s has not participated in match\n", team->TeamName);
        exit(-1);
    }
    if (match->goalHost == match->goalGuest)
    {
        return false;
    }
    if (match->goalGuest > match->goalHost)
    {
        return match->teamGuest->TeamName == team->TeamName;
    }
    return match->teamHost->TeamName == team->TeamName;
}

bool team_lost(const Match *match, const Team *team)
{
    if (!team_participated(match, team))
    {
        printf("Error in file %s, line %d\n", __FILE__, __LINE__);
        printf("Team %s has not participated in match\n", team->TeamName);
        exit(-1);
    }
    return (!match_tied(match) && !team_won(match, team));

}

int GF(const Match *match, const Team *team)
{
    if (!team_participated(match, team))
    {
        printf("Error in file %s, line %d\n", __FILE__, __LINE__);
        printf("Team %s has not participated in match\n", team->TeamName);
        exit(-1);
    }
    return (match->teamGuest == team) ? match->goalGuest : match->goalHost;

}

int GA(const Match *match, const Team *team)
{
    if (!team_participated(match, team))
    {
        printf("Error in file %s, line %d\n", __FILE__, __LINE__);
        printf("Team %s has not participated in match\n", team->TeamName);
        exit(-1);
    }
    return (match->teamGuest == team) ? match->goalHost : match->goalGuest;


}