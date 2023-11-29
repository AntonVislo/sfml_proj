FROM ubuntu:22.04

RUN apt update
RUN apt install git  build-essential libsfml-dev -y

RUN useradd -ms /bin/bash -p user user
RUN adduser user sudo
RUN echo user:user | chpasswd

USER user
WORKDIR /home/user

RUN git config --global credential.helper store
RUN mkdir ~/workspace
RUN cd ~/workspace
