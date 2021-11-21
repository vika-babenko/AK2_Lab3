<h1 align="center">Laboratory work #3</h1>

Simple program for simple list manipulation.

## Usage:

### --help (-h)

Simply showing the manual for the program.

#### Arguments

*Option has no arguments.*

#### Example

- ./simple_program --help

### --version" (-v)

Simply showing program version.

#### Arguments

*Option has no arguments.*

#### Example

- ./simple_program --version

### --create (-i)

Simply creation of a list of numbers.

#### Arguments

- **$1** (list<number>): The input list.

#### Example

- ./simple_program -i1,2,3
- ./simple_program -create=1,2,3

### --sum (-s)

Simply summing the first *n* members in the list (all if *n* is not specified).

#### Arguments

- **$1** (int): n (optional).

#### Example

- ./simple_program --create=1,2,3 --sum
- ./simple_program --create=1,2,3 -s2

### --count (-c)

Simply counting the number of members in the list.

#### Arguments

*Option has no arguments.*

#### Example

- ./simple_program -i1,2,3 -c

### --reverse (-r)

Simply reversing order of all members in the list.

#### Arguments

*Option has no arguments.*

#### Example

- ./simple_program -i1,2,3 -r