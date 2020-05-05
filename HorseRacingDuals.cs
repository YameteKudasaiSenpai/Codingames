using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;

class Solution
{
    static void Main(string[] args)
    {
        int numberOfHorses = int.Parse(Console.ReadLine());
        List<int> values = new List<int>();

        for (int i = 0; i < numberOfHorses; i++)
        {   values.Add(int.Parse(Console.ReadLine()));  }

        List<int> orderedValues = values.OrderByDescending(i => i).ToList();
        int difference = 0;

        for (int i = 0; i < orderedValues.Count; i++)
        {
            if (i == 0)
            {   difference = orderedValues[i] - orderedValues[i + 1];   }
            else if (orderedValues[i-1] - orderedValues[i] < difference)
            {   difference = orderedValues[i - 1] - orderedValues[i];   }
        }
        
        Console.WriteLine(difference);
    }
}