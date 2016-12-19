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

Grading Helper:
- Both BitArray and FSA are allocated on the heap of Memory Allocator
- FSA construction with number of blocks (bits) (FixedSizeAllocator.cpp / line 17)
- FSA free function