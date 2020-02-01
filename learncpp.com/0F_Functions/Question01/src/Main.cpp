/*
 * Chapter F :: Question 3
 *
 * binary search
 *
 * KoaLaYT  17:42  01/02/2020
 *
 */

#include <iostream>

/*
// iterative version
int binary_search(const int *array, int target, int min, int max) {
  while (min < max) {
    int mid = min + (max - min) / 2;
    if (array[mid] == target) {
      return mid;
    }
    if (array[mid] > target) {
      max = mid - 1;
    } else {
      min = mid + 1;
    }
  }

  // min equals to max
  if (array[min] == target)
    return min;
  else
    return -1;
}
*/

// recursive version
int binary_search(const int *array, int target, int min, int max) {
  if (min > max)
    return -1;
  if (min == max) {
    if (array[min] == target)
      return min;
    else
      return -1;
  }

  int mid = min + (max - min) / 2;

  if (array[mid] == target)
    return mid;
  if (array[mid] > target)
    return binary_search(array, target, min, mid - 1);
  else
    return binary_search(array, target, mid + 1, max);
}

int main() {
  constexpr int array[]{3,  6,  8,  12, 14, 17, 20, 21,
                        26, 32, 36, 37, 42, 44, 48};

  // We're going to test a bunch of values to see if they produce the expected
  // results
  constexpr int numTestValues{9};
  // Here are the test values
  constexpr int testValues[numTestValues]{0, 3, 12, 13, 22, 26, 43, 44, 49};
  // And here are the expected results for each value
  int expectedValues[numTestValues]{-1, 0, 3, -1, -1, 8, -1, 13, -1};

  // Loop through all of the test values
  for (int count{0}; count < numTestValues; ++count) {
    // See if our test value is in the array
    int index{binary_search(array, testValues[count], 0, 14)};
    // If it matches our expected value, then great!
    if (index == expectedValues[count])
      std::cout << "test value " << testValues[count] << " passed!\n";
    else // otherwise, our binarySearch() function must be broken
      std::cout << "test value " << testValues[count]
                << " failed.  There's something wrong with your code!\n";
  }

  return 0;
}

