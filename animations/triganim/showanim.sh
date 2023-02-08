#!/bin/bash


if [[ $1 == 'gif' ]]; then
	manim -pql --format=gif triganim.py CosGraphScene
	manim -pql --format=gif triganim.py SinGraphScene
else
	manim -pql triganim.py GraphScene
fi

#celluloid media/videos/coscompare/480p15/GraphScene.mp4
