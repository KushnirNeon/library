#include "magazine.h"

Magazine::Magazine() {}

Magazine::Magazine(std::string title, std::string author, int publicationYear, int id, std::string category, int numIssue, int frequency) : LibraryItem (title, author, publicationYear, id, category), numIssue_(numIssue), frequency_(frequency) {}

Magazine::~Magazine() {}

bool Magazine::isRecent()
{
    if (CURRENT_YEAR - publicationYear_ <= RECENTNESS)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Magazine::nextIssue()
{
    return publicationYear_ + frequency_;
}

bool operator < (const Magazine & magazine1, const Magazine & magazine2)
{
    return magazine1.title_ < magazine2.title_;
}

int Magazine::getNumIssue() const
{
    return numIssue_;
}

int Magazine::getFrequency() const
{
    return frequency_;
}

void Magazine::setNumIssue(int numIssue)
{
    numIssue_ = numIssue;
}

void Magazine::setFrequency(int frequency)
{
    frequency_ = frequency;
}
