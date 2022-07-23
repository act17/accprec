# accprec
Accuracy/Precision Calculator + Example Program
# Description
  This program's purpose is to calculate the accuracy and precision of an array given, assuming the array corresponds to values on a two-dimensional plane. It includes two example functions, one in the file that contains the calculating functions of ``accuracy()`` and ``precision()`` that is entirely command-line based, and one in ``test.c`` that provides a 7-unit by 14-unit square which one can make use of to select 10 spaces which are put into the functions with their results returned onto the interface.
# Accuracy Algorithim
  The algorithim for accuracy is all sorts of FUBAR'd, at the moment. It uses triangulation and the Pythagorean thereom to determine the distance between all points and the point considered to be the one that is 100% accurate. Then, it subtracts 100 by this average and divides it by 100, returning the result. It's ridiculous, makes no sense, and overall is something that definitely needs work. But I'm too lazy and proud of my current work to do that at the moment.
# Precision Algorithim
  The algorithim for precision, however, is quite well-formed as far as I'm aware. As the maximum possible distance covered between two points is passed into the function, the program simply averages the distance between two points and divides that by the maximum distance. Then 1 is subtracted by this number, showing the overall precision of the array.
# Changelog
**Version 1.0** (July 23rd, 2022)
  - Initial commit.
