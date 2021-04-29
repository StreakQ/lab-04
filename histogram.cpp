#include "histogram.h"

void find_minmax(const vector<double>& numbers, double& min, double& max)
{
    min = numbers[0];
    max = numbers[0];
if(numbers.size() != 0)
    {
        for (size_t i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] < min)
            {
                min = numbers[i];
            }
            if (numbers[i] > max)
            {
                max = numbers[i];
            }
        }
    }
    return;
}
