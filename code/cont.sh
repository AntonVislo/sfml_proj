# /bin/bash

sudo docker build -t sfml_image .
sudo sudo docker run -it -v /home/user/workspace/dck/sfml/code/:/home/user/code --name sfml -e DISPLAY=unix$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix sfml_image
