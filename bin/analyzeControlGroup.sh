#!/bin/bash
# This file runs wordFrequency on the contents of each of the categories in controlgroup/
# It will create an individual file with word totals for each category.
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
