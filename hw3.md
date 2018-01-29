# Homework 3 Practicing Sorting Algorithms

## Overview

In homework 2, we have practiced how to store data in dynamically managed
data containers. This time we are going to practice how to sort elements
in a data container. As you may noticed from the last homework, dynamically
growing array offers the best overall performance, this time we will only
use dynamically growing array. But the same algorithm should be able to
apply to any type of indexed containers.

## Starting Point

Since howework 2, part of the starting code is updated. Now you have `Event`,
`Group`, and `Member` class to represent more types for data fromt the csv
tables. The `Database` class now can hold data from all three tables. Moreover,
there is a function called `LoadData` that can automatically load data from
the csv tables.

## P1. Simple Sorting (2 pt.)

The first task is to implement a simple sorting algorithm in `simple_sorter.h`.
You can use Selection Sort, Insertion Sort, or Bubble Sort.

All the sorters are decleared in `sorter.h` based on the `Sorter` class. The
sorter class has a `Sort` pure virtual function. The `Sort` function requires
the `List` to be sorted and a comparator to compare the values. The comparator
class is also defined in the `sorter.h`. An example of a concreate comparator
can be found in `main.cc`.

In this problem, we are interested in the highly-rated groups. Therefore, we
need to sort all the groups according to the rating. The main function is
provided in `main.cc`. So you do not need to modified the main function and the
comparator. But you can run `make clean && make` and run the compiled
executable to see if you get the correct result.

## P2. Merge Sort (3 pt.)

In this problem, you need to implement Merge Sort algorithm in `merge_sorter.h`.
You also need to modify the `main.cc` to switch the algorithm being used.

## P3. Quick Sort (3 pt.)

This problem is similar to P2, but you need to implement Quick sort algorithm
in `quick_sorter.h`.

## P4. Performance Analysis (2 pt.)

## P5. Extra Credit (2 pt.)

In the extra credit problem, please search online for the concept of
`Bridge Pattern`, `Iterator Pattern`. Explain the concept with your own words.
How are the patterns use in out homework code.
