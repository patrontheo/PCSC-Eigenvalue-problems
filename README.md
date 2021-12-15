# PCSC-Eigenvalue-problems
Project for the Programming concept in Scientific Computing course




## Usage

* `--method` to specify the method used to find eigenvalues: power, inversepower, or qr.  
Default: power
* `--filename` to specify the name of the file in 'data/' used as input matrix.
Default: mat.csv
* `--shift` to specify a shift used in inverse power method.  
Default: 0
* `--error` to specify the error criterion used to stop the algorithm.  
Default: 0.0001





# Bouldering problems analyzer

This project aims at identifying the holds of climbers in bouldering problems with just video input.
It was originally written for Google Colab, with direct GDrive integration.

## Prerequisites

* `ffmpeg`
* `python` =~3.8
* `mediapipe`
* `numpy`
* `scikit-learn`

## File structure

The file structure to follow for the project to work out of the box is the following :
```
pyboulder
│   boulder_problems.xlsx
|   move_sequence.py
|   pose_estimation.py    
│   README.md
|   run.py    
|   utils.py    
│
└───preprocessing
│   │   cropping.py
│   │   screengrab.py
│   │   stabilization.py
│   
└───videos
    |
    |
    └───boulder_1_01
    |   |   [vid_file]
    |   |   [vid_file]
    |   |   ...
    |
    └───boulder_1_02
    |   |   [vid_file]
    |   |   [vid_file]
    |   |   ...
    |
    └───...
```

## What it does

### Preprocessing

* Stabilization is done using FFMPEG in conjunction with vidstab, we first compute the transformation of the camera with the following command :
`ffmpeg -hide_banner -loglevel error -i f'{[vid_file]}' -vf f'vidstabdetect=result={[vid_file]}.trf' -f null -`. Afterwards we can stabilize the video with : `ffmpeg -hide_banner -loglevel error -i f'{[vid_file]}' -vf f'vidstabtransform=input={[vid_file]}.trf:smoothing=0' f'{[vid_file]}_STAB.MOV'`

* Cropping, we have to define the time interval we want to keep for each video in the excel sheet.

* Screenshots, these will help us with the visualization later on. The time to take the screenshot can be defined in the excel sheet, otherwise it will be the last frame of the video.

### Pose estimation

We used mediapipe for pose estimation as it work well and ran pretty fast during our testing.

### Move sequence

For the computing the move sequence, we first check which extremity has not moved for more than a certain threshold during a short period of time, this allows us to roughly determine the coordinates of the holds. After that we run a clustering algorithm on this point cloud in order to get the centroids and to get a better idea of the holds' locations.

## Usage

* `--path` the path of the excel sheet.
* `--no_prep` skips all the preprocessing steps (stabilization, cropping and screengrabing).
* `--stab` to stabilize all the unstabilized videos.
* `--crop` to crop the time of the videos (according to the numbers in the excel sheet).
* `--screen` to generate the screenshot for each of the videos.
* `--pose` to estimate the pose using mediapipe and generate json files containing the keypoints coordinates.
* `--output_video` to output the videos with the pose estimation.
* `--move` to generate the move sequence using the json files of the pose estimation.
* `--normal_screens` to grab screenshots on the non mediapipe videos, defaults to False.
* `--redo_screens` to rerun the screengrabing on all videos.
* `--redo_moves` to rerun the move sequence computations.

## Output

After running everything, for each video we will end up having :

* `[vid_file]`
* `[vid_file].trf`
* `[vid_file]_STAB.MOV`
* `[vid_file]_STAB.MOV_SCREEN.jpg`
* `[vid_file]_STAB.MOV_POSE.json` 
* `[vid_file]_STAB.MOV_POSE.mp4` 
* `[vid_file]_STAB.MOV_MOVE_SEQ.jpg`

## Example command 

The command `python3 run.py --stab --crop --screen --pose --move` gives the following results :

![Example result](docs/res.jpg)