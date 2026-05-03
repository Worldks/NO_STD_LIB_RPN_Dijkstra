# Overview  
Evaluates the arithmetic expression represented by the line read from standard input and prints the result.
It uses Polish infix notation (POLIS) and Dijkstra's algorithm, which can be used to convert any expression written in traditional infix notation to POLIS.

The program does not use the C standard library.

The program will only compile on Unix on an x86-compatible platform.  

Вычисляет арифметическое выражение, представленное в прочитанной строке из потока стандартного ввода, и печатает полученный результат. 
Используется польская инверсная запись(ПОЛИЗ), а также алгоритм Дейкстры, с помощью которого можно перевести в ПОЛИЗ произвольное выражение, записанное в традиционной инфиксной нотации.  
Программа не использует стандартную библиотеку языка Си.  
Программа скомпилируется только под Unix на x86 совместимой платформе.  
Также необходимо установить nasm  
>sudo apt install nasm  

#  Build  
В директории build  
>make prog  
>./prog

# Usage  
Enter an arithmetic expression (can consist of integers written in decimal notation, as well as symbols for the four arithmetic operations and parentheses)  

Ввести арифметическое выражение (может состоять из целых чисел, записанных в десятичной системе,
а также символов четырёх действий арифметики и круглых скобок)
