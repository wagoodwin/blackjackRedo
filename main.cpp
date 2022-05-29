#include <algorithm> // for std::shuffle
#include <array>
#include <cassert>
#include <ctime>
#include <iostream>
#include <random>

class Card
{
public:
    enum Suit
    {
        club,
        diamond,
        heart,
        spade,

        max_suits
    };

    enum Rank
    {
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        rank_ace,

        max_ranks
    };

private:
    Rank m_rank{};
    Suit m_suit{};

public:
    Card() = default;

    Card(Rank rank, Suit suit)
        : m_rank{ rank }, m_suit{ suit }
    {
    }
    void print() const
    {
        switch (m_rank)
        {
        case rank_2:        std::cout << '2';   break;
        case rank_3:        std::cout << '3';   break;
        case rank_4:        std::cout << '4';   break;
        case rank_5:        std::cout << '5';   break;
        case rank_6:        std::cout << '6';   break;
        case rank_7:        std::cout << '7';   break;
        case rank_8:        std::cout << '8';   break;
        case rank_9:        std::cout << '9';   break;
        case rank_10:       std::cout << 'T';   break;
        case rank_jack:     std::cout << 'J';   break;
        case rank_queen:    std::cout << 'Q';   break;
        case rank_king:     std::cout << 'K';   break;
        case rank_ace:      std::cout << 'A';   break;
        default:
            std::cout << '?';
            break;
        }

        switch (m_suit)
        {
        case club:          std::cout << 'C';   break;
        case diamond:       std::cout << 'D';   break;
        case heart:         std::cout << 'H';   break;
        case spade:         std::cout << 'S';   break;
        default:
            std::cout << '?';
            break;
        }
    }

    int value() const
    {
        switch (m_rank)
        {
        case rank_2:        return 2;
        case rank_3:        return 3;
        case rank_4:        return 4;
        case rank_5:        return 5;
        case rank_6:        return 6;
        case rank_7:        return 7;
        case rank_8:        return 8;
        case rank_9:        return 9;
        case rank_10:       return 10;
        case rank_jack:     return 10;
        case rank_queen:    return 10;
        case rank_king:     return 10;
        case rank_ace:      return 11;
        default:
            assert(false && "should never happen");
            return 0;
        }
    }
};

class Deck
{
public:
    // type definitions. Just renaming types to make it easier to follow
    using array_type = std::array<Card, 52>;
    using index_type = array_type::size_type;

private:
    array_type m_deck{};

public:
    Deck()
    {
        index_type index{ 0 };

        for (int suit{ 0 }; suit < Card::max_suits; ++suit)
        {
            for (int rank{ 0 }; rank < Card::max_ranks; ++rank)
            {
                m_deck[index] = { static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit) };
                ++index;
            }
        }
    }
    void print() const
    {
        for (const auto& card : m_deck)
        {
            card.print(); // I'm assuming there's a print function in std::array?
            std::cout << ' ';
        }

        std::cout << '\n';
    }

    void shuffle()
    {
        static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

        std::shuffle(m_deck.begin(), m_deck.end(), mt);
    }
};

int main()
{
    Deck deck;
    deck.print();
    deck.shuffle();
    deck.print();

    return 0;
}