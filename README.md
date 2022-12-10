# lolbison

A LOLCODE interpreter written in C++ using Flex and Bison

## Building & running lolbison

```
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./lolbison {{path/to/file.lol}}
```

## Implemented functionality

- Types: NUMBR (int), YARN (string), TROOF (bool) and NOOB (nil)
- Binary math operators
- Boolean operators
- VISIBLE (print to stdout)
- if-then-else statement (without MEBBE)
- Loops
- Arrays (reduced functionality)
- ENUF (as break in a loop, as exit outside loops)

## The difference from [lolcode specification v1.2](https://github.com/justinmeza/lolcode-spec/blob/master/v1.2/lolcode-spec-v1.2.md)

- There is only one variable scope
- A variable can be declared multiple times. Just like a function in C++
- Arrays work like dictionaries with integer keys

The grammar is described here: [reference/grammar.txt](reference/grammar.txt)
