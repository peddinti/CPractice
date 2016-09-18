//
// Created by Raghava Viswa Mani Kiran Peddinti on 9/14/16.
//

#ifndef CPRACTICE_QUORACHALLENGES_H
#define CPRACTICE_QUORACHALLENGES_H
#include <vector>
using namespace std;
// https://www.quora.com/challenges
class QuoraChallenges {
public:
    static void UpVotesTrend(int[], int, int, int*);
    static int BestRelatedQuestion(int, int*, vector<pair<int, int>>);
//private:
    struct Question {
        int reading_time;
        vector<Question*> related_questions;
        vector<float> related_questions_cost;
    };
    static int NonDecreasingRange(int*, int, int);
    static int NonIncreasingRange(int*, int, int);
    static Question** CreateRelatedQuestions(int, int*, vector<pair<int, int>>);
    static float ComputeCost(Question*, Question*);
};


#endif //CPRACTICE_QUORACHALLENGES_H
