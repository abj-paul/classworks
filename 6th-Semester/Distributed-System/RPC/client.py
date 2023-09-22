import xmlrpc.client

server = xmlrpc.client.ServerProxy("http://localhost:8000")
result = server.square(5)
print("The square of 5 is:", result)
result = server
