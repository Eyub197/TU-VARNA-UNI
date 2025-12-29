#pragma once

const int MAX_NUM_OF_CONTESTANTS = 30;
const char FILE_NAME[30] = "contestants.dat";

const int NAME_MIN = 2;
const int NAME_MAX = 50;

const int GENDER_LENGTH = 2;

const float HIP_MIN = 30.0;
const float HIP_MAX = 200.0;
const float SHOULDER_MIN = 30.0;
const float SHOULDER_MAX = 200.0;
const float NECK_MIN = 20.0;
const float NECK_MAX = 60.0;
const float CALF_MIN = 20.0;
const float CALF_MAX = 60.0;

const int AGE_GROUP_ONE_MIN = 14;
const int AGE_GROUP_ONE_MAX = 16;
const int AGE_GROUP_TWO_MIN = 17;
const int AGE_GROUP_TWO_MAX = 19;
const int AGE_GROUP_THREE_MIN = 20;
const int AGE_GROUP_THREE_MAX = 22;
const int AGE_GROUP_FOUR_MIN = 23;
const int AGE_GROUP_FOUR_MAX = 25;

const float WINNER_SCORE_MIN = 0.54;
const float WINNER_SCORE_MAX = 0.62;


struct Contestant {
    int number;
    char name[NAME_MAX];
    int age;
    char gender[GENDER_LENGTH];
    float hipCircumference;
    float shoulderCircumference;
    float neckCircumference;
    float calfCircumference;
};

struct ScoreCategories {
    Contestant winners[MAX_NUM_OF_CONTESTANTS];
    int countOfWinners = 0;
    Contestant highP[MAX_NUM_OF_CONTESTANTS];
    int countOfHighP = 0;
    Contestant lowP[MAX_NUM_OF_CONTESTANTS];
    int countOfLowP = 0;
};

struct AgeCategories {
    Contestant contestantsGroupAge14to16[MAX_NUM_OF_CONTESTANTS];
    int countOfContestantsGroupAge14to16 = 0;
    Contestant contestantsGroupAge17to19[MAX_NUM_OF_CONTESTANTS];
    int countOfContestantsGroupAge17to19 = 0;
    Contestant contestantsGroupAge20to22[MAX_NUM_OF_CONTESTANTS];
    int countOfContestantsGroupAge20to22 = 0;
    Contestant contestantsGroupAge23to25[MAX_NUM_OF_CONTESTANTS];
    int countOfContestantsGroupAge23to25 = 0;
};
