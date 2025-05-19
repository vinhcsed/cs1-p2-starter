#include <sstream>
#include <iomanip>
#include "deck.h"

void assertTrue(string testName, bool assertion) {
    string title = "Test ";
    title += testName;
    cout << setw(21) << title;
    if(assertion) { cout << ": PASSED" << endl; } 
    else { cout << ": FAILED" << endl; }
}

void testBasicDeck() {
    cout << "BASIC TEST" << endl;
    Deck deck;
    ostringstream oss;
    
    oss << deck;
    cout << deck;
    assertTrue(
        "Constructor",
        oss.str() ==
        "[AC, AD, AH, AS, 2C, 2D, 2H, 2S, 3C, 3D, 3H, 3S, 4C, 4D, 4H, 4S, 5C, 5D, 5H, 5S, 6C, 6D, 6H, 6S, 7C, 7D, 7H, 7S, 8C, 8D, 8H, 8S, 9C, 9D, 9H, 9S, 10C, 10D, 10H, 10S, JC, JD, JH, JS, QC, QD, QH, QS, KC, KD, KH, KS]"
    );
    assertTrue(
        "size",
        deck.getSize() == MAX_CARDS
    );
    assertTrue(
        "isEmpty",
        !deck.isEmpty()
    );
    Card p = deck.peek();
    assertTrue(
        "peek",
        p.rank == ACE && p.suit == 'C'
    );
}

void testCopy() {
    cout << "COPY TEST" << endl;
    Deck original;
    ostringstream d1, d2;

    original.draw();
    original.draw();
    original.shuffle();
    Deck duplicate(original);
    
    d1 << original; d2 << duplicate;
    assertTrue(
        "Copy Constructor",
        d1.str() == d2.str()
    );
    assertTrue(
        "size original",
        original.getSize() == 50
    );
    assertTrue(
        "size duplicate",
        duplicate.getSize() == 50
    );
    Card p1 = original.peek();
    Card p2 = duplicate.peek();
    assertTrue(
        "peek",
        p1.rank == p2.rank && p1.suit == p2.suit
    );
    p1 = original.draw();
    p2 = duplicate.draw();
    assertTrue(
        "draw",
        p1.rank == p2.rank && p1.suit == p2.suit
    );
    d1.clear();
    d2.clear();
    d1 << original; d2 << duplicate;
    assertTrue(
        "output",
        d1.str() == d2.str()
    );
}

void testAssignment() {
    cout << "ASSIGN TEST" << endl;
    Deck original;
    ostringstream d1, d2;

    original.draw();
    original.draw();
    original.shuffle();
    Deck duplicate = original;
    
    d1 << original; d2 << duplicate;
    assertTrue(
        "Copy Constructor",
        d1.str() == d2.str()
    );
    assertTrue(
        "size original",
        original.getSize() == 50
    );
    assertTrue(
        "size duplicate",
        duplicate.getSize() == 50
    );
    Card p1 = original.peek();
    Card p2 = duplicate.peek();
    assertTrue(
        "peek",
        p1.rank == p2.rank && p1.suit == p2.suit
    );
    p1 = original.draw();
    p2 = duplicate.draw();
    assertTrue(
        "draw",
        p1.rank == p2.rank && p1.suit == p2.suit
    );
    d1.clear();
    d2.clear();
    d1 << original; d2 << duplicate;
    assertTrue(
        "output",
        d1.str() == d2.str()
    );
}

void testEmpty() {
    cout << "EMPTY TEST" << endl;
    Deck deck;
    ostringstream d;

    for(int _ = 0; _ < MAX_CARDS; _++) {
        deck.draw();
    } 
    assertTrue(
        "isEmpty",
        deck.isEmpty()
    );
    assertTrue(
        "size empty",
        deck.getSize() == 0
    );
    deck.addTop({ACE, 'S'});
    d << deck;
    assertTrue(
        "output",
        d.str() == "[AS]"
    );
    assertTrue(
        "size one",
        deck.getSize() == 1
    );
}

void testSort() {
    cout << "SORT TEST" << endl;
    Deck deck;
    ostringstream d, r;

    deck.draw();
    deck.draw();
    d << deck;
    deck.shuffle();
    deck.order();
    r << deck;

    assertTrue(
        "size",
        deck.getSize() == 50
    );
    assertTrue(
        "ordering",
        d.str() == r.str()
    );
    assertTrue(
        "top",
        deck.peek().rank == 1
        && deck.peek().suit == 'H'
    );
}

void testSearch() {
    cout << "SEARCH TEST" << endl;
    Deck partialDeck;
    Deck fullDeck;

    partialDeck.shuffle();
    Card removed = partialDeck.draw();
    partialDeck.order();
    
    assertTrue(
        "not present",
        partialDeck.search(removed) == -1
    );
    assertTrue(
        "present",
        fullDeck.search({6, 'H'}) == 22
    );
}

int main() {
    srand(time(0));
    testBasicDeck();
    testCopy();
    testAssignment();
    testEmpty();
    testSort();
    testSearch();
    return 0;
}
