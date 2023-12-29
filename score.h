//
// Created by Octa on 29.12.2023.
//

#ifndef OOP_SCORE_H
#define OOP_SCORE_H

#endif //OOP_SCORE_H

#pragma once

class Score {
public:
    virtual ~Score() = default;
    virtual void increaseScore() = 0;
    virtual int getScore() const = 0;

protected:
    int score;

};



class SimpleScore : public Score {
public:
    void increaseScore() override;
    int getScore() const override;
};

class DoubleScore : public Score {
public:
    void increaseScore() override;
    int getScore() const override;
    void handleThresholds();
};

class TripleScore : public Score {
public:
    void increaseScore() override;
    int getScore() const override;
    void handleThresholds();

};

