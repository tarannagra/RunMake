# RunMake

The only reason to use this is if you are lazy enough to write the same command in each folder where a `Makefile` is.

## Compiling source

```bash
g++ main.cpp -o main.exe
```

## Running

```bash
./main.exe
```

## Why make this?

I wanted to make a program that will recursively search each folder for a Makefile and run it. C++ is fast(er) than Python so it's only fitting. I really didn't want to have to `cd` in to each folder, run `make build` then `cd` out for each of the folders, so a program was created.

## Credits

Made by [Taran Nagra](https://github.com/tarannagra)
