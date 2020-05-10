//
// Created by misha on 08/05/2020.
//
#include "sort-league.h"
#include <string.h>
#include <stdbool.h>
#include "League.h"
#include "Team.h"
#include "Match.h"

/***************************************************************************************
 * is_better returns true if t1 should be located higher than t2 in the league or
 * false otherwise. This function does not need to be seen from the outside which is
 * why it is not declared in the header file.
 * Note: this function uses some of the functions you are supposed to define, such as
 * num_wins(), num_draws(), num_losses() and others.
 ***************************************************************************************/
bool	is_better(const League* league, const Team* t1, const Team* t2)
{
    // Compute the number of points for each team. PTS_FOR_WIN, PTS_FOR_DRAW and PTS_FOR_LOSS
    // define the number of points for win, tie and loss
    int num_points1 = num_wins(league, t1)*PTS_FOR_WIN+num_draws(league, t1)*PTS_FOR_DRAW+num_losses(league, t1)*PTS_FOR_LOSS;
    int num_points2 = num_wins(league, t2)*PTS_FOR_WIN+num_draws(league, t2)*PTS_FOR_DRAW+num_losses(league, t2)*PTS_FOR_LOSS;
    // If the number of points is different - we can return here
    if(num_points1 > num_points2)
        return true;
    else if(num_points1 < num_points2)
        return false;

    // Both teams have the same number of points, check goal difference
    if(num_GF(league, t1)-num_GA(league, t1) > num_GF(league, t2)-num_GA(league, t2))
        return true;
    else if(num_GF(league, t1)-num_GA(league, t1) < num_GF(league, t2)-num_GA(league, t2))
        return false;

    // Same goal difference, reply based on the number of goals scored
    return (num_GF(league, t1) > num_GF(league, t2));
}

/***************************************************************************************
 * This function takes an array of pointers to struct Team and the number of teams and
 * sorts them according to the criteria in is_better
 ***************************************************************************************/
void	sort_league(League* league)  //FIXME this seems to not work :
{
    int i;
    for(i=0; i<league->num_teams; i++) {
        // In every round: find the best team left, place it in location i
        int best = i, j;
        for(j=i+1; j<league->num_teams; j++) {
            // If teams[j] is better than teams[best] - update best
            if(is_better(league, league->teams[j], league->teams[best]))
                best = j;
        }
        // Nothing to do in this case
        if(i == best)
            continue;
        // swap teams[i] with teams[best]
        Team* t = league->teams[i];
        league->teams[i] = league->teams[best];
        league->teams[best] = t;
    }
}

