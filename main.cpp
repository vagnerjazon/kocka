#include <iostream>
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
    part5.setVoxel(1, 3, 0, 1);
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

void resetPart(int index)
{
    allParts[index] = allParts_original[index];
}

int currentOrientation[6] = { 0, 0, 0, 0, 0, 0 };
int currentTranslationX[6] = { 0, 0, 0, 0, 0, 0 };
int currentTranslationY[6] = { 0, 0, 0, 0, 0, 0 };

int main()
{
    initParts();

    Space space;

    resetAllParts();
    
    int iterationCounter = 0;

    for (int i = 0; i < 6; i++)
    {
    ToTranslate:

        std::cout << '\r' << "iterationCounter: " << iterationCounter << " i=" << i;

        allParts[i].translateAlongY(currentTranslationY[i]);
        allParts[i].translateAlongX(currentTranslationX[i]);

    //NextOrientation:
        iterationCounter++;
        if (currentOrientation[i] < 24)
        {
            allParts[i].applyRotation(currentOrientation[i]);
            currentOrientation[i]++;

            Space temp = space + allParts[i];
            if (temp.ContainsOverlap() == false)
                space = temp;
            else
            {
                resetPart(i);
                if (allParts[i].isTranslatableAlongY(currentTranslationY[i] + 1))
                {
                    currentTranslationY[i]++;
                    currentOrientation[i]--;
                    goto ToTranslate;
                }
                if (allParts[i].isTranslatableAlongX(currentTranslationX[i] + 1))
                {
                    currentTranslationX[i]++;
                    currentTranslationY[i] = 0; //reset Y translation
                    currentOrientation[i]--;
                    goto ToTranslate;
                }
                currentTranslationX[i] = 0;
                currentTranslationY[i] = 0;
                goto ToTranslate;
            }
        }
        else //if this part does not fit in any possible place, try to translate it (because of the first part), or else go back to the previous one
        {
            resetPart(i); //resetting this part
            currentOrientation[i] = 0;
            if (allParts[i].isTranslatableAlongY(currentTranslationY[i] + 1))
            {
                currentTranslationY[i]++;
                goto ToTranslate;
            }
            if (allParts[i].isTranslatableAlongX(currentTranslationX[i] + 1))
            {
                currentTranslationX[i]++;
                currentTranslationY[i] = 0; //reset Y translation
                goto ToTranslate;
            }

            //stepping back to the previous part
            currentTranslationX[i] = 0;
            currentTranslationY[i] = 0;
            i--;
            resetPart(i); //also resetting the previous part
            space = Space(); //reset space to conatin only the parts before the previous one
            for (int ii = 0; ii < i; ii++)
                space = space + allParts[ii];

            if (i < 0)
                throw std::invalid_argument("No solution");
            goto ToTranslate;
        }
    }
 
    for (int i = 0; i < 6; i++)
    {
        std::cout << "part: " << i << std::endl;
        std::cout << "orientation: " << (currentOrientation[i] - 1) << std::endl;
        std::cout << "X translation: " << currentTranslationX[i] << std::endl;
        std::cout << "Y translation: " << currentTranslationY[i] << std::endl << std::endl;
        std::cout << "iterationCounter: " << iterationCounter << std::endl;
    }

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
