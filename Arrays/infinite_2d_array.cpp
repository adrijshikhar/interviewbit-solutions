#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int coverPoints(vector<int> &A, vector<int> &B)
{
  int positionX = *A.begin(), positionY = *B.begin();

  int steps = 0;
  int i = 1;
  int diffX, diffY, minDiff;
  while (i < A.size())
  {

    diffX = abs(positionX - *(A.begin() + i));
    diffY = abs(positionY - *(B.begin() + i));

    minDiff = min(diffX, diffY);
    // cout << positionX << " " << positionY << " " << minDiff << endl;
    // return 0;
    if (minDiff == 0)
    {
      if (diffY == 0)
      {
        if ((positionX) < *(A.begin() + i))
        {
          positionX += diffX;
        }
        else
        {
          positionX -= diffX;
        }
        steps += diffX;
      }
      if (diffX == 0)
      {
        if ((positionY) < *(B.begin() + i))
        {
          positionY += diffY;
        }
        else
        {
          positionY -= diffY;
        }
        steps += diffY;
      }
    }
    else
    {
      if ((positionY) < *(B.begin() + i))
      {
        positionY += minDiff;
      }
      else
      {
        positionY -= minDiff;
      }
      if ((positionX) < *(A.begin() + i))
      {
        positionX += minDiff;
      }
      else
      {
        positionX -= minDiff;
      }
      steps += minDiff;
    }

    if (positionX == *(A.begin() + i) && positionY == *(B.begin() + i))
    {
      i++;
    }
  }
  return steps;
}

int main()
{
  vector<int> v1{4, 8, -7, -5, -13, 9, -7, 8}, v2{4, -15, -10, -3, -13, 12, 8, -8};
  int minSteps = coverPoints(v1, v2);
  cout << minSteps;
  return 0;
}
