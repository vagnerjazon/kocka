#include <iostream>
#include <fstream>
#include "Space.h"
#include "Part.h"

Part part1, part2, part3, part4, part5, part6;
Part allParts_original[6];

void initParts()
{
    part1.setVoxel(0, 0, 0, 1);
    part1.setVoxel(0, 1, 0, 1);
    part1.setVoxel(0, 2, 0, 1);
    part1.setVoxel(0, 3, 0, 1);
    part1.setVoxel(1, 0, 0, 1);
    part1.setVoxel(1, 3, 0, 1);
    part1.setVoxel(1, 3, 1, 1);

    part2.setVoxel(0, 0, 0, 1);
    part2.setVoxel(0, 1, 0, 1);
    part2.setVoxel(0, 2, 0, 1);
    part2.setVoxel(0, 3, 0, 1);
    part2.setVoxel(1, 0, 0, 1);
    part2.setVoxel(1, 3, 0, 1);
    part2.setVoxel(0, 3, 1, 1);
    part2.setVoxel(1, 0, 1, 1);

    part3.setVoxel(0, 0, 0, 1);
    part3.setVoxel(0, 1, 0, 1);
    part3.setVoxel(0, 2, 0, 1);
    part3.setVoxel(0, 3, 0, 1);
    part3.setVoxel(1, 3, 0, 1);
    part3.setVoxel(1, 0, 0, 1);
    part3.setVoxel(2, 0, 0, 1);
    part3.setVoxel(3, 0, 0, 1);
    part3.setVoxel(3, 1, 0, 1);
    part3.setVoxel(3, 2, 0, 1);
    part3.setVoxel(0, 0, 1, 1);
    part3.setVoxel(1, 3, 1, 1);
    part3.setVoxel(3, 0, 1, 1);
    part3.setVoxel(3, 1, 1, 1);

    part4.setVoxel(0, 0, 0, 1);
    part4.setVoxel(0, 1, 0, 1);
    part4.setVoxel(0, 2, 0, 1);
    part4.setVoxel(0, 3, 0, 1);
    part4.setVoxel(1, 3, 0, 1);
    part4.setVoxel(1, 0, 0, 1);
    part4.setVoxel(2, 0, 0, 1);
    part4.setVoxel(3, 0, 0, 1);
    part4.setVoxel(3, 1, 0, 1);
    part4.setVoxel(3, 2, 0, 1);
    part4.setVoxel(0, 3, 1, 1);
    part4.setVoxel(1, 0, 1, 1);

    part5.setVoxel(3, 0, 0, 1);
    part5.setVoxel(3, 1, 0, 1);
    part5.setVoxel(3, 2, 0, 1);
    part5.setVoxel(3, 3, 0, 1);
    part5.setVoxel(2, 1, 0, 1);
    part5.setVoxel(2, 2, 0, 1);
    part5.setVoxel(1, 2, 0, 1);
    part5.setVoxel(0, 1, 0, 1);
    part5.setVoxel(0, 2, 0, 1);
    part5.setVoxel(0, 3, 0, 1);
    part5.setVoxel(0, 1, 1, 1);
    part5.setVoxel(0, 2, 1, 1);

    part6.setVoxel(0, 0, 0, 1);
    part6.setVoxel(0, 1, 0, 1);
    part6.setVoxel(0, 2, 0, 1);
    part6.setVoxel(0, 3, 0, 1);
    part6.setVoxel(1, 1, 0, 1);
    part6.setVoxel(1, 3, 0, 1);
    part6.setVoxel(0, 2, 1, 1);
    part6.setVoxel(1, 1, 1, 1);
    part6.setVoxel(0, 0, 1, 1);
    part6.setVoxel(0, 0, 2, 1);
    part6.setVoxel(0, 0, 3, 1);

    allParts_original[0] = part1;
    allParts_original[1] = part2;
    allParts_original[2] = part3;
    allParts_original[3] = part4;
    allParts_original[4] = part5;
    allParts_original[5] = part6;
}

Part allParts[6];

void resetAllParts()
{
    allParts[0] = allParts_original[0];
    allParts[1] = allParts_original[1];
    allParts[2] = allParts_original[2];
    allParts[3] = allParts_original[3];
    allParts[4] = allParts_original[4];
    allParts[5] = allParts_original[5];
}

int currentOrientation[6] = { 0, 0, 0, 0, 0, 0 };
int currentTranslationX[6] = { 0, 0, 0, 0, 0, 0 };
int currentTranslationY[6] = { 0, 0, 0, 0, 0, 0 };
int currentTranslationZ[6] = { 0, 0, 0, 0, 0, 0 };

unsigned long long iterationCounter = 0;

void incrementConfiguration()
{
    iterationCounter++;

    for (int i = 0; i < 6; i++)
    {
        if (allParts[i].isTranslatableAlongZ(currentTranslationZ[i] + 1))
        {
            currentTranslationZ[i]++;
            break;
        }
        if (allParts[i].isTranslatableAlongY(currentTranslationY[i] + 1))
        {
            currentTranslationY[i]++;
            currentTranslationZ[i] = 0;
            break;
        }
        if (allParts[i].isTranslatableAlongX(currentTranslationX[i] + 1))
        {
            currentTranslationX[i]++;
            currentTranslationY[i] = 0;
            currentTranslationZ[i] = 0;
            break;
        }

        currentTranslationX[i] = 0;
        currentTranslationY[i] = 0;
        currentTranslationZ[i] = 0;

        if (currentOrientation[i] < (24-1))
        {
            currentOrientation[i]++;
            break;
        }
        else
        {
            currentOrientation[i] = 0;
        }
    }
}

bool isThisTheSolution()
{
    Space space;
    for (int i = 0; i < 6; i++)
    {
        allParts[i].translateAlongY(currentTranslationY[i]);
        allParts[i].translateAlongX(currentTranslationX[i]);
        allParts[i].translateAlongZ(currentTranslationZ[i]);
        allParts[i].applyRotation(currentOrientation[i]);
        
        space = space + allParts[i];
        if (space.ContainsOverlap())
        {
            resetAllParts();
            return false;
        }
    }
    return true;
}


int main()
{
    Space space;
    initParts();
    resetAllParts();

    std::ofstream statusFile;
    statusFile.open("status.txt");

    while (isThisTheSolution() == false)
    {
        if ((iterationCounter % 1000000000) == 0)
            statusFile << iterationCounter << std::endl;

        incrementConfiguration();
    }

    std::ofstream resultFile;
    resultFile.open("result.txt");

    for (int i = 0; i < 6; i++)
    {
        resultFile << "part: " << i << std::endl;
        resultFile << "X translation: " << currentTranslationX[i] << std::endl;
        resultFile << "Y translation: " << currentTranslationY[i] << std::endl;
        resultFile << "Z translation: " << currentTranslationZ[i] << std::endl;
        resultFile << "orientation: " << currentOrientation[i] << std::endl << std::endl;
    }

    resultFile << "iterationCounter: " << iterationCounter << std::endl;

    resultFile.close();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
