#include <iostream>
#include <ctime>
#include <random>
#include <vector>
using namespace std;

#ifndef DECK_H
#define DECK_H

#include "card.h"

const int MAX_CARDS = 52;

class Deck {
    private:
        vector<Card> cards;
        bool comesBefore(const Card&, const Card&) const;
        

    public:
        Deck();
        Deck(const Deck&);
        Deck& operator=(const Deck&);
        ~Deck();

        bool isEmpty() const;
        int getSize() const;
        Card peek() const;
        Card draw();
        void addTop(const Card&);
        void shuffle();
        void order();
        int search(const Card&) const;
        void print(ostream&) const;
};

ostream& operator<<(ostream&, const Deck&);

#endif
