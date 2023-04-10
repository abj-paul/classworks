from pydantic import BaseModel

class Item(BaseModel):
    id : int = 2
    name: str = ""

    def __init__(self, id, name):
        self.id = id 
        self.name = name 
