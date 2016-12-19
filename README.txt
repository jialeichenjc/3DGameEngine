C++ Programming Final

Name: Joyce Chen (u1086833)
Email: superbrainchen@gmail.com


Testing:
in MonsterChaseGame/main:
MemoryAllocatorUnitTest.cpp
- modified from given HeapManager_UnitTest.cpp to test memory allocator and fixed size allocator
play.cpp 
- currently commented out 
- the monster chase game where game objects are allocated on the memory allocator heap


Key Files:
BitArray.h (.cpp)
- represents the BitArray class flagging availabilities of memory blocks

FixedSizeAllocator.h (.cpp)
- the fixed size allocator
- only allocates memory smaller than 8 bytes 

MemoryAllocator.h (.cpp)
- allocates memory for BitArray and FSA
- allocates larger memory not handled by FSA

GameObject.h (.cpp)
- uses two allocators (FSA and MemoryAllocator)

For Grading:
- Both BitArray and FSA are allocated on the heap of Memory Allocator
- FSA construction with number of blocks (bits) (FixedSizeAllocator.cpp / line 17)
- FSA free function (FixedSizeAllocator.cpp / line 64)
- BitArray.h lists all the implemented methods in BitArray
- FixedSizeAllocator added to overridden new and delete in GameObject.h (.cpp)
- GameObject has two booleans on_mem_allocator and on_fsa_allocator
to keep track of which allocator owns which memory
- Passed unit test MemoryAllocatorUnitTest.cpp (in all builds)
- Can comment out the unit test and de-comment play() in main
to see Monster Chase using memory allocator

- Use _BitScanForward in BitArray.cpp / line 92
- Warns about outstanding memory allocation FSA.cpp / line 82 
(commented out because I don't want to be warned)

