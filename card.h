/*                           *\  
    DO NOT MODIFY THIS FILE
\*                           */

#include <iostream>
#include <string>

#ifndef CARD_H
#define CARD_H

const int ACE = 1;
const int JACK = 11;
const int QUEEN = 12;
const int KING = 13;
const std::string SUITS = "CDHS";

/* Rank/Suit Order
    1. 1(A), 2-10, 11(J), 12(Q), 13(K)
    2. C, D, H, S 
*/
struct Card {
    int rank;
    char suit;
};

inline std::string strcard(const Card& card) {
    std::string str;
    int r = card.rank;
    if(r >= 2 && r <= 10) {
        str = std::to_string(r);
    } else {
        switch(r) {
            case ACE: str = "A"; break;
            case JACK: str = "J"; break;
            case QUEEN: str = "Q"; break;
            case KING: str = "K"; break;
            default: str = "?"; break;
        }
    }
    return str + card.suit;
}

inline ostream& operator<<(ostream& out, const Card& card) {
    out << strcard(card);
    return out;
}

#endif
