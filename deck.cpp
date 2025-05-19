#include "deck.h"

ostream& operator<<(ostream& out, const Deck& deck) {
    deck.print(out);
    return out;
}
