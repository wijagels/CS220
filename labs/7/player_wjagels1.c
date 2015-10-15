#include "rps.h"

winner eval_round_silent(rps p1, rps p2, char * p1_name, char * p2_name) {
	if ((p1==Unknown) && (p2 == Unknown)) return Tie;
	if (p1==Unknown) return Player2;
	if (p2==Unknown) return Player1;
	if (p1==p2) return Tie;
	if (p1==Rock && p2==Scissors) return Player1;
	if (p1==Scissors && p2==Paper) return Player1;
	if (p1==Paper && p2==Rock) return Player1;
	return Player2;
}

struct chain {
    rps first;
    rps second;
    rps third;
    int occurrences;
};

void chainInsert(struct chain* c, struct chain insert) {
    for(int i=0;i<500;i++) {
        if(c[i].first == insert.first && c[i].second == insert.second && c[i].third == insert.third) {
            c[i].occurrences++;
            return;
        }
        if(c[i].occurrences == 0) {
            insert.occurrences = 1;
            c[i] = insert;
            return;
        }
    }
}

rps chainChoice(struct chain* c, rps first, rps second) {
    struct chain possible[5];
    for(int i=0;i<5;i++) {
        possible[i].occurrences=0;
        possible[i].first = Unknown;
        possible[i].second = Unknown;
        possible[i].third = Unknown;
    }
    int k=0;
    for(int i=0;i<500;i++) {
        if(c[i].first == first && c[i].second == second) {
            possible[k++] = c[i];
        }
    }
    int max = 0;
    int at = 0;
    for(int i=0;i<5;i++) {
        if(possible[i].occurrences > max) {
            max = possible[i].occurrences;
            at = i;
        }
    }
    rps enemy = possible[at].third;
    if(enemy == Rock)
        return Paper;
    if(enemy == Paper)
        return Scissors;
    else // Scissors
        return Rock;
}

rps player_wjagels1(int round,rps *myhist,rps *opphist) {
    // time_t t;
    // if (round==0) srand((unsigned) time(&t)); /* Intializes random number generator */
    // char i = rand()%3;
    // switch(i) {
    //     case 0: return Rock;
    //     case 1: return Scissors;
    // }
    // return Paper;
    srand(0);
    // if(round<3) {
    //     time_t t;
    //     srand((unsigned) time(&t)); /* Intializes random number generator */
    //     char i = rand()%3;
    //     rps mv = Paper;
    //     switch(i) {
    //         case 0: mv = Rock;
    //         case 1: mv = Scissors;
    //     }
    //     srand(0);
    //     return mv;
    // }
    int rate[3];
    int chosen[3];
    for(int i=0;i<3;i++) {
        rate[i]=0;
        chosen[i]=0;
    }
    // Run analysis on which choices win most often.
    for(int i=0;i<round;i++) {
        winner w = eval_round_silent(myhist[i], opphist[i], "me", "enemy");
        if(w == Player1) {
            if(myhist[i] == Rock) {
                rate[0]++;
                chosen[0]++;
            }
            else if(myhist[i] == Paper) {
                rate[1]++;
                chosen[1]++;
            }
            else {
                rate[2]++;
                chosen[2]++;
            }
        }
        else if(w == Player2) {
            if(myhist[i] == Rock) {
                rate[0]--;
                chosen[0]++;
            }
            else if(myhist[i] == Paper) {
                rate[1]--;
                chosen[1]++;
            }
            else {
                rate[2]--;
                chosen[2]++;
            }
        }
        else {
            // Tie.
            if(myhist[i] == Rock) {
                chosen[0]++;
            }
            else if(myhist[i] == Paper) {
                chosen[1]++;
            }
            else {
                chosen[2]++;
            }
        }
    }
    struct chain* moves = (struct chain*)malloc(sizeof(struct chain) * 500);
    for(int i=0;i<500;i++) {
        moves[i].first = Unknown;
        moves[i].second = Unknown;
        moves[i].third = Unknown;
        moves[i].occurrences = 0;
    }
    for(int i=0;i<round;i++) {
        if(i+2 < round) {
            struct chain meirl;
            meirl.first = opphist[i];
            meirl.second = opphist[i+1];
            meirl.third = opphist[i+2];
            chainInsert(moves, meirl);
        }
    }
    printf("Rock: %d/%d Paper: %d/%d Scissors: %d/%d\n", rate[0], chosen[0], rate[1], chosen[1], rate[2], chosen[2]);
    printf("Chain: %s, %s, %s, %d\n", fmt_rps(moves[1].first), fmt_rps(moves[1].second), fmt_rps(moves[1].third), moves[1].occurrences);
    rps me = chainChoice(moves, opphist[round-1], opphist[round-2]);
    free(moves);
    // First round, no idea what to do.
    if(round == 0) return Paper;
    // Confuse the enemy by pretending we're just trying to beat the last move.
    if(round < 3) {
        if(opphist[round-1] == Rock)
            return Paper;
        if(opphist[round-1] == Paper)
            return Scissors;
        return Rock;
    }
    return me;
}



#ifndef EXDEE
#define EXDEE
int rand(void) {
    return 4; // chosen by fair dice roll.
              // guaranteed to be random.
}
#endif

register_player(player_wjagels1,"wjagels1");

