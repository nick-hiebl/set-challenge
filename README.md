# C Challenge

The aim is essentially to implement the fastest possible string set algorithm.

A fairly straightforward but perfectly correct solution is included here in Set.c, but feel free to deviate from it. All that matters for now is that you implement the interface described in Set.h.

This includes:
- The definition of a `struct _SetRep` (for the #define)
- Implementation of the 3 functions `initSet`, `checkSet` and `freeSet`

## How to get started:

Simply clone the repo as is and you should just be able to run `run.sh` and it'll give you the basic output you should aim for.
```
$ ./run.sh 
Failures: 0

real	0m3.336s
user	0m3.336s
sys	0m0.000s
```
Failures is simply the number of `checkSet` calls that you return the wrong answer for. Try adding extra debug in `index.c` to troubleshoot any issues you have with that.

Ideally you should try to crank down on the time taken to significantly speed up the time taken.

## Amping up

If your code gets too fast for the `time` output to be meaningful, modify `index.c` to make more `checkSet` calls. Alternatively increase the size of the word sets.

I've been producing word sets for `words.txt` based on `tail` outputs of `allwords.txt`, ie:
```
$ tail -25000 allwords.txt > words.txt
```
You could modify this to be more (but ideally not more than half the number of lines in `allwords.txt`), just remember to update `NUM_WORDS` in `Set.h`.

## Be creative

The problem seems fairly simple, just implementing a `Set` ADT, but there are *countless* ways to approach it. Maybe try to come up with something unusual or creative even if it's not the fastest thing in the world.