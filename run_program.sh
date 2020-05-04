#!/bin/bash

filename=$1
extension="${filename##*.}"
fileName="${filename%.*}"
baseDir="EPIJudge"

cd "${baseDir}"

if [ "$extension" == "cc" ]; then
	judgePath="epi_judge_cpp"
	cd "${judgePath}"
	filePath="${baseDir}/${judgePath}/${fileName}"
	make "${fileName}"
	cd ../../
	read -p 'Do you want to save the solution ' choice
	if [ "$choice" -eq 1 ]; then
		moveFileName="${fileName}.mine.${extension}"
		solPath="${judgePath}_solutions"
		moveFilePath="${baseDir}/${solPath}/${moveFileName}"
		echo "${filePath}.cc \n ${moveFilePath}"
		cp ${filePath}.cc ${moveFilePath}
	fi	

fi
