#!/bin/bash
#
# based on example from laboratories ros_docker script with a docker command:
# docker run --net=host -ti --rm -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix -v /mnt/student/ros_workspace/home/student:/home/student ros_orocos/ubuntu:12.04
#
#
#	Original author: Jędrzej Boczar (2018/2019)(Steps 0 - 6)
################################################################################
#
# INSTRUCTIONS:
#
# (HERE - refers to the direcotry in which this script exists)
#
# 0. Install docker. This depends on the system, try googling: docker install <YOUR_SYSTEM>
#
# 1. Build the docker image defined in Dockerfile:
#       docker build --tag rpe-gui .
#
# (2.) This has created a docker image called "orocos-ros-kinetic", to see it, use:
#        docker images
#
# 3. Use this script to start the docker container as follows:
#        ./run-docker-image.sh
#
# 4. This script maps directory HERE/docker-workspace to /workspace inside container.
#    Now we need to create the whole catkin workspace (while being inside docker!), e.g.:
#        mkdir -p /workspace/ros_ws/src/
#        cd /workspace/ros_ws/
#        catkin_make
#
# (5.) Now it is good to add something to bashrc so that we will always source
#    the file devel/setup.bash. The Dockerfile added a line to .bashrc inside
#    the container that will source file /workspace/bashrc if it exists.
#    As /workspace is mapped to HERE/docker-workspace/ on our machine, we can add
#    a file HERE/docker-workspace/bashrc with a line:
#        [[ -f /workspace/ros_ws/devel/setup/bash ]] && source /workspace/ros_ws/devel/setup/bash
#    We can also add other commands/aliases in that bashrc file, as it will
#    persist after exiting docker container.
#
# 6. Now do the task:
#    http://galatea.ict.pwr.wroc.pl/index.php/teaching/12-rpe/7-robotic-programming-environments-lab4
#
################################################################################
#	(Modification of the script prepared by Jędrzej Boczar in academic year 2018/2019)
#	(Author: Aleksander Sil)
#
#	(7.) Add GUI
#		In this version of the script we run the image with the display capabilities.
#		You need to check your Docker adapter IP (in my case it says Ethernet adapter vEthernet (DockerNAT)
#		after running ipconfig. Then you put the IP after -e DISPLAY in docker-run command
#		at the bottom of this script.
#		
#		If you are using WSL to run this image then you should first follow this guide:
#		https://www.makeuseof.com/tag/linux-desktop-windows-subsystem/
#
#
################################################################################
#	Comments on some issues:
#	1. 	You might encounter permissions issues while running this docker image on Windows.
#		Possible fix is to use WSL (Windows Subsystem for Linux) to work with this Docker image.
#		https://nickjanetakis.com/blog/setting-up-docker-for-windows-and-wsl-to-work-flawlessly
#
#	2.	Typegen is not working - it won't. Typegen requires older version of system/linux/ros/whatever.
#		Try to copy your project to computer in the lab and then do the part about typegen.
#		You may also try to modify the dockerfile and use previous version of Ubuntu. You might try
#		to do this based on the original command from Dockerfile on the lab computers provided at
#		the beginning of this script.
#		
################################################################################

# get this directory's full path
HERE="$(dirname "$(realpath ${BASH_SOURCE[0]})")"
echo "$HERE"

# create the directory that will be mapped into docker image
docker_ws="$HERE/docker-workspace"
mkdir -p "$docker_ws"

# run the container that has previously been built from the Dockerfile
#   e.g. with a command:
#       docker build --tag orocos-ros-kinetic:v1 .
# run it in interactive mode, remove everything after exiting, but create a volume
# mapping to local directory

docker run \
    --net=host \
    --tty \
    --interactive \
    --rm \
    --volume "$docker_ws:/workspace" \
	-ti \
	-e DISPLAY=10.0.75.1:0.0 \
    rpe-gui
	
	
	
	
