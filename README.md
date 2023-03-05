<h1 align="center">
	📖 Push_Swap
</h1>

<p align="center">
	<b><i>Sort data on a stack</i></b><br>
</p>

<p align="center">
    <a href="https://www.cprogramming.com/"><img alt="Made with C" src="https://img.shields.io/badge/Made%20with-C-1f425f.svg"/></a>
    <img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/iflis7/get_next_line?color=lightblue" />
    <img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/iflis7/get_next_line?color=critical" />
    <img alt="Code language count" src="https://img.shields.io/github/languages/count/iflis7/get_next_line?color=yellow" />
    <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/iflis7/get_next_line?color=blue" />
    <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/iflis7/get_next_line?color=green" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for an
optimized data sorting. `Version: 6`.<br>
You can read the subject: [`push_swap.pdf`](subject/push_swap.pdf)


### Discription of mandatory part
## Challenge

Sort a random list of integers using the smallest number of moves, 2 stacks
and a limited set of operations. <br />
<br />

You start with two empty stacks: **a** and **b**. You are given a random list of integers via command line arguments.
<br />
<br />

Only these moves are allowed:
- `sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- `sb` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- `ss` : `sa` and `sb` at the same time.
- `pa` : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
- `pb` : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
- `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
- `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.
<br />

At the end, **stack b** must empty empty and all integers must be in **stack a**, sorted in ascending order. <br />
<br />


## The Project
Create two programs: ```checker``` and ```push_swap```. <br />

The ```checker``` program reads a random list of integers from the stdin, stores them, and checks to see
if they are sorted. <br />
<br />
The ```push_swap``` program calculates the moves to sort the integers – *pushing, popping, swapping* and *rotating* 
them between **stack a** and **stack b** – and displays those directions on the stdout. <br />
<br />
You can pipe ```push_swap``` into ```checker```, and ```checker``` will verify that ```push_swap```'s instructions were successful. 
<br />

Both programs must mandatorily parse input for errors, including empty strings, no parameters, 
non-numeric parameters, duplicates, and invalid/non-existent instructions.

**Push_Swap** must conform to the [42 Norm](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf). <br />
Using normal ```libc``` functions is strictly forbidden. Students are however, allowed to use: ```write```, ```read```, ```malloc```, ```free```, ```exit```. 
It must not have any memory leaks. Errors must be handled carefully. <br />
In no way can it quit in an unexpected manner (segmentation fault, bus error, double free, etc).

All errors like: wrong commands,  permission to files and etc, need be handle.
### Testers
[Tester](https://github.com/LeoFu9487/push_swap_tester)

[![hsaadi's 42 push_swap Score](https://badge42.vercel.app/api/v2/cl5s2p211013909jutf782quk/project/2593964)](https://github.com/JaeSeoKim/badge42)
