The PARSER allows you to parse different files. 

For thoses files to be parsed, they must respect batchmake language and include each other.
For example, the file file1.txt can contain :

#code file1
#code file1
include( file2.txt )
#code file1
#code file1

The parser will go look for file2.txt and include it at that place. you'll have :

#code file1
#code file1

#code file2
#code file2

#code file1
#code file1

The others files can be in others directories as long as the path you give is correct. You can also give absolute path.
The output file will have some commentaries to help you find where the different parts are. 
Have fun!

Any questions, donations for me not being a genius : marion.hoogstoel@gmail.com
