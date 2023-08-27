# Include a python environment (alpine environments are small)
FROM python:3.8-alpine

# Copy the current directory at host to /app of container
COPY . /app

# Set the working directory to /app
WORKDIR app

# Install the python dependencies
RUN pip3 install -r requirements.txt

# Command for running python app
CMD [ "python", "index.py"]