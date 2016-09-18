//
// Created by Raghava Viswa Mani Kiran Peddinti on 9/14/16.
//

#include "QuoraChallenges.h"
#include "iostream"
using namespace std;

void QuoraChallenges::UpVotesTrend(int * values, int length, int window_size, int* trends) {
    for (int start=0; start < (length-window_size+1); start++) {
        trends[start] = 0;
        trends[start] += NonDecreasingRange(values, start, window_size);
        trends[start] -= NonIncreasingRange(values, start, window_size);
    }
    return;
}

int QuoraChallenges::NonDecreasingRange(int * values, int start, int length) {
    int count = 0;
    for (int i=0; i< length-1; i++) {
        int j = i+1+start;
        while ((j < (start+length)) && (values[j] >= values[j-1])) {
            count++;
            j++;
        }
    }
    return count;
}

int QuoraChallenges::NonIncreasingRange(int *values, int start, int length) {
    int count = 0;
    for (int i=0; i< length-1; i++) {
        int j = i+1+start;
        while ((j < (start+length)) && (values[j] <= values[j-1])) {
            count++;
            j++;
        }
    }
    return count;
}

int QuoraChallenges::BestRelatedQuestion(int length, int* reading_times, vector<pair<int, int>> relations) {
    // create required DS
    Question** questions = CreateRelatedQuestions(length, reading_times, relations);
    float cost = INT_MAX;
    int position = 0;
    for (int i=0; i<length; i++) {
        float new_cost = ComputeCost(questions[i], nullptr);
        if (new_cost < cost) {
            cost = new_cost;
            position = i;
        }
    }
    return position;
}

float QuoraChallenges::ComputeCost(Question* current_question, Question* previous_question) {
    float cost = 0;
    int count = 0;
    auto related_questions = current_question->related_questions;
    for (int i =0; i < related_questions.size(); i++) {
        if (related_questions[i] != previous_question) {
            if (current_question->related_questions_cost[i] == -1) {
                // compute and add
                current_question->related_questions_cost[i] = ComputeCost(related_questions[i], current_question);
            }
            cost += current_question->related_questions_cost[i];
            count += 1;
        }
    }
    // getting expected cost;
    if (count > 0)
        cost /= count;
    // adding cost to read the current question
    cost += current_question->reading_time;
    return cost;
}
QuoraChallenges::Question** QuoraChallenges::CreateRelatedQuestions(int length, int* reading_times,
                                                                    vector<pair<int, int>> relations) {
    // initializing question objects
    Question** questions = new Question*[length];
    for (int i=0; i<length; i++) {
        questions[i] = new Question();
        questions[i]->reading_time = reading_times[i];
    }
    // initializing relations
    for (auto relation: relations) {
        // creating two way relations
        questions[relation.first - 1]->related_questions.push_back(questions[relation.second - 1]);
        questions[relation.first - 1]->related_questions_cost.push_back(-1);

        questions[relation.second - 1]->related_questions.push_back(questions[relation.first - 1]);
        questions[relation.second - 1]->related_questions_cost.push_back(-1);
    }
    return questions;
}
