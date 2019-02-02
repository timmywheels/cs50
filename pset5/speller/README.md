# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

A lung disease caused by inhaling very fine ash and sand dust.

## According to its man page, what does `getrusage` do?
// http://man7.org/linux/man-pages/man2/getrusage.2.html

`getrusage()` returns resource usage measures for `int who`, which can be either: `RUSAGE_SELF`, `RUSAGE_CHILDREN`, or `RUSAGE_THREAD`

## Per that same man page, how many members are in a variable of type `struct rusage`?

There are 16 members in `struct rusage`.

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?
Passing by reference is less memory-intensive.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.
`main` loops through the `.txt` file that's provided in the command line arg. If `file` returns `NULL` the program exits, otherwise it loops through each char in the provided file until it hits the EOF.
As it loops through the words, it checks that each char is indeed alphabetical, or if it's an apostrophe, and if so, it appends it to the `word` variable and then increments `index`. The program ignores strings that are longer than `LENGTH` which is set to `45`.
The program also ignores words that contain numbers, resets `index` to `0`, then skips to the next word. From there, if these checks are ignored, we can assume the program found a while word so we will append the null temrinator and update the word counter.
Next we will check the spelling of the word using `getrusage`. If the word is misspelled, it increments `misspellings` by one, then resets `index` to `0`.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?
Using `fscanf` is not as precise when needing to check char by char. `fscanf` also ignores whitespace which isn't particularly helpful for this problem set where we need to note the start of a new word.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?
Being that `check` and `load` accept pointers it's important not to be changing the values for these in this instance as we just need them to read the arguments.
