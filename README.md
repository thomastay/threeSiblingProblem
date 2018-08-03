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

**Solving mode** - The program takes in a number and a string denoting which daughter is specified in the riddle (you have to tell it whether it is the eldest or youngest daugher)

## Building

### Dependencies
You will need a compiler with C++11 support (clang-3.3+, g++-4.8+), CMake 3.0+, and git.

To check, run the following commands on your terminal:
```
g++ --version
cmake --version
git --version
```

### Steps
Run the following commands on your machine:
```
git clone https://github.com/thomastay/threeSiblingSolver.git
cd threeSiblingSolver
mkdir build bin
cd build
cmake ..
make
```

## Usage
To use, go to the source directory and go into the folder named *bin*. The executable is called *threeSiblingSolver*

For full help and usage instructions, type
```
./threeSiblingSolver --help
```

### Solving mode
```
./threeSiblingSolver --solve [NUMBER] --type [ANSWER-TYPE]
```

For example, if the product of the neighbor's daughter's ages is 36 and he specified his eldest daughter, you would type in

```
./threeSiblingSolver --solve 36 --type eldest
```

This would give the output
```
For the problem of siblings whose ages multiply to 36,
and the neighbor specified his eldest daughter
Solving ...

Solved!
The ages of the siblings are: 2, 2, 9
```

Here's a bigger problem:
```
./threeSiblingSolver --solve 9072 --type youngest

For the problem of siblings whose ages multiply to 9072,
and the neighbor specified his youngest daughter
Solving ...

Solved!
The ages of the siblings are: 16, 21, 27
```

### Generation mode
```
./threeSiblingSolver --generate [RANGE]
```

This generates all possible numbers where the daughters ages are in the range [1,RANGE)

For example, if you want to see all cases where the daughters are preteens (12 and below)


```
./threeSiblingSolver --generate 13
```

would output

```
   36:  1  6  6 &  2  2  9
   40:  1  5  8 &  2  2 10
   72:  2  6  6 &  3  3  8
   90:  2  5  9 &  3  3 10
  144:  3  6  8 &  4  4  9
  360:  5  8  9 &  6  6 10
```
