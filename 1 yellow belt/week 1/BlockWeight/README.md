# Desctiption

Calculate the total mass of blocks having the shape of a rectangular parallelepiped of the same density, but of different sizes.  

## Note
Consider that the dimensions of the blocks are measured in centimeters, the density is in grams per cubic centimeter, and the final mass is in grams. Thus, the mass of the block can be calculated as a simple product of density by volume.  

## Input format
In the first line, two positive integers are entered: the number of blocks N and the density of each block R. Each of the following N lines contains three positive integers W, H, D — the dimensions of the next block.

It is guaranteed that:

 - the number of blocks N does not exceed 10^5;

 - the density of R blocks does not exceed 100;

 - the sizes of blocks W, H, D do not exceed 10^4.

# Example
|input|output|
|-|-|
|2 14|840084|
|1 2 3||
|30 40 50||