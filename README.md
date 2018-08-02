# The Three Siblings Problem
## A solver in C++

The three siblings problem (a common math riddle), goes like this:
> I asked my neighbor how old his three daughters were
> He replied: "The product of their ages is 36 (or **N**, in general)"
> I thought for a while, but couldn't figure out their ages
> He gave another hint: "The sum of their ages is the number on my door"
> I thought for a long time, but still couldn't figure it out
> In the end, he gave one last hint: *My eldest daughter loves fishing*
> And in that moment, I got it
> How old are his daughters?

The following is a C++ solver that is able to find the solution to the problem, as well as being able to generate numbers **N** for which you can play this puzzle.

## Features
**Generating mode** - The program generates all possible N in a range that suit this problem.
[still in progress] **Solving mode** - The program takes in a number and a string denoting which daughter is specified in the riddle (you have to tell it whether it is the eldest or youngest daugher)

## Building
Run the following commands on your machine:
```
    git clone https://github.com/thomastay/threeSiblingProblem.git ~/threeSiblingProblem
    cd ~/threeSiblingProblem
    mkdir build bin
    cd build
    cmake ..
    make
```

## Usage
To use, go to the source directory and go into the folder named *bin*. The executable is called *threeSiblingProblem*
```
    ./threeSiblingProblem
```
This runs it in generation mode
[progress] working on solver mode now
