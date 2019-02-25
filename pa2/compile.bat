antlr4 pa2.g4
pause
javac -cp "antlr-4.7.1-complete.jar" *.java
pause
java -cp . main < commands.txt > output.txt
