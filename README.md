# LongDocumentClassifier
Bonus Project for CSC 3320 with Professor Long

To build all project files, run build.sh in bin

To run the program:

- First, see if "analyzeText", "generateWeights", and "wordFrequency" are in bin
	+ If not, run "build.sh"

- Next, we must generate weight vectors for each category. To do this, run 
"analyzeControlGroup.sh".
	+ A file named "weights.txt" will be created

- Finally, enter the command:
```
	./analyzeText weights.txt filename
```
	+ "filename" is the file to be analyzed.
	+ "weights.txt" can be changed to accept other weight files.

