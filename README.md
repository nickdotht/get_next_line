# get_next_line - jrameau @42Born2Code

A C function that reads any valid file line by line until the end.

### TOC
* [What is get_next_line?](#what-is-get_next_line)
* [Why would I use/try it?](#why-would-i-use-try-it)
* [How do I use it?](#how-do-i-use-it)
* [How do I try it out?](#how-do-i-try-it-out)
	* [How do I test my own code?](#how-do-i-test-my-own-code)

### What is get_next_line?

[get_next_line][1] is an individual project at [42][2] that basically reads a file line by line.

Disclaimer: *There [are][10] [so][11] [many][12] [easier][13] methods of doing this by using standard functions in C. But the goal here is to be able to do it by using any functions from my [libft][14] and only the standard functions `read`, `malloc` and `free`.*

### Why would I use/try it?

You probably will never have to use this funciton if you are not a 42 student. The goal is to get better at C. As I said above, you can only use those three standard library functions:

* read
* malloc
* free

So it makes the project harder. But you can also use functions from your [personal library][14].

After finishing this project, you'll definitely learn some more about static variables, pointers, arrays, linked lists (if you decide to do the bonus part), dynamic memory allocation and file manipulation.

My code is not the best, but it passed all the 42 tests successfully.

### How do I use it?

I added a main file called **main.c**, it takes a file name as an argument, opens it and passes the file descriptor (fd) to get_next_line until get_next_line returns -1 or 0.

**Note:** get_next_line returns -1, 0, 1 depending on wether an error has occurred, the reading has been completed or a line has been read respectively.

Alright, so first of all, download/clone this repo:

	git clone https://github.com/r4meau/get_next_line
	
Get into it and build the library:
	
	cd get_next_line
	make -C libft/

Build the executable:
	
	gcc -Wall -Wextra -Werror -I./libft/includes -L./libft -lft -o gnl get_next_line.c main.c

-I tells the compiler where your header files are. `./libft/includes` in this case

-L tells it where your library resides. `./libft` here

-l takes the name of your library. This is the set of characters that come after `lib` in your library name.

**NOTE:** -L and -l might look a little bit too much, you could replace those flags with `libft/libft.a` if you want.

Alright, the last command created a `gnl` executable in your directory. Now test it with:

	./gnl m83.txt
	
**NOTE:** The lyrics in the text file are from [Claudia Lewis][15] by [M83][16] ;)

### How do I try it out?

If you are a beginner to intermediate programmer and want to hone your skills in C, I highly recommend you to give this project a try.

To do that, you just have to read the [project instructions][1], some stuffs on there might be confusing if you are not a 42 student, but don't mind them. Just make sure you use only `read`, `malloc`, `free` as your only available standard library functions and my/your [libft][14] functions.

The instructions are clear enough, so I won't add anything else. If you have any questions, feel free to [ask me][8].

#### How do I test my own code?

You can do as [above](#how-do-i-use-it) and use the main file I added, just make sure you use your own `get_next_line.c` file. This is a pretty rudimentary test, if you want to try some deep tests, let me introduce you to the amazing [42FileChecker][17] by [@jgigault][18].

Assuming you read the project instructions and coded your own get_next_line
		
1. Go back to the root directory and download @jgigault's 42FileChecker:

		cd ..
		git clone https://github.com/jgigault/42FileChecker
		
2. Go into the test folder and run the test:

		cd 42FileChecker
		sh 42FileChecker.sh

At the time of writing, @jgigault is looking for a maintainer for 42FC, so he displays a message on startup, dismiss it with `1` or contact him if you think you can help.

Then press `5` to select tests for get_next_line, press `1` to install [moulitest][5] as an external repo, then `1` to configure the tests, now you handle the path to your get_next_line and then choose which test to run on your project.

That's it! If you're having some problems, just [send me a tweet][8]. If you think your problem is due to my code or this README, [create a new issue][9]. I'll definitely check it out.

Enjoy.

[1]: https://github.com/R4meau/get_next_line/blob/master/get_next_line.en.pdf "get_next_line PDF"
[2]: http://42.us.org "42 USA"
[5]: https://github.com/yyang42/moulitest
[8]: https://twitter.com/r4meau
[9]: https://github.com/R4meau/get_next_line/issues
[10]: http://stackoverflow.com/questions/3501338/c-read-file-line-by-line
[11]: http://stackoverflow.com/questions/2372813/reading-one-line-at-a-time-in-c
[12]: http://stackoverflow.com/questions/9206091/going-through-a-text-file-line-by-line-in-c
[13]: https://linux.die.net/man/3/getline
[14]: https://github.com/R4meau/libft
[15]: https://www.youtube.com/watch?v=ZdGLsMfJMy0
[16]: http://ilovem83.com/
[17]: https://github.com/jgigault/42FileChecker
[18]: https://github.com/jgigault