using System.Data;

namespace BinarySearch;

public class Program
{
    public static int SearchUnique(int[][] index, int indexLength, int search_value)
    {
        int left = 0;
        int right = indexLength - 1;

        while (left <= right)
        {
            int center = (left + right) / 2;
            int value = index[center][1];

            if (value == search_value)
            {
                return index[center][0];
            }
            else if (value < search_value)
            {
                left = center + 1;
            }
            else
            {
                right = center - 1;
            }
        }

        return int.MaxValue;
    }

    public static void test()
    {
        int rows = 5_000_000; // 5.000.000
        int[][] index = new int[rows][];

        Random random = new Random();

        for (int i = 0; i < rows; i++)
        {
            index[i] = new int[2];
            index[i][0] = random.Next(0, 999999);
            index[i][1] = i * 2;
        }

        int picedIndexesCount = 100_000; // 100.000
        int[][] picedIndexes = new int[picedIndexesCount][];

        for (int i = 0; i < picedIndexesCount; i++)
        {
            int randomIndex = random.Next(0, rows);
            picedIndexes[i] = new int[2];
            picedIndexes[i][0] = index[randomIndex][0];
            picedIndexes[i][1] = index[randomIndex][1];
        }

        Console.WriteLine($"searching for {picedIndexesCount} indexes in an index of {rows} indexes");
        int dummySum = 0;

        DateTime start = DateTime.Now;
        for (int i = 0; i < picedIndexesCount; i++)
        {
            int ptr = SearchUnique(index, rows, picedIndexes[i][1]);
            if (ptr == picedIndexes[i][0])
            {
                dummySum++;
            }
        }
        DateTime end = DateTime.Now;

        Console.WriteLine($"DummySum: {dummySum}");
        Console.WriteLine($"Took: {(end - start).TotalMilliseconds} ms");
        Console.WriteLine($"Average per search: {(end - start).TotalMilliseconds / picedIndexesCount}");
    }

    public static void Main(string[] args)
    {
        while (true)
        {
            Console.ReadLine();
            test();
        }
    }
}