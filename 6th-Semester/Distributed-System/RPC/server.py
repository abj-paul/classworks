import xmlrpc.server

class MyServer:
    def square(self, x):
        return x * x

    def cube(self, x):
        return x * x * x

server = xmlrpc.server.SimpleXMLRPCServer(("localhost", 8000))
server.register_instance(MyServer())
server.serve_forever()
