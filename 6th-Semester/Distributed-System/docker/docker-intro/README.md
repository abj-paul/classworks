# Docker intro

This is an example repository to run docker containers. 

## Run a container with docker CLI

1. `cd server`
1. `docker build . -t hello`
1. `docker run -p 5000:5000 hello` [Map port 5000 of localhost to port 5000 of container]

Then go to [localhost:5000](https://localhost:5000)

## Run containers with docker-compose

In the project root:

1. `docker-compose build`
1. `docker-compose up`