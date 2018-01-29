# Homework 3 Practicing Sorting Algorithms

## Overview

In homework 2, we have practiced how to store data in dynamically managed
data containers. This time we are going to practice how to sort elements
in a data container. As you may noticed from the last homework, dynamically
growing array offers the best overall performance, this time we will only
use dynamically growing array. But the same algorithm should be able to
apply to any type of indexed containers.

## Starting Point

As usual, we start this homework by desinging some classes. The first class is
an interface class called `Sorter`. The main public interface is `Sort`
function.