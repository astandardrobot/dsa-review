#include <iostream>
#include <vector>
#include <algorithm>
/*
 * Heaps are essentially ordered in a tree like fashion, such that the lowest (min-heap) value 
 * or the highest (max-heap) value is the root.
 * Respectively, each node below the root will be lesser or greater than it, and their children will
 * abide by this rule, as well.
 *
 * Insertion: Top->bottom, left->right. If the item isn't in the right order, we can just swap values
 * up the tree until it's correctly located.
 *
 * Removing the min/max element: this is easy since this value is ALWAYS the root. However,
 * what happens to the rest of the nodes' priorities? 
 *
 * While learning how these methods are implemented is useful, for the sake of interviewing, just use
 * the containerized make_heap() method. Heaps can also be contained within the priority queue class, which
 * is essentially an adapter class
 *
 * Associated methods (in the containerized version):
 *      - make_heap() - O(3n)
 *      - push_heap() - O(log n)
 *      - sort_heap() - O(n*log n)
 *      - reverse() - O(n/2)
 * 
 * In the below example, a vector is being wrapped into a max-heap structure.
 */

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(std::vector<int> &hT, int i)
{
  int size = hT.size();
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < size && hT[l] > hT[largest])
    largest = l;
  if (r < size && hT[r] > hT[largest])
    largest = r;

  if (largest != i)
  {
    swap(&hT[i], &hT[largest]);
    heapify(hT, largest);
  }
}
void insert(std::vector<int> &hT, int newNum)
{
  int size = hT.size();
  if (size == 0)
  {
    hT.push_back(newNum);
  }
  else
  {
    hT.push_back(newNum);
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(hT, i);
    }
  }
}
void deleteNode(std::vector<int> &hT, int num)
{
  int size = hT.size();
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == hT[i])
      break;
  }
  swap(&hT[i], &hT[size - 1]);

  hT.pop_back();
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(hT, i);
  }
}
void printArray(std::vector<int> &hT)
{
  for (int i = 0; i < hT.size(); ++i)
    std::cout << hT[i] << " ";
  std::cout << "\n";
}

int main()
{
    std::vector<int> heapTree;

    insert(heapTree, 3);
    insert(heapTree, 4);
    insert(heapTree, 9);
    insert(heapTree, 5);
    insert(heapTree, 2);

    std::cout << "Max-Heap array: ";
    printArray(heapTree);

    deleteNode(heapTree, 4);

    std::cout << "After deleting an element: ";

    printArray(heapTree);
    std::vector<int> v {10,19,5,100,39,12};
    std::make_heap(v.begin(), v.end());
}
