import datetime

def log(message):
    with open("log.txt", "a") as logfile:
        logfile.write(f"{datetime.datetime.now()} - {message}\n")

