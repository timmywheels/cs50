# Questions

## What's `stdint.h`?
stdint.h is a header file in the C standard library introduced in the C99 standard library
section 7.18 to allow programmers to write more portable code by providing a set of typedefs
that specify exact-width integer types, together with the defined minimum and maximum allowable
values for each type, using macros.

[Source](https://en.wikibooks.org/wiki/C_Programming/stdint.h)

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?
It helps clarify exactly how you intend to use an integer and what it's exact-width is.

[Source](https://en.wikibooks.org/wiki/C_Programming/stdint.h)

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

        `BYTE` = 1 byte
        `DWORD` = 4 bytes / 32 bits
        `LONG` = 4 bytes / 32 bits
        `WORD` = 2 bytes / 16 bits

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."
The first 2 bytes of the BMP file format are the character "B" then the character "M" in ASCII encoding.

[Source](https://en.wikipedia.org/wiki/BMP_file_format)

## What's the difference between `bfSize` and `biSize`?

biSize = The number of bytes required by the structure
bfSize = The size, in bytes, of the bitmap file

[Source](https://stackoverflow.com/questions/25713117/what-is-the-difference-between-bisizeimage-bisize-and-bfsize)

## What does it mean if `biHeight` is negative?
If biHeight is negative, the bitmap is a top-down DIB with the origin at the upper left corner.

[Source](https://docs.microsoft.com/en-us/windows/desktop/api/wingdi/ns-wingdi-tagbitmapinfoheader)

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?
The number of bits-per-pixel. The biBitCount member of the BITMAPINFOHEADER structure determines
the number of bits that define each pixel and the maximum number of colors in the bitmap.

[Source](https://msdn.microsoft.com/en-us/library/windows/desktop/dd183376(v=vs.85).aspx)

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?
fopen on these lines could return null if the specified input/output file doesn't exist

## Why is the third argument to `fread` always `1` in our code?
Because that arg defines how many elements to read, and we only need to read 1 struct

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?
Padding would be 3

## What does `fseek` do?
fseek moves the file pointer position to the given location.

[Source](https://fresh2refresh.com/c-programming/c-file-handling/fseek-seek_set-seek_cur-seek_end-functions-c/)

## What is `SEEK_CUR`?

SEEK_CUR moves the file pointer position to given location.

[Source](https://fresh2refresh.com/c-programming/c-file-handling/fseek-seek_set-seek_cur-seek_end-functions-c/)

## Whodunit?
It was Profesor Plum with the candlestick!