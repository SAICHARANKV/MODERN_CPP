#include <iostream>
#include <queue>
#include <vector>
// functor Object !!!! class in which overloaded() is available
struct Less_Equal_Comparator {
  bool operator()(int a, int b) {
    return a >= b; // Max heap
  }
};

// MIN HEAP: if a,b a will be before b in a min heap if a is greater than b

// MAX HEAP: If a,b a will be before b in a max heap if a is less than b

/*
pq{11}
add 25 a=25 b=11
*/

int main() {
  std::vector<int> data{11, 22, 13, 11, 22, 13, 22, 11, 22};

  std::priority_queue<int, std::vector<int>, Less_Equal_Comparator> pq(
      data.begin(), data.end());

  //   std::cout << pq.top() << "\n"; //   22  // 11
  //   pq.push(17);
  //   std::cout << pq.top() << "\n"; // 22    // 11
  //   std::cout << "After poping element highest priority is:" << pq.top() <<
  //   "\n";
  //   // After poping element highest priority is:22 // 11
  //   pq.pop();
  //   std::cout << pq.top() << "\n"; // 17 // 13
  // first output without comparator & second with comparator

  while (!pq.empty()) {
    std::cout << "Popping: " << pq.top() << "\n";
    pq.pop();
  }
}
/*
{11, 22, 13, 11, 22, 13, 22, 11, 22}
step 1:
    11 popped out
step 2:
  {22,13,22,13,22,11,22}
    11 popped out(it wont show others.we are considerate on lowest element as on
condition).
step 3: 11 step 4: 13 step 5: 13 step 6: 22 step 7: 22 step 8: 22
step 9: 22
(it wont matter on order)
*/

/*
  std::map:
      a) key value pairs for inserting data into container
      b) order of insertion and order of access are same i.e.
         elements can be retrieved in the same order
         in the same order as they were inserted
    {1, sai},{2,rohan},{3,surya}
        - Implemented using a tree-based structure (e.g: Red_Black Tree )
  std::unordered_map:
      a) key value pairs for inserting data into container.
      b) order of insertion and access may not be same.
              - Implemented using a HashTable structure (based on some
  implementing container ).
   std::set:
   Implemented by using concept of Red_Black
  Tree In a set,a key can only appear once(giving the illusion of uniqueness of
  entries)
*/

/*
Make a Priority queue where objects of a class automobile are stored via
priority based on"Max price first!"

The attributes of the class are as follows:
_id :string,
_price :float,
_type : either PRIVATE or COMMERICAL

*/