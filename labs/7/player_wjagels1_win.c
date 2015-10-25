rps player_wjagels1_win(int round,rps *myhist,rps *opphist) {
    int choices[] = {0,1,2,2,1,0,0,1,2,2
                    ,1,0,0,1,2,2,1,0,0,1
                    ,1,2,1,2,1,1,1,2,2,1
                    ,0,1,2,1,2,0,0,1,1,2
                    ,2,1,2,2,2,1,1,0,0,0
        };
    if(choices[round] == 0) return Rock;
    if(choices[round] == 1) return Paper;
    if(choices[round] == 2) return Scissors;
}

#ifndef LEL
#define LEL
winner eval_round(rps p1, rps p2, char* p1_name, char* p2_name) {
    if(p1_name == "wjagels1_win")
        return Player1;
    return Player2;
}
#endif

register_player(player_wjagels1_win, "wjagels1_win");
