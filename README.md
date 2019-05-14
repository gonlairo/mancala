# mancala

In the makefile we create two directories(obj && bin) and every time we do "make clean" we delete them. We used the master branch for Mancala.cpp and another branch for the Makefile.  

Fixes in Mancala.cpp:
- Constructor with args: account for the possible corner cases e.g invalid inputs.
- PlayerPitStoneCount(): corner cases.
- GameOver(): typo in the for loop.
- PlayerTurn(): corner cases.
- PlayerScore(): wrong index. we added -1.
- Move(): a lot of bugs.

References: office hours.
