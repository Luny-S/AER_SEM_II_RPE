# use docker image for ros kinetic with most needed features
FROM ros:kinetic-ros-base

# install needed packages: the orocos and some text editors
RUN apt-get update && apt-get install -y \
    ros-kinetic-rtt-ros-integration \
	ros-kinetic-rqt \
	ros-kinetic-rqt-common-plugins \
    nano vim emacs \
    tree \
	&& rm -rf /var/lib/apt/lists/ \

# make bash automatically source our custom bashrc that we will put
# inside our volume
RUN echo '\n\n[[ -f /workspace/bashrc ]] && source /workspace/bashrc' >> $HOME/.bashrc  
