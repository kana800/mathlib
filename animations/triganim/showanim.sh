#!/bin/bash



if [[ $1 == 'gif' ]]; then
	manim -pql --format=gif coscompare.py GraphScene
fi
#manim -pql coscompare.py GraphScene

#celluloid media/videos/coscompare/480p15/GraphScene.mp4
