# polyverse-polyscripting-learning

## What is polyscripting?

Polyscripting is a method of blocking code injection attacks in a super clever way, developed at [Polyverse Corporation](polyverse.com/). I have explained it in my own words below, but visit their [site](https://polyverse.com/blog/introducing-polyscripting-the-beginning-of-the-end-of-code-injection-fe0c99d6f199/) to learn more.

A programming language is essentially a collection of tokens that follow a set of strict grammar rules. Code injections work by getting malicious code onto a server, and then using the interpreter on the infected server to run the malicious code. The hackers take advantage of the fact that there is a fully functioning interpreter on the server that can run their own code.

Polyscripting thwarts this type of attack by taking each keyword in a language, and replacing it with a randomized string. 
This is normal Python:
```
for i in range(10):
    print('Hello World!')
```
This would be polyscripted Python:
```
OIHfdsdfoihs i SsSDFidf JIsdSDSf(10):
    MtyKjDgFJ('Hello World!')
```

So polyscripting results in a brand new language, and a brand new compiler, that will not parse any actual Python keywords. And the process of setting keywords to randomized strings can be done over and over and over again, for every individual case where a Python interpreter is needed. Such a simple idea, but powerful enough to effectively stop all code injections.

## What I am trying to do

I learn best by building things, so in an effort to try and understand how polyscripting would work (and how it might not work), I decided to write a Python script that will:

1. Take a python file as input
2. Split the file based on any non-keyword strings (colons, parentheses, quoted strings, etc.)
3. Create a map of keywords to randomized strings
4. Output the python file in the new, randomized language
5. Create a bash script that contains the keyword map so that the script can take the new python file as input and run it.

My approach does have a major security flaw, since the interpreter contains the mapping and could be used to undo the randomization I did. But I will try to see how I can avoid this in the next iteration of the project.
