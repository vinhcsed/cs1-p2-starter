#include "deck.h"

// Implement Deck methods here

ostream& operator<<(ostream& out, const Deck& deck) {
    deck.print(out);
    return out;
}
