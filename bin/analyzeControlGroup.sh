#!/bin/bash
# This file runs wordFrequency on the contents of each of the categories in controlgroup/
# It will create a file "weights.txt" that contains the weight vectors used in analyzeText
rm -f output.txt
for file in ../controlGroup/moneyArticles/*
do
	./wordFrequency "$file"
done
mv output.txt moneyFrequency.txt

for file in ../controlGroup/politicsArticles/*
do
	./wordFrequency "$file"
done
mv output.txt politicsFrequency.txt

for file in ../controlGroup/sportsArticles/*
do
	./wordFrequency "$file"
done
mv output.txt sportsFrequency.txt

./generateWeights moneyFrequency.txt politicsFrequency.txt sportsFrequency.txt

rm moneyFrequency.txt politicsFrequency.txt sportsFrequency.txt


