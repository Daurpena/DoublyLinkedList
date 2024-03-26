#include <iostream>
#include "DoublyLinked.hpp"
#include <boost/assert.hpp>

DoublyLinked<int> linked; 

namespace UnitTest
{

     void AddandMovement_test()
     {
          std::cout << "\n[Add and Movement Test]\n" ;
          linked.InsertHead(10); 
          linked.InsertTail(100);
          linked.Insert(1, 50); 
          
          //Expected output 10 -> 50 -> 100 -> NULL
          linked.PrintList();
          
          //Ensure list traversal operates in both directions
          assert(linked.Head->Data == 10);
          assert(linked.Head->Next->Data == 50);
          assert(linked.Head->Next->Next->Data == 100);
          assert(linked.Head->Next->Next->Next == NULL);
          assert(linked.Tail->Data == 100);
          assert(linked.Tail->Previous->Data == 50);
          assert(linked.Tail->Previous->Previous->Data == 10);
          std::cout << "\n\n" ;
     }

     void Remove_test()
     {
          //Starting list 10 -> 50 -> 100 -> NULL
          std::cout << "\n[Remove Test]\n" ;

          linked.RemoveHead();                         //10 has been removed
          assert(linked.Head->Data == 50);             //50 is the new head 
          linked.RemoveTail();                         //100 has been removed
          assert(linked.Tail->Data == 50);             //Since previous tail is removed, current Tail = Head  
          linked.Remove(0);                            //List should be empty
          
          //Expected output == NULL (empty list)
          linked.PrintList();
     }

}



int main()
{

     UnitTest::AddandMovement_test();
     UnitTest::Remove_test();



     return 0;
}
