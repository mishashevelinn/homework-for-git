//
// Created by misha on 08/05/2020.
//

#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include "League.h"
#include "Team.h"

#define	PTS_FOR_WIN	3
#define	PTS_FOR_DRAW	1
#define	PTS_FOR_LOSS	0

/***************************************************************************************
 * This function takes an array of pointers to struct Team and the number of teams and
 * sorts them according to the criteria in is_better
 ***************************************************************************************/
void	sort_league(League* league);

#endif
