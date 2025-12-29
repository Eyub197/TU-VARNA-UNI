#include "contestantManager.h"
#include "constants.h"
#include "utils.h"
#include <ios>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int getContestantsToAdd(int numOfContestants) {
    int countOfContestantsToAdd;

    do {
        cout << "Enter how many contestants do you want to add: ";
        cin >> countOfContestantsToAdd;

        checkForSimpleNumber(countOfContestantsToAdd, "Enter how many contestants do you want to add: ");

        if (MAX_NUM_OF_CONTESTANTS < numOfContestants + countOfContestantsToAdd)
            cout << "The number of contestants must not exceed the maximum of " << MAX_NUM_OF_CONTESTANTS << " contestants" << endl;
    } while (MAX_NUM_OF_CONTESTANTS < countOfContestantsToAdd + numOfContestants);

    return countOfContestantsToAdd;
}

int getUniqNumber (const Contestant contestants[], int index) {
   int number;
   bool isDuplicateNumber;

    do {
        isDuplicateNumber = false;
        cout << "number: ";
        cin >> number;

        checkForSimpleNumber(number, "number: ");

        for (int j = 0; j < index; j++) {
            if (contestants[j].number == number) {
                cout << "This number is already taken. Please enter a unique number" << endl;
                isDuplicateNumber = true;
                break;
            }
        }
    } while (isDuplicateNumber);

    return number;
}

void setName(char name[], int nameSize, string optionalMessage = "") {
    bool valid = false;

    while (!valid) {
        optionalMessage.length() > 0 ? cout << optionalMessage : cout << "name: ";
        cin.getline(name, nameSize);

        if (cin.fail()) {
            cin.clear();
            clearBuffer();
            cout << "Name is too long enter a shorter nickname or make it maximum of 50 letters" << endl;
            continue;
        }

        valid = isValidName(name);
    }
}

void checkContestants(int numOfContestants) {
    if (numOfContestants == 0) {
        cout << "There are no contestants" << endl;
        return;
    }
}

int getValidAge() {
    int validAge;
        do {
            cout << "age (between 14 to 25): ";
        } while (!isValidInt(validAge, AGE_GROUP_ONE_MIN, AGE_GROUP_FOUR_MAX));

    return validAge;
}

void setGender(char gender[GENDER_LENGTH]) {
    int genderChoice;

    do {
        cout << "gender chose 1 for male and 2 for female: ";
    } while (!isValidInt(genderChoice, 1, 2));

    genderChoice == 1 ? strcpy(gender, "m") : strcpy(gender, "f");
}

float getCircumference(string typeOfCircumference, float min, float max) {
    float circumference;

    do {
        cout << typeOfCircumference << " circumference " << min << "cm"<< " - " << max << "cm :";
        cin >> circumference;

        if (!cin) {
            cout << "Invalid input please enter a number or floating point number" << endl;
            cin.clear();
            clearBuffer();
            continue;
        }

        if (circumference < min || circumference > max) {
            cout << "Invalid value. " << typeOfCircumference << " cirfumference must be between "  << min << "cm" << " and " << max << "cm" << endl;
        }

    } while (circumference < min || circumference > max);


    return circumference;
}

void printContestant(Contestant contestant) {
    cout << "Number: " << contestant.number << endl;
    cout << "Name: " << contestant.name << endl;
    cout << "Age: " << contestant.age  << endl;
    cout << "Gender: " << contestant.gender << endl;
    cout << "Hip circumference: " << contestant.hipCircumference << endl;
    cout << "Shoulder circumference: " << contestant.shoulderCircumference << endl;
    cout << "Neck circumference: " << contestant.neckCircumference << endl;
    cout << "Calf circumference: " << contestant.calfCircumference << endl;
    cout << endl;
}

void printContestants(const Contestant contestants[], int numOfContestants) {
    for (int contestant = 0; contestant < numOfContestants; contestant++) {
       printContestant(contestants[contestant]);
    }
}

int getYoungestAge (const Contestant contestants[], int numOfContestants) {
    int youngestAge = 1000;

    for (int contestant = 0; contestant < numOfContestants; contestant++) {
        if (contestants[contestant].age < youngestAge)
            youngestAge = contestants[contestant].age;
    }

    return youngestAge;
}

void copyArrayWithDiffrentIndexes(const Contestant originalArray[], Contestant arrayToCopy[], int indexOne, int indexTwo) {
    arrayToCopy[indexTwo].number = originalArray[indexOne].number;
    strcpy(arrayToCopy[indexTwo].name, originalArray[indexOne].name);
    arrayToCopy[indexTwo].age = originalArray[indexOne].age;
    strcpy(arrayToCopy[indexTwo].gender, originalArray[indexOne].gender);
    arrayToCopy[indexTwo].hipCircumference = originalArray[indexOne].hipCircumference;
    arrayToCopy[indexTwo].shoulderCircumference = originalArray[indexOne].shoulderCircumference;
    arrayToCopy[indexTwo].neckCircumference = originalArray[indexOne].neckCircumference;
    arrayToCopy[indexTwo].calfCircumference = originalArray[indexOne].calfCircumference;
}


void copyArray(const Contestant originalArray[], Contestant arrayToCopy[], int index) {
    copyArrayWithDiffrentIndexes(originalArray, arrayToCopy, index, index);
}

void sortByAgeAndName(Contestant arrayToSort[], int numOfContestants) {
    for (int i = 0; i < numOfContestants; i++) {
        for (int j = 0; j < numOfContestants - 1; j++) {
            if (arrayToSort[j].age > arrayToSort[j + 1].age) {
                Contestant temp = arrayToSort[j];
                arrayToSort[j] = arrayToSort[j + 1];
                arrayToSort[j + 1] = temp;
            }

            if (arrayToSort[j].age == arrayToSort[j + 1].age) {
                if (strcmp(arrayToSort[j].name, arrayToSort[j + 1].name) > 0) {
                    Contestant temp = arrayToSort[j];
                    arrayToSort[j] = arrayToSort[j + 1];
                    arrayToSort[j + 1] = temp;
                }
            }
        }
    }
}

float findScore(const Contestant contestant) {
    float denominator = contestant.shoulderCircumference + contestant.neckCircumference + contestant.calfCircumference;

    if (denominator == 0) {
        cout << "Something went wrong it. The circumferences can't be 0";
        return 0.0;
    }

    return contestant.hipCircumference / denominator;
}

ScoreCategories categorizeByScore(const Contestant contestants[], int numOfContestants) {
    ScoreCategories categories;

    for (int contestant = 0; contestant < numOfContestants; contestant++) {
        float score = findScore(contestants[contestant]);

        if (score >= WINNER_SCORE_MIN && score <=  WINNER_SCORE_MAX) {
            copyArrayWithDiffrentIndexes(contestants, categories.winners, contestant, categories.countOfWinners);
            categories.countOfWinners++;
        }
        else if (score > WINNER_SCORE_MAX) {
            copyArrayWithDiffrentIndexes(contestants, categories.highP, contestant, categories.countOfHighP);
            categories.countOfHighP++;
        }
        else  {
            copyArrayWithDiffrentIndexes(contestants, categories.lowP, contestant, categories.countOfLowP);
            categories.countOfLowP++;
        }
    }

    return categories;
}

void sortByScoreAscending(Contestant contestants[], int numOfContestants) {
    for (int i = 0; i < numOfContestants; i++) {
        for (int j = 0; j < numOfContestants - i - 1; j++) {
            if (findScore(contestants[j]) > findScore(contestants[j + 1])) {
                Contestant temp = contestants[j];
                contestants[j] = contestants[j + 1];
                contestants[j + 1] = temp;
            }
        }
    }
}

void sortByScoreDescending(Contestant contestants[], int numOfContestants) {
    for (int i = 0; i < numOfContestants; i++) {
        for (int j = 0; j < numOfContestants - i - 1; j++) {
            if (findScore(contestants[j]) < findScore(contestants[j + 1])) {
                Contestant temp = contestants[j];
                contestants[j] = contestants[j + 1];
                contestants[j + 1] = temp;
            }
        }
    }
}

AgeCategories groupByAge(const Contestant contestants[], int numOfContestants) {
    AgeCategories ageCategories;

    for (int contestant = 0; contestant < numOfContestants; contestant++) {
        if (contestants[contestant].age >= AGE_GROUP_ONE_MIN && contestants[contestant].age <= AGE_GROUP_ONE_MAX) {
            copyArrayWithDiffrentIndexes(contestants, ageCategories.contestantsGroupAge14to16, contestant, ageCategories.countOfContestantsGroupAge14to16);
            ageCategories.countOfContestantsGroupAge14to16++;
        } else if (contestants[contestant].age >= AGE_GROUP_TWO_MIN && contestants[contestant].age <= AGE_GROUP_TWO_MAX) {
            copyArrayWithDiffrentIndexes(contestants, ageCategories.contestantsGroupAge17to19, contestant, ageCategories.countOfContestantsGroupAge17to19);
            ageCategories.countOfContestantsGroupAge17to19++;
        }
        else if (contestants[contestant].age >= AGE_GROUP_THREE_MIN && contestants[contestant].age <= AGE_GROUP_THREE_MAX) {
            copyArrayWithDiffrentIndexes(contestants, ageCategories.contestantsGroupAge20to22, contestant, ageCategories. countOfContestantsGroupAge20to22);
            ageCategories.countOfContestantsGroupAge20to22++;
        }
        else if (contestants[contestant].age >= AGE_GROUP_FOUR_MIN && contestants[contestant].age <= AGE_GROUP_FOUR_MAX){
            copyArrayWithDiffrentIndexes(contestants, ageCategories.contestantsGroupAge23to25, contestant, ageCategories.countOfContestantsGroupAge23to25);
            ageCategories.countOfContestantsGroupAge23to25++;
        }
    }

    return ageCategories;
}

void addContestants(Contestant contestants[], int &numOfContestants) {
    int countOfContestansToAdd = getContestantsToAdd(numOfContestants);

    for (int contestant = numOfContestants; contestant < numOfContestants + countOfContestansToAdd; contestant++) {
        cout << "Entering information about contestants number " << contestant + 1 << endl;
        contestants[contestant].number = getUniqNumber(contestants, contestant);
        cin.ignore();
        setName(contestants[contestant].name, 50);
        contestants[contestant].age = getValidAge();
        setGender(contestants[contestant].gender);
        contestants[contestant].hipCircumference = getCircumference("Hip", HIP_MIN, HIP_MAX);
        contestants[contestant].shoulderCircumference = getCircumference("Shoulder", SHOULDER_MIN, SHOULDER_MAX);
        contestants[contestant].neckCircumference = getCircumference("Neck", NECK_MIN, NECK_MAX);
        contestants[contestant].calfCircumference = getCircumference("Calf", CALF_MIN, CALF_MAX);
        cout << endl;
    }

    numOfContestants += countOfContestansToAdd;
    cout << endl;
}

void printAllContestants(const Contestant contestants[], int numOfContestants) {
    checkContestants(numOfContestants);
    printContestants(contestants, numOfContestants);
}

void printYoungestContestants(const Contestant contestants[], int numOfContestestants) {
    int youngestAge = getYoungestAge(contestants, numOfContestestants);

    cout << "--- Results ---" << endl;
    for (int contestant = 0; contestant < numOfContestestants; contestant++) {
        if(contestants[contestant].age == youngestAge) {
            printContestant(contestants[contestant]);
        }
    }
}

void searchContestantByName(const Contestant contestants[], int numOfContestants) {
    char nameToSearchFor[50];
    bool foundContestant = false;

    cin.ignore();
    setName(nameToSearchFor, 50, "Enter the name that you are searching for: ");

    for (int contestant = 0; contestant < numOfContestants; contestant++) {
        if(strcmp(contestants[contestant].name, nameToSearchFor) == 0) {
            printContestant(contestants[contestant]);
            foundContestant = true;
        }
    }

    if (!foundContestant) {
        cout << "There is no contestant with this name" << endl;
    }

}

void sortByAge(Contestant contestants[], int numOfContestants) {
    checkContestants(numOfContestants);

    for (int i = 0; i < numOfContestants; i++) {
        for (int j = 0; j < numOfContestants - i - 1; j++) {
            if (contestants[j].age > contestants[j + 1].age) {
                Contestant temp = contestants[j];
                contestants[j] = contestants[j + 1];
                contestants[j + 1] = temp;
            }
        }
    }

    cout << "--- Sorted contestants succesfully ---" << endl;
}

void saveToFile(const Contestant contestants[], int numOfcontestants) {
    ofstream outFile(FILE_NAME, ios::out | ios::binary);

    if(!outFile) {
        cout << "Something went wrong while opening the file" << endl;
        return;
    }

    outFile.write((char*)&numOfcontestants, sizeof(int));

    outFile.write((char*)contestants, sizeof(Contestant) * numOfcontestants);

    if (outFile)
       cout << "--- Successfully saved " << numOfcontestants << " contestants to --- " << FILE_NAME << endl;
    else
        cout << "An error occured while writing to the file" << endl;

    outFile.close();
}

void loadFromFile(Contestant contestants[], int &numOfContestants) {
    ifstream inFile(FILE_NAME, ios::in | ios::binary);

    if (!inFile) {
        cout << "Something went wrong with the file" << endl;
        return;
    }

    int countFromFile = 0;

    inFile.read((char*)&countFromFile, sizeof(int));

    if (countFromFile < 0) {
        cout << "The file data is corrupt (contestant count is less then zero)" << endl;
        inFile.close();
        return;
    }

    if (countFromFile > MAX_NUM_OF_CONTESTANTS) {
        cout << "The file contains " << countFromFile << " contestants but the app can work with maximum of " << MAX_NUM_OF_CONTESTANTS << " contestants" << endl;
        inFile.close();
        return;
    }

    if (countFromFile == 0) {
        numOfContestants = 0;
        cout << "There are no contestants saved in the file" << endl;
        inFile.close();
        return;
    }

    inFile.read((char*)contestants, sizeof(Contestant) * countFromFile);

   if (inFile.gcount() != (sizeof(Contestant) * countFromFile)) {
       cout << "Corrupted date in file. Couldn't read all the contestants date" << endl;
   } else {
      numOfContestants = countFromFile;
      cout << "--- Succesfully loaded " << numOfContestants << " contestants from the file --- " << FILE_NAME << endl;
   }

    inFile.close();
}

void printContestantsSortedByAgeAndName(const Contestant contestants[], int numOfContestants) {
    Contestant tempContestants[MAX_NUM_OF_CONTESTANTS];

    for (int contestant = 0; contestant < numOfContestants; contestant++) {
        copyArray(contestants, tempContestants, contestant);
    }

    sortByAgeAndName(tempContestants, numOfContestants);

    cout << "--- Information about the sorted contestants ---" << endl;
    cout << endl;

    printContestants(tempContestants, numOfContestants);
}

void searchContestantByAgeAndGender(const Contestant contestants[], int numOfContestants) {
    char genderToSearchFor[2];
    bool foundContester = false;
    int ageToSearchFor = getValidAge();
    setGender(genderToSearchFor);

    cout << "--- Results ---" << endl;
    for (int contestant = 0; contestant < numOfContestants; contestant++) {
        if(contestants[contestant].age == ageToSearchFor && strcmp(contestants[contestant].gender, genderToSearchFor) == 0) {
            printContestant(contestants[contestant]);
            foundContester = true;
        }
    }

    if (!foundContester) {
        cout << "There is no contester with this name and age" << endl;
    }
}

void findWinnerForCategory(const Contestant contestants[], int numOfContestants) {
    ScoreCategories categories = categorizeByScore(contestants, numOfContestants);

    sortByScoreDescending(categories.winners, categories.countOfWinners);
    sortByScoreAscending(categories.highP, categories.countOfHighP);
    sortByScoreAscending(categories.lowP, categories.countOfLowP);

    if (categories.countOfWinners == 0) {
         cout << "There are no winners" << endl;
    } else printContestants(categories.winners, categories.countOfWinners);

    if (categories.countOfHighP == 0) {
        cout << "There were no contestants with high P" << endl;
    } else  printContestants(categories.highP, categories.countOfHighP);

    if (categories.countOfLowP == 0){
       cout << "There were no contestants with low P" << endl ;
    } else printContestants(categories.lowP, categories.countOfLowP);
}

void printContestantsGroupedByAge(const Contestant contestants[], int numOfContestants) {
    AgeCategories ageCategories = groupByAge(contestants, numOfContestants);

    cout << "--- Category 1 age " << AGE_GROUP_ONE_MIN << " - " << AGE_GROUP_ONE_MAX << " ---" << endl;
    if (ageCategories.countOfContestantsGroupAge14to16 == 0)
        cout <<  "There were no contestants between the age of 14 to 16" << endl ;
    else
        printContestants(ageCategories.contestantsGroupAge14to16, ageCategories.countOfContestantsGroupAge14to16);

    cout << endl;

    cout << "--- Category 2 age " << AGE_GROUP_TWO_MIN << " - " << AGE_GROUP_TWO_MAX << " ---" << endl;
    if(ageCategories.countOfContestantsGroupAge17to19 == 0)
        cout <<  "There were no contestants between the age of 17 to 19"  << endl;
    else printContestants(ageCategories.contestantsGroupAge17to19, ageCategories.countOfContestantsGroupAge17to19);

    cout << endl;


    cout << "--- Category 3 age " << AGE_GROUP_THREE_MIN<< " - " << AGE_GROUP_THREE_MAX << " ---" << endl;
    if(ageCategories.countOfContestantsGroupAge20to22 == 0)
        cout << "There were no contestants between the age of 20 to 22" << endl;
    else printContestants(ageCategories.contestantsGroupAge20to22, ageCategories.countOfContestantsGroupAge20to22);

    cout << endl;


    cout << "--- Category 4 age " << AGE_GROUP_FOUR_MIN << " - " << AGE_GROUP_FOUR_MAX << " ---" << endl;
    if(ageCategories.countOfContestantsGroupAge23to25 == 0) {
        cout << "There were no contestants between the age of 23 to 25" << endl;
    } else printContestants(ageCategories.contestantsGroupAge23to25, ageCategories.countOfContestantsGroupAge23to25);

    cout << endl;
}

void findAndPrintWinnersForAllCategories(const Contestant contestants[], int numOfContestants) {
    AgeCategories ageCategories = groupByAge(contestants, numOfContestants);
    cout << "--- Winners: age " << AGE_GROUP_ONE_MIN << " - " << AGE_GROUP_ONE_MAX << " ---"<< endl;
    findWinnerForCategory(ageCategories.contestantsGroupAge14to16, ageCategories.countOfContestantsGroupAge14to16);

    cout << "--- Winners: age " << AGE_GROUP_TWO_MIN << " - " << AGE_GROUP_TWO_MAX << " ---"<< endl;
    findWinnerForCategory(ageCategories.contestantsGroupAge17to19, ageCategories.countOfContestantsGroupAge17to19);


    cout << "--- Winners: age " << AGE_GROUP_THREE_MIN << " - " << AGE_GROUP_THREE_MAX << " ---"<< endl;
    findWinnerForCategory(ageCategories.contestantsGroupAge20to22, ageCategories.countOfContestantsGroupAge20to22);

    cout << "--- Winners: age " << AGE_GROUP_FOUR_MIN << " - " << AGE_GROUP_FOUR_MAX << " ---"<< endl;
    findWinnerForCategory(ageCategories.contestantsGroupAge23to25, ageCategories.countOfContestantsGroupAge23to25);
}
