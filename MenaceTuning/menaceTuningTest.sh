#!/bin/sh

#********************************************************************
# Run 5 matches between Menace and Menace (test)
#./tuner.py ./Menace ./Menace -d ../ -r 2 -v


#********************************************************************
# Tune time divider test (grid search)
#./tuner.py ./Menace ./Menace -d ../ -r 7 -v -m 0 \
#		-n timeDivider --bounds 1 100 35 1
		#-n timeDivider --bounds 1,100,5,1
#********************************************************************
# Test another method
./tuner.py ./Menace ./Menace -d ../ -r 7 -v -m 2 \
		-n timeDivider --bounds 1 100 35 50
#********************************************************************
#********************************************************************
#********************************************************************
#********************************************************************
#********************************************************************
#********************************************************************