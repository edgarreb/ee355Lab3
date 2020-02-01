# EE355 Lab3 
### ***Please see the [PDF file](../master/EE355_Lab3.pdf) for the more detailed problem descriptions. Remember to check back on Blackboard periodically for any updates on the problem description.***
**Assigned: Wednesday Jan. 23**
**Due: Wednesday Jan. 30 at 11:59pm**


**What You Will Practice**

In this lab, you are going to practice OOP and multidimensional array manipulations **in C++**.

**Problem Description -  &quot;3D Burnt Pancake Problem&quot;**

A chef for a catering event is sloppy, and when he prepares a bunch of pancakes they come out all different sizes. The pancakes are burnt on one side; also they are randomly flipped with the burnt at the top or bottom side.  There are M pancakes, such that M = X\*Y\*Z, where X, Y and Z are known. They are placed in X\*Y piles in a rectangular pan, where there are Z pancakes in each pile. This means there are X rows and Y columns of the pancake piles.

**Part 1: Burnt Pancake Problem (20%)**

The pancakes are burnt on one side, we want all the pancakes to be placed with the burnt side face down. Initially, the burnt side of a pancake could face either up or down.  Implement a solution to flip the pancakes properly to have the burnt side facing down.

**Part 2: Rearrange Interior Piles (15%)**

Run your Burnt Pancake solution for every &quot;interior&quot; pile of pancakes such that they all have the burnt side facing **down**. An &quot;interior&quot; column is defined as a pile (of size Z pancakes) with the coordinate variable x as neither zero nor X-1, and also the  coordinate variable y as neither zero, nor Y-1; with x iterating from 0 to X-1 and y from 0 to Y-1. Note that you should do the processing for (X-2)\*(Y-2) piles of pancakes.

**Part 3: Rearrange Exterior Piles (15%)**

Run your Burnt Pancake solution for every &quot;exterior&quot; pile such that they all have the burnt side facing **up**. An exterior pile is defined as a pile (of size Z pancakes) such that its x or y coordinates follow one of these values: x=0, or x=X-1, or y=0, or y=Y-1.

**Object-oriented Design (50%)**

You should design and implement the following three classes:

1) Class _Pancake_ that includes an integer variable _Size_ and a bool variable _Burnt_. Burnt =1 means the top side is burnt (and 0 mean the down side is burnt). A method _flip\_pancake()_ should be included that flips the pancake, i.e., inverts Burnt.

2) Class _PancakePile_ should be defined. It should include an array of size Z of pancake objects of type Pancake. The array can be maintained based on a pointer, or statically sized (of size Z). This class should include two methods: a) _pancake\_burnt\_down()_: have the burnt side facing down for all the pancakes in the pile; b) _pancake\_burnt\_up()_: have the burnt side facing up for all the pancakes in the pile;

3) Class _MPancakePiles_ which must include X\*Y objects of type class _PancakePile_. This class should include two methods: a) _rearrange\_interior()_; b) rearrange_\_exterior()_

**Part 4: Pancake Sorting Problem (Extra credit: 30%)**

You would like to rearrange each pile of the pancakes so that the the sizes of them are in either ascending or descending order, as explained below. The only operation you are allowed to perform is grabbing several pancakes from the top and flipping them over, repeating this (varying the number you flip) as many times as necessary.

For every &quot;interior&quot; pile of pancakes, they should be sorted **ascendingly** , meaning the largest pancake is placed at the bottom of each pile and the smallest at the top.  Also, the burnt side of each pancake should be **down**.

For every &quot;exterior&quot; pile of pancakes, they should be sorted **descendingly** , meaning the smallest pancake is placed at the bottom of each pile and the largest at the top.  Also, the burnt side of each pancake should be **up**.

**Part 5: Optional: Statistical Analysis of the Pancake Piles**

Design a Python script that performs statistical analysis of piles, in terms the variance of their sizes, various correlations between different piles, such as cross-correlation, anti-correlation, etc. Please be reminded that this parts has been changed to optional, hence no submission is required for this part.
