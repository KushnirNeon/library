#pragma once

#include <string>
#include <vector>

#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "libraryItem.h"

class Magazine : public LibraryItem
{
    public:
        Magazine();
        Magazine (std::string title, std::string author, int publicationYear, int id, std::string category, int numIssue, int frequency);
        ~Magazine();
        bool isRecent(); // checks if magazine was published within last 5 years
        int nextIssue(); // returns year of next issue
        friend bool operator < (const Magazine & magazine1, const Magazine & magazine2);

        int getNumIssue() const;
        int getFrequency() const;

        void setNumIssue(int numIssue);
        void setFrequency(int frequency);

    private:
        int numIssue_;
        int frequency_; // in years
        static const int CURRENT_YEAR = 2023;
        static const int RECENTNESS = 5;
};

#endif
