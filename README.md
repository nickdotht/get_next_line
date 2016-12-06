# get_next_line - jrameau @42Born2Code

A C function that reads any valid file line by line until the end.

### TOC
* [What is get_next_line?](#what-is-get_next_line)
* [Why would I use/try it?](#why-would-i-use-try-it)
* [How do I use it?](#how-do-i-use-it)
* [How do I test it? How do I test my own implementation?](#how-do-i-test-it-how-do-i-test-my-own-implementation)
	1. [To test the code in this repo](#1-to-test-the-code-in-this-repo)
	2. [To test your own code](#2-to-test-your-own-code)

### What is get_next_line?

[get_next_line][1] is an individual project at [42][2] that basically reads a file line by line.

Disclaimer: *There [are][10] [so][11] [many][12] [easier][13] methods of doing this by using standard functions in C. But the goal here is to be able to do it by only using any functions from my [libft][14] and the standard functions `read`, `malloc` and `free`.*

### Why would I use/try it?

As I said above, you can only use those three standard library functions:

* read
* malloc
* free

So it makes the project harder. But you can also use functions from your [personal library][14].

After finishing this project, you'll definitely learn some more about static variables, pointers, arrays, linked lists (if you decide to do the bonus part), dynamic memory allocation and file manipulation.

My code is not the best, but it passed all the 42 tests successfully.

### How do I use it?

I added a main file called **main.c**, it takes a file name as an argument, opens it and passes the file descriptor (fd) to get_next_line until get_next_line returns something other than 1.

**Note:** get_next_line returns -1, 0, 1 depending on wether an error has occurred, the reading has been completed or a line has been read respectively.

Alright, so first of all, download/clone this repo

To test the function, you'll need [libft][14], so download/clone it and build the library

		`gg -Ilibft/includes libft/libft.a get_next_line.c main.c`

-L takes the path to your library. `.` in this case<br>
-l takes the name of your library. This is the set of characters that come after `lib` in your library name.

That's it. Now run it using `./a.out`

### How do I try it out?

To test the code we're going to be using @alelievr's [Libft Unit Test][4]. There are [some][5] [good][6] [others][7] but I'll only be covering this one.

#### 1. To test the code in this repo

1. Clone this repo and cd into it, make sure it's called `libft`:

		git clone https://github.com/R4meau/libft
		cd libft/
2. Copy all the source files to the root directory:

		make copy
3. Run Make so you can build the library:

		make
4. Go back to the root directory and download @alelievr's Libft Unit Test:

		cd ..
		git clone https://github.com/alelievr/libft-unit-test
5. Go into the test folder and run the test:

		cd libft-unit-test/
		make f

If you did everything correctly you should get a cool list of tests showing you the function name and if it passed for each test.

#### 2. To test your own code

You might want to have a go at this project too. If you never heard of Makefiles, don't worry, you don't have to learn about it now. So go ahead and follow those steps:

1. Create a directory for your project, make sure you call it `libft`:

		mkdir libft
2. Clone this repo (don't name it libft) and copy the Makefile-sample as Makefile and libft.h to your own project:

		git clone https://github.com/R4meau/libft r4-libft
		cp r4-libft/Makefile-sample libft/Makefile
		cp r4-libft/libft.h libft/
3. Go to your project, [read the instructions][1] for the function you want to create, code it and uncomment it from the Makefile:

		cd libft
		vim ft_memset.c
		vim Makefile

	As an example, after creating ft_memset as your first function, you go into the Makefile, remove the `#` in front of `FILES`, remove the `\` at the end of `ft_memset` and add a `#` in front of `ft_bzero`.

	If it still looks complicated, **DON'T PANIC**, [just ask me][8] :)
4. Run Make so you can build the library:

		make
5. Go back to the root directory and download @alelievr's Libft Unit Test:

		cd ..
		git clone https://github.com/alelievr/libft-unit-test
6. Go into the test folder and run the test:

		cd libft-unit-test/
		make f

That's it! If you're having some problems, just [send me a tweet][8]. If you think your problem is due to my code or this README, [create a new issue][9]. I'll definitely check it out.

Enjoy.

[1]: https://github.com/R4meau/get_next_line/blob/master/get_next_line.en.pdf "get_next_line PDF"
[2]: http://42.us.org "42 USA"
[3]: http://www.asciitable.com/ "The ASCII Table"
[4]: https://github.com/alelievr/libft-unit-test
[5]: https://github.com/yyang42/moulitest
[6]: https://github.com/QuentinPerez/Maintest/tree/master/libft
[7]: https://github.com/Kant1-0/libft-test
[8]: https://twitter.com/r4meau
[9]: https://github.com/R4meau/libft/issues
[10]: http://stackoverflow.com/questions/3501338/c-read-file-line-by-line
[11]: http://stackoverflow.com/questions/2372813/reading-one-line-at-a-time-in-c
[12]: http://stackoverflow.com/questions/9206091/going-through-a-text-file-line-by-line-in-c
[13]: https://linux.die.net/man/3/getline
[14]: https://github.com/R4meau/libft
